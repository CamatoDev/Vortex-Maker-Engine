#include "pch.h"
#include "Window.h"

// Définition des dimension de la fenêtre  
int width = 640;
int height = 480;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    static HDC hDC;
    PAINTSTRUCT ps;
    
    static HPEN hPen;
    static HBRUSH hBrush;
    
    RECT customRect = { width/2 - 140, 5, width/2 + 140, 30 }; // left, top, right, bottom
    LPCTSTR text = L"Hello, this is Vortex Maker Engine V1.0!";
    
    switch(uMsg)
    {
        case WM_CREATE:
        {
            LOGPEN pen;
            LOGBRUSH brush;
            
            hDC = GetDC(hwnd);
            
            /* Création et sélection du crayon */
            pen.lopnColor = RGB(255, 0, 0);
            pen.lopnStyle = PS_SOLID;
            pen.lopnWidth.x = 2;
            
            hPen = CreatePenIndirect(&pen);
            SelectObject(hDC, hPen);
            
            /* Création et sélection de la brosse */
            brush.lbColor = RGB(0, 0, 255);
            brush.lbHatch = 0;
            brush.lbStyle = BS_SOLID;
            
            hBrush = CreateBrushIndirect(&brush);
            SelectObject(hDC, hBrush);
            
            break;
        }
    
        case WM_PAINT:
        {
            BeginPaint(hwnd, &ps);
            SetTextColor(hDC, RGB(0, 255, 0));
            SetBkMode(hDC, OPAQUE);
            SetBkColor(hDC, RGB(10, 20, 50));  // Fond vert
            DrawText(hDC, text, -1, &customRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RoundRect(hDC, 10, 40, width - 10, height/2 + 100, 10, 10);
            EndPaint(hwnd, &ps);
            
            break;
        }
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;    
        case WM_DESTROY:
            ReleaseDC(hwnd, hDC);
            DeleteObject(hPen);
            DeleteObject(hBrush);
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window()
    : _hInstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"Vortex Window Class";

    // Paramètre de la fenêtre
    WNDCLASS wndClass = {};
    wndClass.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = _hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // Enregistrement de la class
    RegisterClass(&wndClass);

    // Flags
    DWORD style = WS_OVERLAPPEDWINDOW;

    

    // Cadrage
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    //
    AdjustWindowRect(&rect, style, false);

    _hWind = CreateWindowEx(
        0,
        CLASS_NAME,
        L"VmEditor",
        WS_OVERLAPPEDWINDOW,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        _hInstance,
        NULL
    );

    //
    ShowWindow(_hWind, SW_SHOW);
}

Window::~Window(){
    const wchar_t* CLASS_NAME = L"Vortex Window Class";

    UnregisterClass(CLASS_NAME, _hInstance);
}

bool Window::ProcessMessages(){
    MSG msg = {};

    while(PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}