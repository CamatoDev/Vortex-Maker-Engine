#ifndef __CORE_WINDOW_H__
#define __CORE_WINDOW_H__

#pragma once

#include <Windows.h>
#include "Core/Exports.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class CORE_API Window
{
public:
    Window();
    Window(const Window&) = delete;
    Window& operator =(const Window&) = delete;
    ~Window();

    bool ProcessMessages();
private:
    HINSTANCE _hInstance;
    HWND _hWind;
};

#endif    // __CORE_WINDOW_H__