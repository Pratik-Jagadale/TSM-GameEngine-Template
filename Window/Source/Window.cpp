#include "Window.h"
#include <TSM.h>
#ifdef TSM_PLATFORM_WINDOWS

// GLOBAL MACROS
#define WINWIDTH 800
#define WINHEIGHT 600

// GLOBAL WINDOW RELATED VARIBLE DECLARATIONS
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
BOOL gbFullScreen = FALSE;
BOOL gbActiveWindow = FALSE;

// CALL BACK FUNCTION DECLARTIONS
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// ENTRY POINT FUNCTION
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// LOCAL FUNCTION DECLARTIONS
	void uninitializeWindow(void);

	// LOCAL VARIABLE DECLARTIONS
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("TheShowMan");
	BOOL bDone = FALSE;
	int iRetVal = 0;
	int iHeightOfWindow, iWidthOfWindow;

	// CODE
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// REGISTER ABOVE WNDCLASS
	RegisterClassEx(&wndclass);

	iHeightOfWindow = GetSystemMetrics(SM_CYSCREEN); // Height of Window Screen
	iWidthOfWindow = GetSystemMetrics(SM_CXSCREEN);	 // Width Of Window Screen

	// INITIALIZE TSM APPLICATION AND LOG 
	auto oglmain = TSM::CreateApplication();

	// CREATE WINDOW
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName,
		TEXT("TheShowMan"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		(iWidthOfWindow - WINWIDTH) / 2,
		(iHeightOfWindow - WINHEIGHT) / 2,
		WINWIDTH,
		WINHEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ghwnd = hwnd;

	// INITIALIZING GLEW AND OPENGL
	iRetVal = oglmain->initialize();

	if (iRetVal == -1)
	{
		TSM_ERROR("Choose Pixel format Failed...\n");
		oglmain->uninitialize();
		uninitializeWindow();
	}
	else if (iRetVal == -2)
	{
		TSM_ERROR("Set Pixel format Failed...\n");
		oglmain->uninitialize();
		uninitializeWindow();
	}
	else if (iRetVal == -3)
	{
		TSM_ERROR("Crete OpenGL Context Failed...\n");
		oglmain->uninitialize();
		uninitializeWindow();
	}
	else if (iRetVal == -4)
	{
		TSM_ERROR("Makeing OpenGL as current Context Failed...\n");
		oglmain->uninitialize();
		uninitializeWindow();
	}
	else if (iRetVal == -5)
	{
		TSM_ERROR("GLEW Initialization Failed...\n");
		oglmain->uninitialize();
		uninitializeWindow();
	}
	else
	{
		TSM_INFO("Initialize Successful...\n");
	}

	ShowWindow(hwnd, iCmdShow);

	// FORE GROUNDING AND FOCUSING WINFOW
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// GAME LOOP
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActiveWindow == TRUE)
			{
				// UPDATE
				oglmain->update();
				// RENDER
				oglmain->display();
			}
		}
	}

	oglmain->uninitialize();
	delete oglmain;
	uninitializeWindow();

	return ((int)msg.wParam);
}

// NEED CONSOLE FOR PRINT LOG IN DEBUG MODE OTHER WISE IN RELEASE MODE WINMAIN WILL CALL DIRECTLY.
#ifdef TSM_DEBUG 
int main()
{
	return WinMain(GetModuleHandle(NULL), NULL, (LPSTR)GetCommandLine(), SW_SHOWNORMAL);
}
#endif

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// FUNCTION DECLARTIONS
	void ToggleFullScreen();

	// code
	switch (iMsg)
	{
	case WM_CREATE:
		TSM::WINDOW::WindowEvent::TSM_WM_CREATE();
		break;

	case WM_ERASEBKGND:
		TSM::WINDOW::WindowEvent::TSM_WM_ERASEBKGND();
		break;

	case WM_CHAR:
		TSM::WINDOW::KeyEvent::TSM_WM_CHAR(wParam);

		switch (iMsg)
		{
		case WM_CHAR:
			switch (wParam)
			{
			case 'f':
			case 'F':
				ToggleFullScreen();
				break;
			case 27:
				PostQuitMessage(0);
				break;
			}
			break;
		}

	case WM_KEYDOWN:
		TSM::WINDOW::KeyEvent::TSM_WM_KEYDOWN(wParam);
		break;

	case WM_SIZE:
		TSM::WINDOW::WindowEvent::TSM_WM_SIZE(lParam);
		break;

	case WM_CLOSE:
		TSM::WINDOW::WindowEvent::TSM_WM_CLOSE(hwnd);
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		TSM::WINDOW::WindowEvent::TSM_WM_DESTROY();
		PostQuitMessage(0);
		break;

	case WM_MOUSEMOVE:
		TSM::WINDOW::MouseEvent::TSM_WM_MOUSEMOVE(lParam);
		break;

	case WM_MOUSEWHEEL:
		TSM::WINDOW::MouseEvent::TSM_WM_MOUSEWHEEL(wParam);
		break;

	default:
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void uninitializeWindow(void)
{
	/*if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}*/

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghwnd = NULL;
		ghdc = NULL;
	}

	if (ghwnd)
	{
		DestroyWindow(ghwnd);
	}

}

void ToggleFullScreen()
{
	// variable declartions
	static DWORD dwStyle;
	static WINDOWPLACEMENT wp;
	MONITORINFO mi;

	//	code
	wp.length = sizeof(WINDOWPLACEMENT);
	if (gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			mi.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(ghwnd, &wp) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);

				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); // nccalksize
			}

			ShowCursor(FALSE);
			gbFullScreen = TRUE;
		}
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);

		SetWindowPlacement(ghwnd, &wp);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullScreen = FALSE;
	}
}

#endif