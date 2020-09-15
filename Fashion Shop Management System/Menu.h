#ifndef _MENU_
#define _MENU_

#include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>


using namespace std;

class Menu
{

public:

	enum Color
	{
		RED = 12
	};

	static void gotoxy(int x, int y)
	{
		static HANDLE h = NULL;
		if (!h)
			h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c = { x, y };
		SetConsoleCursorPosition(h, c);
	}

	static void TextColor(int x)
	{
		HANDLE mau;
		mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}

private:

	static stringstream _buffer;

public:

	static void showMenu();
	
	static void continueMenu(int x = 0, int y = 0);

	static void showProductManagementMenu();
	
	static void showStaffMenu();

	static void showSellerMenu();

	static void showSecurityMenu();
};


#endif // !_MENU_