#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")



VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen      pen(Color(255, 0, 0, 0), 10);
	graphics.DrawLine(&pen, 0, 180, 200, 180);
	graphics.DrawLine(&pen, 0, 330, 200, 330);
	graphics.DrawLine(&pen, 0, 480, 200, 480);
	graphics.DrawLine(&pen, 0, 630, 200, 630 );
	graphics.DrawRectangle(&pen, 210, 10, 170, 700);
	graphics.DrawRectangle(&pen, 230, 30, 130, 150);
	

}



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	
	HWND                hWnd;
	MSG                 msg;
	WNDCLASS            wndClass;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;



	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("GettingStarted");

	RegisterClass(&wndClass);

	hWnd = CreateWindow(
		TEXT("GettingStarted"),   // window class name
		TEXT("WINDA"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		CW_USEDEFAULT,            // initial x size
		CW_USEDEFAULT,            // initial y size
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	HWND hwndButton1 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"1",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		550,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.

	HWND hwndTextButton1 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 100, 550, 40,
		20, hWnd, NULL, NULL, NULL);


	HWND hwndButton2 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"2",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		400,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.


	HWND hwndTextButton2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 100, 400, 40,
		20, hWnd, NULL, NULL, NULL);

	HWND hwndButton3 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		250,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.


	HWND hwndTextButton3 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 100, 250, 40,
		20, hWnd, NULL, NULL, NULL);

	HWND hwndButton4 = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"4",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		100,         // y position 
		50,        // Button width
		50,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		NULL);      // Pointer not needed.


	HWND hwndTextButton4 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, 100, 100, 40,
		20, hWnd, NULL, NULL, NULL);

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC          hdc;
	PAINTSTRUCT  ps;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
} // WndProc