#pragma once

#include <windows.h>

#include "resource.h"

namespace Globals
{
	extern HINSTANCE hInstance; // current instance
	extern WCHAR szTitle[]; // The title bar text
	extern WCHAR szWindowClass[]; // the main window class name

	ATOM MyRegisterClass();
	BOOL InitInstance(int);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
}
