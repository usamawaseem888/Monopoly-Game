#pragma once
#include "Property.h"
#include "Player.h"

class Residential :public Property
{
	char block;
	int  house;
	int  shops;
	bool hotel;
	int payrent;

	//Utilities
	bool gas;
	bool wifi;
	bool electricity;
public:
	Residential();
	Residential(char, int, int, bool , int , bool, bool, bool, int, int, int, bool,char*,int);
	~Residential();
	//Getters
	char getblock();
	int gethouse();
	int getshops();
	bool gethotel();
	bool getgas();
	bool getwifi();
	bool getelectricity();
	int getpayrent();

	void upgrade(Player& whichplayer);

	//int CalPropertyWorth();

	void dummy();
};

