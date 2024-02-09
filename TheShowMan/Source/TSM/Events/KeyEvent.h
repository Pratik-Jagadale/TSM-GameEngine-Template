#pragma once
#include "../Core.h"

namespace TSM
{
    namespace WINDOW
    {
        class TSM_API KeyEvent
        {
        public:
            static void TSM_WM_CHAR(WPARAM wParam);
            static void TSM_WM_KEYDOWN(WPARAM wParam);
        };
    }
}
