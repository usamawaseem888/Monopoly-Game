#include "Residential.h"
#include <iostream>
using namespace std;


Residential::Residential()
{
	block = 0;
	house = 0;
	shops = 0;
	hotel = 0;
	gas = 0;
	wifi = 0;
	electricity = 0;
	payrent = 0;
}

Residential::Residential(char block, int house, int shops, bool hotel ,int payrent, bool gas, bool wifi, bool electricity, int price, int rent, int owner, bool mortgaged,char*name,int position):Property(price , rent, owner , mortgaged,name,position)
{
	this->block = block;
	this->house = house;
	this->shops = shops;
	this->hotel = hotel;
	this->gas = gas;
	this->wifi = wifi;
	this->electricity = electricity;
	payrent = getrent(); //the default rent of a property without any building
}


Residential::~Residential()
{
	//destructor of property?
}

char Residential::getblock()
{
	return block;
}

int Residential::gethouse()
{
	return house;
}

int Residential::getshops()
{
	return shops;
}

bool Residential::gethotel()
{
	return hotel;
}

bool Residential::getgas()
{
	return gas;
}

bool Residential::getwifi()
{
	return wifi;
}

bool Residential::getelectricity()
{
	return electricity;
}

int Residential::getpayrent()
{
	return payrent;
}

void Residential::upgrade(Player& whichplayer)
{
	//in monopoly.cpp
	//



	//enter this function only if player_cash > 300 i.e max upgrading cost
	//ask this before calling this function
	/*cout << "You want to build or not" << endl;
	int what = 0;*/
	cout << "Build a property(1) or Add Utility(2) " << endl;
	int select = 0;
	if (select == 1)
	{
		if (house == 0)
		{
			//building first time
			house++;
			payrent = payrent + (getrent() / 100) * 30;
			whichplayer.Setcash(whichplayer.getcash() - 100);
		}
		else
		{
			if (house == 3)
			{
				shops++;
				payrent = payrent + 2 * payrent;
				whichplayer.Setcash(whichplayer.getcash() - 300);
			}
			if (shops == 2)
			{
				hotel = 1;
				payrent = payrent + (payrent / 100) * 20;
				whichplayer.Setcash(whichplayer.getcash() - 300);
			}
			if (house < 3)
			{
				house++;
				payrent = payrent + (payrent / 100) * 30;
				whichplayer.Setcash(whichplayer.getcash() - 100);
			}
		}
	}
	if (select == 2)
	{
		cout << "Which utility ? " << endl;
		cout << "1. GAS " << endl;
		cout << "2. Electricity " << endl;
		cout << "3. WiFi " << endl;
		int which = 0;
		cin >> which;
		if (which == 1)
		{
			if (!gas)
			{
				gas = 1;
				payrent = payrent + (payrent / 100) * 20;
				whichplayer.Setcash(whichplayer.getcash() - 50);
			}
			if (gas)
			{
				cout << "Already added " << endl;
			}
			
		}
		if (which == 2)
		{
			if (!electricity)
			{
				electricity = 1;
				payrent = payrent + (payrent / 100) * 20;
				whichplayer.Setcash(whichplayer.getcash() - 50);
			}
			if (electricity)
			{
				cout << "Already added " << endl;
			}
		}
		if (which == 3)
		{
			if (!wifi)
			{
				wifi = 1;
				payrent = payrent + (payrent / 100) * 10;
				whichplayer.Setcash(whichplayer.getcash() - 30);
			}
			if (wifi)
			{
				cout << "Already added " << endl;
			}
		}

	}
	
}

//int Residential::CalPropertyWorth()
//{
//
//
//
//	return 0;
//}

void Residential::dummy()
{
}
