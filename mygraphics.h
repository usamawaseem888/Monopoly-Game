#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H
#include <windows.h>


//To compile your program with graphics.cpp you need to include the gdi32 library
//compile it using: g++ -o myprog.exe myprog.cpp graphics.cpp -lgdi32
// for visual studio if you get linker errors then goto properties->linker->input and add the library 
//gdi32.lib or gdi64.lib depending on your system.  Normally this libaray is added by default so you may be able 
//to compile the code.


//set the color of a pixel at (x,y) to colorVal
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage exammple: mySetPixel(200,200,RGB(230,0,0));
void mySetPixel(int x,int y, COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	SetPixel(device_context, x, y, colorVal);
	ReleaseDC(console_handle, device_context);
}


//draw a line from (x1,y1) to (x2,y2) using lineColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: myLine(0,0,300,400,RGB(200,0,0));
void myLine(int x1, int y1, int x2, int y2, COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, lineColor); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	DeleteObject(pen);

	ReleaseDC(console_handle, device_context);
}
//draw a rectangle with top corner (x1,y1) and bottom corner(x2,y2) with outline lineColor
//and fillColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myRect(300,300,350,350,RGB(100,0,0),RGB(0,0,240));
void myRect(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 4, lineColor);
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);
}
void myRect1(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 5, lineColor);
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);
}

//draw an ellipse within a rectangle with top corner (x1,y1) and bottom corner(x2,y2)
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myEllipse(100,50,180,200,RGB(100,0,0),RGB(0,0,240));
void myEllipse(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, lineColor);
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);

}

//write a string at position (x,y) in lineColor and background color as fillColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myDrawText(100,200,40,"Good day",RGB(200,0,200),RGB(3,200,3));
void myDrawText(int x, int y, int ht, char str[], COLORREF lineColor, COLORREF fillColor)
{
	WCHAR wstr[20] = {};
	for (int i = 0; i<20 && str[i]; ++i)
		wstr[i] = str[i];

	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x + ht;
	rects.bottom = y + ht;//(x,y,x+ht,y+ht);

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	SetTextColor(device_context, lineColor);
	SetBkColor(device_context, fillColor);
	DrawText(device_context, wstr, -1, &rects, DT_TOP | DT_NOCLIP);

	ReleaseDC(console_handle, device_context);

}


//write a string at position (x,y) in lineColor and background color as fillColor
//the font size will be determined by the ht parameter
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myDrawText(100,200,40,"Good day",RGB(200,0,200),RGB(3,200,3));

void myDrawTextWithFont(int x, int y, int ht, char  str[], COLORREF lineColor, COLORREF fillColor)
{
	WCHAR wstr[20] = {};
	for (int i = 0; i<20 && str[i]; ++i)
		wstr[i] = str[i];

	RECT rects;
	HFONT hFont;
	rects.left = x;
	rects.top = y;
	rects.right = x + ht;
	rects.bottom = y + ht;//(x,y,x+ht,y+ht);

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	hFont = CreateFont(ht, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, 1, VARIABLE_PITCH, TEXT("Impact"));
	SelectObject(device_context, hFont);

	SetTextColor(device_context, lineColor);
	SetBkColor(device_context, fillColor);
	DrawText(device_context, wstr, -1, &rects, DT_TOP | DT_NOCLIP);
	DeleteObject(hFont);
	ReleaseDC(console_handle, device_context);

}

#endif


