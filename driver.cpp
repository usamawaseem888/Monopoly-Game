#include <iostream>
#include <string>
#include"Monopoly.h"
#include"mygraphics.h"
#include<Windows.h>
using namespace std;

//class cell
//{
//public:
//	cell();
//	~cell();
//	virtual void print()
//		= 0;
//
//private:
//	int pos;
//
//};
//
//cell::cell()
//{
//}
//
//cell::~cell()
//{
//}
//
//class property:public cell
//{
//public:
//
//public:
//	void print() {
//		cout << "property " << endl;
//	}
//
//private:
//
//};
//
//class residencial : public property
//{
//public:
//	void print(){
//		cout << "residential " << endl;
//	}
//	void buy()
//	{
//		cout << "Buy " << endl;
//	}
//};
//
//class non_residencial :public property
//{
//
//public:
//	void print() {
//		cout << " non residential " << endl;
//	}
//	void non_buy()
//	{
//		cout << "not Buy " << endl;
//	}
//};
//
//class teasure :public cell
//{
//public:
//	
//private:
//
//};
//
//class taxes :public cell
//{
//public:
//	void print()
//	{
//		cout << "taxese" << endl;
//	}
//};
//
//class monopoly
//{
//public:
//	vector<cell*>  c;
//
//};
//
//int main()
//{
//
//	monopoly obj;
//	cell * temp = new taxes();
//
//	obj.c.push_back(temp);
//	temp = new residencial();
//	obj.c.push_back(temp);
//
//	obj.c[0]->print();
//	obj.c[1]->print();
//
//	
//	string clas = typeid(*(obj.c[1])).name();
//	if("class residencial" == clas)
//	{
//		residential*tp=dynamic_cast<residencial*>(obj.c[1]);
//		tp->buy();
//	}
//
//
//	
//
//
//	system("pause");
//}

int main()
{
	int players;
	cout << "Enter number of Players:";
	cin >> players;
	Monopoly obj(players);
	while(1)
	{
	obj.TurnTaking();
    }
	cout << "Main is working!!!\n";
	system("pause");
	return 0;
}

void Board()
{
	//background
	myRect(500, 20, 1890, 1070, RGB(0, 0, 0, ), RGB(245, 222, 179));

	

	//boxesbottom
	int x = 0;
    for(int i=0;i<9;i++,x=x+110)
	myRect1(1580-x, 920, 1690-x, 1065, RGB(0, 0, 0, ), RGB(240, 230, 140));

	//boxesleftside
	x = 0;
	for (int i = 0; i<9; i++, x = x + 80)
		myRect1(500, 180+x, 670, 270+x, RGB(0, 0, 0, ), RGB(240, 230, 140));

	//boxesbottom
	x = 0;
	for (int i = 0; i<9; i++, x = x + 110)
		myRect1(1580 - x, 920, 1690 - x, 1065, RGB(0, 0, 0, ), RGB(240, 230, 140));

	//boxestop
	x = 0;
	for (int i = 0; i<9; i++, x = x + 110)
		myRect1(1580 - x, 20, 1690 - x, 165, RGB(0, 0, 0, ), RGB(240, 230, 140));

	//boxesside
	x = 0;
	for (int i = 0; i<9; i++, x = x + 80)
		myRect1(1730, 180 + x, 1890, 270 + x, RGB(0, 0, 0, ), RGB(240, 230, 140));

	//JailCell
	myRect1(500, 900, 700, 1070, RGB(0, 0, 0, ), RGB(96, 96, 96));

	//Parking
	myRect(500, 20, 700, 180, RGB(0, 0, 0, ), RGB(0, 128, 255));

	//G0tojail
	myRect(1690, 20, 1890, 180, RGB(0, 0, 0, ), RGB(255, 0, 0));

	//start
	myRect1(1690, 900, 1890, 1070, RGB(0, 0, 0, ), RGB(255, 0, 0));
}



//void main()
//{
//	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//	//HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	//system("COLOR F4");
//	//while (1)
//	//{
//	//	//Board();
//	//	Sleep(500);
//	//}
//	system("pause");
//}