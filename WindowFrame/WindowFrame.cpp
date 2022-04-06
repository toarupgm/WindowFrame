#include "DxLib.h"
#include <iostream>
HWND g_hwnd[250];
int  g_cnt = 0;
BOOL CALLBACK WndEnumProc(HWND hWnd, LPARAM lParam)
{
	char szBuff[512];
	GetWindowTextA(hWnd, szBuff, _countof(szBuff));


	std::cout << szBuff << std::endl;
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);

	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;


	ChangeWindowMode(TRUE);
	SetUseBackBufferTransColorFlag(TRUE);
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() < 0) return -1;

	

	SetWindowSize(width, width);
	SetGraphMode(width, width, 32);


	SetWindowPos(GetMainWindowHandle(), HWND_TOPMOST, 10, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	DWORD allProc[1024];
	DWORD cbNeeded;


	

	SetForegroundWindow(GetMainWindowHandle());
    



	while (ProcessMessage() == 0)
	{

		ClearDrawScreen();

        HWND hDesktop = GetForegroundWindow();

        WINDOWINFO windowInfo;
        windowInfo.cbSize = sizeof(WINDOWINFO);

        GetWindowInfo(hDesktop, &windowInfo);




        for (int i = 0; i < 5; i++) {
            DrawBox(windowInfo.rcWindow.left + 15 - i, windowInfo.rcWindow.top - i, windowInfo.rcWindow.right + i, windowInfo.rcWindow.bottom + i - 7.5,  0x4287f5, FALSE);
        }
		

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
