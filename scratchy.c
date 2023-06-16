// Scratchy - A simple scratchpad edit window app
// 
// License: MIT / X11
// https://github.com/jimlawless/scratchy/blob/main/LICENSE
//
// Copyright (c) 2023 by James K. Lawless
// jimbo@radiks.net  https://jiml.us
// To build, use the following MinGW command:
//    gcc  scratchy.c -mwindows -o scratchy.exe

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG Msg;
    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW,
        "edit",
        "Scratchy - https://github.com/jimlawless/scratchy",
        WS_OVERLAPPEDWINDOW|ES_MULTILINE,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
        NULL, NULL, hInstance, NULL);
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Could not create Scratch Pad window", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    SetWindowText(hwnd,"");
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        if(!IsWindow(hwnd))
            break;
            
    }
    return Msg.wParam;
}