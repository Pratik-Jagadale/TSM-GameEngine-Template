#include "pch.h"
#include "WindowEvent.h"

namespace TSM
{
    namespace WINDOW
    {
        void resize(int, int)
        {
        }

        void WindowEvent::TSM_WM_CREATE(void)
        {
        }

        void WindowEvent::TSM_WM_ERASEBKGND(void)
        {
        }

        void WindowEvent::TSM_WM_SIZE(LPARAM lParam)
        {
            resize(WORD(lParam), HIWORD(lParam));
        }

        void WindowEvent::TSM_WM_DESTROY(void)
        {
            PostQuitMessage(0);
        }

        void WindowEvent::TSM_WM_CLOSE(HWND hwnd)
        {
            DestroyWindow(hwnd);
        }
    }
}
