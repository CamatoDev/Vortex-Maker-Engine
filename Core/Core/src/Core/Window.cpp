#include "pch.h"
#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch(uMsg){
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
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
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = _hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;

    // Enregistrement de la class
    RegisterClass(&wndClass);

    // Flags
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;

    // Définition des dimension de la fenêtre  
    int width = 640;
    int height = 480;

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
        style,
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