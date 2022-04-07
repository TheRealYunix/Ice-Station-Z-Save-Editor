#include <windows.h>
#include <cassert>
#include <iostream>

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <direct.h>


#include "HexEditor.h"

#define listbox 123
#define Button1 100
#define Button2 101
#define ButtonLoad 105

/*Other Specials*/
HWND hList;
char SelectedData[]= "Data0";

HWND hEdit;
char Textbuffer[5]; //Health Edit Box Buffer

HWND fEdit;
char fEditb[5]; //Food Edit Box buffer

HWND wEdit;
char wEditb[5]; //Water Edit box buffer

HWND HexEditF;
char DecimalConverter[10]; //Decimal to Hex Converter buffer

HWND bEdit;
char bEditb[5];	 //Mystery

HWND dEdit;
char dEditb[5]; //Day Edit Box Buffer

HWND walkedEdit;
char walkedEditb[5];

HWND kzEdit;
char kzEditb[5];

HWND kpEdit;
char kpEditb[5];

LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_COMMAND:

		if (LOWORD(wParam) == Button1) {
			GetWindowText(hEdit, Textbuffer, 5);
			GetWindowText(fEdit, fEditb, 5);
			GetWindowText(wEdit, wEditb, 5);
			GetWindowText(bEdit, bEditb, 5);
			GetWindowText(dEdit, dEditb, 5);
			GetWindowText(walkedEdit, walkedEditb, 5);
			GetWindowText(kzEdit, kzEditb, 5);
			GetWindowText(kpEdit, kpEditb, 5);

			if (SendMessage(hList, LB_GETSEL, 0, 0) > 0) {
				strcpy(SelectedData, "Data0");
			}

			if (SendMessage(hList, LB_GETSEL, 1, 0) > 0) {
				strcpy(SelectedData, "Data1");
			}

			if (SendMessage(hList, LB_GETSEL, 2, 0) > 0) {
				strcpy(SelectedData, "Data2");
			}

			HexLetterEdit(Textbuffer, fEditb, wEditb, bEditb, SelectedData, dEditb, walkedEditb, kzEditb, kpEditb);
		}


		if (LOWORD(wParam) == Button2) {
			std::cout << "\t\n\n---Hex Converter---\n" << std::endl;
			GetWindowText(HexEditF, DecimalConverter, 10);

			HexEdit(DecimalConverter);
		}

		if (LOWORD(wParam) == ButtonLoad) {
	

		
		}
		
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int main() {

	HINSTANCE hInstance = GetModuleHandle(0);
	HWND hWnd;

	HWND hButton;
	WNDCLASS winw;
	MSG msg;

	winw = {};
	winw.style = CS_HREDRAW | CS_HREDRAW;
	winw.lpfnWndProc = MessageHandler;
	winw.hInstance = hInstance;
	winw.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	winw.lpszClassName = "CPPWINDOW";
	assert(RegisterClass(&winw));



	hWnd = CreateWindow("CPPWINDOW", "Ice Station Z Save Editor", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT , CW_USEDEFAULT ,555 ,600, 0, 0, hInstance, 0);
	

	/*Button's*/
	hButton = CreateWindow("button", "Create", WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 10, 60, 100, 30, hWnd, (HMENU)Button1, hInstance, 0);
	hButton = CreateWindow("button", "Advanced", WS_TABSTOP | WS_CHILD | 0 | BS_DEFPUSHBUTTON, 10, 100, 100, 25, hWnd, (HMENU)ButtonLoad, hInstance, 0);
	hButton = CreateWindow("button", "HexConverter", WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 10, 170, 100, 25, hWnd, (HMENU)Button2, hInstance, 0);

	/*Text's*/
	HWND TX1 = CreateWindow("STATIC", "Health", WS_VISIBLE | WS_CHILD | NULL, 10, 40, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX2 = CreateWindow("STATIC", "v2.4-3", WS_VISIBLE | WS_CHILD | NULL, 10, 225, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX3 = CreateWindow("STATIC", "Decimal Value", WS_VISIBLE | WS_CHILD | NULL, 110, 195, 100, 15, hWnd, NULL, hInstance, NULL);
	HWND TX4 = CreateWindow("STATIC", "Food", WS_VISIBLE | WS_CHILD | NULL, 150, 40, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX5 = CreateWindow("STATIC", "Water", WS_VISIBLE | WS_CHILD | NULL, 290, 40, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX6 = CreateWindow("STATIC", "Battery", WS_VISIBLE | WS_CHILD | NULL, 430, 40, 50, 15, hWnd, NULL, hInstance, NULL);
	
	HWND TX7 = CreateWindow("STATIC", "Days", WS_VISIBLE | WS_CHILD | NULL, 10, 430, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX8 = CreateWindow("STATIC", "Walked KM", WS_VISIBLE | WS_CHILD | NULL, 150, 430, 50, 15, hWnd, NULL, hInstance, NULL);
	HWND TX9 = CreateWindow("STATIC", "Killed Zombies", WS_VISIBLE | WS_CHILD | NULL, 290, 430, 150, 15, hWnd, NULL, hInstance, NULL);
	HWND TX10 = CreateWindow("STATIC", "Killed Players", WS_VISIBLE | WS_CHILD | NULL, 430, 430, 150, 15, hWnd, NULL, hInstance, NULL);

	/*HexConverter Input*/
	HexEditF = CreateWindow("edit", "1234", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 170, 100, 25, hWnd, 0, 0, 0);
	hEdit = CreateWindow("edit", "9999", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 10, 100, 30, hWnd, 0, 0, 0);
	fEdit = CreateWindow("edit", "9999", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 10, 100, 30, hWnd, 0, 0, 0);
	wEdit = CreateWindow("edit", "9999", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 10, 100, 30, hWnd, 0, 0, 0);
	bEdit = CreateWindow("edit", "9999", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 430, 10, 100, 30, hWnd, 0, 0, 0);

	dEdit = CreateWindow("edit", "100", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 400, 90, 25, hWnd, 0, 0, 0);
	walkedEdit = CreateWindow("edit", "100", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 400, 90, 25, hWnd, 0, 0, 0);
	kzEdit = CreateWindow("edit", "10", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 290, 400, 90, 25, hWnd, 0, 0, 0);
	kpEdit = CreateWindow("edit", "10", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER, 430, 400, 90, 25, hWnd, 0, 0, 0);

	/*Other*/
	hList = CreateWindowEx(WS_EX_CLIENTEDGE, "listbox", "", WS_CHILD| WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 140,60,130,60,hWnd, (HMENU)listbox, NULL, NULL);
	SendMessage(hList, LB_ADDSTRING, NULL, (LPARAM)"Data0 (Save 1)");
	SendMessage(hList, LB_ADDSTRING, NULL, (LPARAM)"Data1 (Save 2)");
	SendMessage(hList, LB_ADDSTRING, NULL, (LPARAM)"Data2 (Save 3)");


	//Main loop
	while (true) {
		BOOL result = GetMessage(&msg, 0, 0, 0);
		if (result > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			return result;
		}
	}
}