#pragma once
#include "../Core.h"

namespace TSM
{
    namespace WINDOW
    {
        class TSM_API MouseEvent
        {
        public:
            static void TSM_WM_MOUSEMOVE(LPARAM lParam);
            static void TSM_WM_MOUSEWHEEL(WPARAM wParam);
        };
    }
}
