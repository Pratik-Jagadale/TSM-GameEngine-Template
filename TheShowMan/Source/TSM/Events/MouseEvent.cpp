#include "pch.h"
#include "MouseEvent.h"

namespace TSM
{
    namespace WINDOW
    {
        void MouseEvent::TSM_WM_MOUSEMOVE(LPARAM lParam)
        {
            float mouseX = LOWORD(lParam);
            float mouseY = HIWORD(lParam);
        }

        void MouseEvent::TSM_WM_MOUSEWHEEL(WPARAM wParam)
        {
            short scrollDelta = GET_WHEEL_DELTA_WPARAM(wParam);
        }

    }
}
