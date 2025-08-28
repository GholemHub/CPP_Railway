#include "framework.h"
#include "TileClass.h"

#include <array>

#include "Railway2.h"

constexpr int MAX_LOADSTRING(100);

HINSTANCE Globals::hInstance; // current instance
WCHAR Globals::szTitle[MAX_LOADSTRING]; // The title bar text
WCHAR Globals::szWindowClass[MAX_LOADSTRING]; // the main window class name

std::array Tiles
{ 
	Tile(TileState::Empty),
	Tile(TileState::Empty), 
	Tile(TileState::Empty), 
	Tile(TileState::Empty), 
	Tile(TileState::Empty) 
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPWSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	Globals::hInstance = hInstance; // Store instance handle in our global variable

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, Globals::szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_RAILWAY2, Globals::szWindowClass, MAX_LOADSTRING);
	Globals::MyRegisterClass();

	// Perform application initialization:
	if (!Globals::InitInstance (nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAcceleratorsW(hInstance, MAKEINTRESOURCE(IDC_RAILWAY2));

	MSG msg;

	// Main message loop:
	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		if (!TranslateAcceleratorW(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM Globals::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = Globals::hInstance;
	wcex.hIcon          = LoadIconW(Globals::hInstance, MAKEINTRESOURCE(IDI_RAILWAY2));
	wcex.hCursor        = LoadCursorW(nullptr, IDC_ARROW);
	wcex.hbrBackground  = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RAILWAY2);
	wcex.lpszClassName  = Globals::szWindowClass;
	wcex.hIconSm        = LoadIconW(Globals::hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL Globals::InitInstance(int nCmdShow)
{
   HWND hWnd = CreateWindowExW(0, Globals::szWindowClass, Globals::szTitle, WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, Globals::hInstance, nullptr);

   if (!hWnd)
   {
	  return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

const int TILE_SIZE = 64;
const int GRID_SIZE = 8;

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK Globals::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBoxParamW(Globals::hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About, 0);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProcW(hWnd, message, wParam, lParam);
			}
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

			RECT rc;
			GetClientRect(hWnd, &rc);
			Graphics graphics(hdc);
			SolidBrush brush(Color(255, 0, 0, 0));
			Rect rect(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
			graphics.FillRectangle(&brush, rect);

			int clientWidth = rc.right - rc.left;
			int clientHeight = rc.bottom - rc.top;
			int gridWidth = GRID_SIZE * TILE_SIZE;
			int gridHeight = GRID_SIZE * TILE_SIZE;
			int startX = (clientWidth - gridWidth) / 2;
			int startY = (clientHeight - gridHeight) / 2;

			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK Globals::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
