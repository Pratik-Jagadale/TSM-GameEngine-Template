#include "pch.h"
#include "KeyEvent.h"

namespace TSM
{
    namespace WINDOW
    {
        void KeyEvent::TSM_WM_CHAR(WPARAM wParam)
        {
            switch (wParam)
            {
            case 'f':
            case 'F':

                break;

            case '+':
                break;

            case '-':
                break;

            case 'C':
            case 'c':
                break;

            case 'p':
            case 'P':
                break;

            case 'G':
            case 'g':
                break;

            case 'B':
            case 'b':
                break;
            case 'X':
                break;

            case 'x':
                break;
            case 'Y':
                break;

            case 'y':
                break;

            case 'Z':
                break;

            case 'z':
                break;

            case 'm':
            case 'M':
                break;

            case 'r':
            case 'R':
                break;

            case 'q':
            case 'Q':
                break;

            case 'd':
            case 'D':
                break;

            case 't':
            case 'T':
                break;

            case 'n':
            case 'N':
                break;

            case 'i':
            case 'I':
                break;
            case 'k':
            case 'K':
                break;

            case 'L':
            case 'l':
                break;

            case 27:
                PostQuitMessage(0);
            }
        }

        void KeyEvent::TSM_WM_KEYDOWN(WPARAM wParam)
        {
            switch (wParam)
            {
            case VK_LEFT:
                break;

            case VK_RIGHT:
                break;

            case VK_UP:
                break;

            case VK_DOWN:
                break;

            case VK_NUMPAD8:
                break;

            case VK_NUMPAD5:
                break;

            case VK_NUMPAD4:
                break;

            case VK_NUMPAD6:
                break;

            case VK_NUMPAD7:
                break;

            case VK_NUMPAD1:
                break;

            case VK_NUMPAD9:
                break;

            case VK_NUMPAD3:
                break;

            case VK_SUBTRACT:
                break;

            case VK_ADD:
                break;

            default:
                break;
            }
        }
    }
}
