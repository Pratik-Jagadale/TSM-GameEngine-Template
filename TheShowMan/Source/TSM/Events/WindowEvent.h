#pragma once
#include "../Core.h"

namespace TSM
{
    namespace WINDOW
    {
        class TSM_API WindowEvent
        {
        public:
            WindowEvent() {}
            ~WindowEvent() {}

            static void TSM_WM_CREATE(void);
            static void TSM_WM_ERASEBKGND(void);
            static void TSM_WM_SIZE(LPARAM lParam);
            static void TSM_WM_DESTROY(void);
            static void TSM_WM_CLOSE(HWND hwnd);
        };
    }
}
