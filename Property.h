#pragma once
#include<string>
#include "Cell.h"
using namespace std;
class Property : public Cell
{
	int price;
	int rent;
	int owner;
	bool mortgaged;
public:
	Property();
	Property(int, int , int , bool, char*, int);
	~Property();
	//Getters
	int getprice();
	int getrent();
	int getowner();
	bool getmortgage();
	//Setters
	void Setprice(int);
	void Setrent(int);
	void Setowner(int);
	void Setmortgage(bool);

	//int CalPropertyWorth();

	void dummy();
};

