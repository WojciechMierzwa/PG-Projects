// draw.cpp : Defines the entry point for the application.
// projekt wykonali: Wojciech Mierzwa i Mateusz Polom

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>

#define MAX_LOADSTRING 100
#define TMR_1 1

struct Probka
{
public:
	float nr;
	float roll;
	float pitch;
	float yaw;

	Probka(int n, float r, float p, float y)
	{
		this->nr = n;
		this->roll = r;
		this->pitch = p;
		this->yaw = y;
	}
};

HBITMAP CreateOffscreenBmp(int wd, int hgt) {
	HDC hdcScreen = GetDC(NULL);

	HDC hdcBmp = CreateCompatibleDC(hdcScreen);

	HBITMAP bmp = CreateCompatibleBitmap(hdcScreen, wd, hgt);
	HBITMAP hbmOld = static_cast<HBITMAP>(SelectObject(hdcBmp, bmp));

	// Now, you can draw into bmp using the device context hdcBmp...
	RECT r = { 0, 0, wd, hgt };
	FillRect(hdcBmp, &r, static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)));

	SelectObject(hdcBmp, hbmOld);
	DeleteDC(hdcBmp);
	ReleaseDC(NULL, hdcScreen);

	return bmp;
}

bool animation = false;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
INT startFrame = 1;

// buttons
HWND hwndButton;

//zmienne do manipulowania rysowanym polem
int START_X = 50;
int SZER = 708;
int WYS = 500;
// sent data
int col = 0;
std::vector<Probka> data;
RECT drawArea1 = { START_X, 100, SZER, WYS };
RECT drawArea2 = { START_X, 480, SZER, 502};

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	
	HBRUSH b = CreateSolidBrush(RGB(255, 255, 255));
		FillRect(hdc, &drawArea1, b);

	//HBRUSH b2 = CreateSolidBrush(RGB(50, 50, 50));
	FillRect(hdc, &drawArea2, b);

	//tworze 3 'mazaki' ka¿dy dla innej danej (roll/pitch/yaw)
	Pen penRed(Color(255, 255, 0, 0));
	Pen penGreen(Color(255, 0, 255, 0));
	Pen penBlue(Color(255, 0, 0, 255));
	Pen penBlack(Color(255, 0, 0, 0));
	
	for (int i = startFrame; i < 654; i++)
	{
		graphics.DrawLine(&penRed, START_X + data[i - 1].nr - startFrame, data[i - 1].roll + 300, START_X + data[i].nr - startFrame, data[i].roll + 300);
		graphics.DrawLine(&penGreen, START_X + data[i - 1].nr - startFrame, data[i - 1].pitch + 300, START_X + data[i].nr - startFrame, data[i].pitch + 300);
		graphics.DrawLine(&penBlue, START_X + data[i - 1].nr - startFrame, data[i - 1].yaw + 300, START_X + data[i].nr - startFrame, data[i].yaw + 300);
		graphics.DrawRectangle(&penBlack, START_X + value, 480, 10, 20);
	}

	graphics.DrawRectangle(&penBlack, START_X + value, 480, 10, 20);
}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea==NULL)
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea

	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

//funkcja wczytuj¹ca dane z pliku outputRotateA01.log
void inputData()
{	
	//otwieram plik który zawiera dane
	std::ifstream plik;
	plik.open("./outputRotateA01.log");

	if (!plik.is_open()) exit(1);

	//tworze zmienne potrzebne do wczytwania danych
	float roll, pitch, yaw, a_x, a_y, a_z, m_x, m_y, m_z, omega_x, omega_y, omega_z;

	//data.push_back(Point(0, 0));
	//w pliku znajduj¹ siê 654 próbki
	for (int i = 1; i < 655; i++)
	{
		//wczytujê dane dla jednej próbki z pliku
		plik >> roll >> pitch >> yaw >> a_x >> a_y >> a_z >> m_x >> m_y >> m_z >> omega_x >> omega_y >> omega_z;
		//tworzê obiekt próbki
		Probka probka = Probka(i, roll, pitch, yaw);
		//dodaje próbkê do wektora przechowuj¹cego wszystkie dane
		data.push_back(probka);
	}
}

int OnCreate(HWND window)
{
	inputData();
	return 0;
}

// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	value = 0;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       
	
	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Draw"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		SZER + START_X, 60,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("DrawAll"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		SZER + START_X, 0,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	// create button and store the handle                                                       

	hwndButton = CreateWindow(TEXT("button"), TEXT("Timer ON"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		SZER + START_X, 155, 100, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("Timer OFF"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		SZER + START_X, 200, 100, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("0"),
		WS_CHILD | WS_VISIBLE, SZER + START_X, 250, 140,
		20, hWnd, (HMENU)ID_EDIT, NULL, NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("Pomin"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		SZER + START_X, 300, 160, 60, hWnd, (HMENU)ID_BUTTON3, GetModuleHandle(NULL), NULL);

	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);


	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window (low priority)
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HWND editControl1;
	HDC hdc;
	HBRUSH b;
	int a;
	HBRUSH b2;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON1 :
			col++;
			if (col > 10)
				col = 0;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON2 :
			repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON3:
			editControl1 = GetDlgItem(hWnd, ID_EDIT);
			startFrame = GetDlgItemInt(hWnd, ID_EDIT, 0, 0);
			if (startFrame <= 0) startFrame = 1;
			if (startFrame >= 655) startFrame = 644;
			repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;

		case ID_RBUTTON1:
			value = 0;
			SetTimer(hWnd, TMR_1, 25, 0);
			value += startFrame;
			InvalidateRect(hWnd, &drawArea1, TRUE); //repaint drawArea
			hdc = BeginPaint(hWnd, &ps);//GetWindowDC(hWnd);
			b = CreateSolidBrush(RGB(255, 255,255));
			FillRect(hdc, &drawArea1, b);

			//b2 = CreateSolidBrush(RGB(50, 50, 50));
			FillRect(hdc, &drawArea2, b);
			EndPaint(hWnd, &ps);
			break;
		case ID_RBUTTON2:
			value = 0;
			KillTimer(hWnd, TMR_1);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		//MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		//hdc = GetWindowDC(hWnd);
		//MyOnPaint(hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_ERASEBKGND:
		// Don't paint background if you are blitting from off screen surface.
		return 1;
		break;
	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			value++;

			if (value == 655)
			{
				value = 0;
				KillTimer(hWnd, TMR_1);
				animation = false;
				break;
			}
			hdc = GetWindowDC(hWnd);//BeginPaint(hWnd, &ps);
			Graphics graphics(hdc);

			Pen penRed(Color(255, 255, 0, 0));
			Pen penGreen(Color(255, 0, 255, 0));
			Pen penBlue(Color(255, 0, 0, 255));
			Pen penBlack(Color(255, 0, 0, 0));

			graphics.DrawLine(&penRed, START_X + data[value - 1].nr - startFrame, data[value - 1].roll + 350, START_X + data[value].nr - startFrame, data[value].roll + 350);
			graphics.DrawLine(&penGreen, START_X + data[value - 1].nr - startFrame, data[value - 1].pitch + 350, START_X + data[value].nr - startFrame, data[value].pitch + 350);
			graphics.DrawLine(&penBlue, START_X + data[value - 1].nr - startFrame, data[value - 1].yaw + 350, START_X + data[value].nr - startFrame, data[value].yaw + 350);

			graphics.DrawRectangle(&penBlack, START_X + value - startFrame, 480+50, 10, 20);

			EndPaint(hWnd, &ps);
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


INT_PTR CALLBACK PasswordProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR lpszPassword[16];
	WORD cchPassword;

	switch (message)
	{
	case WM_INITDIALOG:
		// Set password character to a plus sign (+) 
		SendDlgItemMessage(hDlg,
			NULL,
			EM_SETPASSWORDCHAR,
			(WPARAM)'+',
			(LPARAM)0);

		// Set the default push button to "Cancel." 
		SendMessage(hDlg,
			DM_SETDEFID,
			(WPARAM)IDCANCEL,
			(LPARAM)0);

		return TRUE;

	case WM_COMMAND:
		// Set the default push button to "OK" when the user enters text. 
		if (HIWORD(wParam) == EN_CHANGE)
		{
			SendMessage(hDlg,
				DM_SETDEFID,
				(WPARAM)IDOK,
				(LPARAM)0);
		}
		switch (wParam)
		{
		case IDOK:
			// Get number of characters. 
			cchPassword = (WORD)SendDlgItemMessage(hDlg,
				NULL,
				EM_LINELENGTH,
				(WPARAM)0,
				(LPARAM)0);
			if (cchPassword >= 16)
			{
				MessageBox(hDlg,
					L"Too many characters.",
					L"Error",
					MB_OK);

				EndDialog(hDlg, TRUE);
				return FALSE;
			}
			else if (cchPassword == 0)
			{
				MessageBox(hDlg,
					L"No characters entered.",
					L"Error",
					MB_OK);

				EndDialog(hDlg, TRUE);
				return FALSE;
			}

			// Put the number of characters into first word of buffer. 
			*((LPWORD)lpszPassword) = cchPassword;

			// Get the characters. 
			SendDlgItemMessage(hDlg,
				NULL,
				EM_GETLINE,
				(WPARAM)0,       // line 0 
				(LPARAM)lpszPassword);

			// Null-terminate the string. 
			lpszPassword[cchPassword] = 0;

			MessageBox(hDlg,
				lpszPassword,
				L"Did it work?",
				MB_OK);

			// Call a local password-parsing function. 
			//ParsePassword(lpszPassword);

			EndDialog(hDlg, TRUE);
			return TRUE;

		case IDCANCEL:
			EndDialog(hDlg, TRUE);
			return TRUE;
		}
		return 0;
	}
	return FALSE;

	UNREFERENCED_PARAMETER(lParam);
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
