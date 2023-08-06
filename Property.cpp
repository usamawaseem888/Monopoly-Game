#include "Property.h"
#include<string>
#include"Non_Residential.h"
#include"Residential.h"
using namespace std;

Property::Property()
{
	price = 0;
	rent = 0;
	owner = -1;
	mortgaged = 0;
}

Property::Property(int price, int rent, int owner , bool mortgaged, char *name, int position):Cell(name,position)
{
	//owner will not be in parameters because when object is made , it is not owned by anyone
	this->price = price;
	this->rent = rent;
	this->mortgaged = mortgaged;
	this->owner = owner;

}


Property::~Property()
{
	//destructor of cell ?
}

int Property::getprice()
{
	return price;
}

int Property::getrent()
{
	return rent;
}

int Property::getowner()
{
	return owner;
}

bool Property::getmortgage()
{
	return mortgaged;
}

void Property::Setprice(int p)
{
	price = p;
}

void Property::Setrent(int rent)
{
	this->rent = rent;
}

void Property::Setowner(int owner)
{
	this->owner = owner;
}

void Property::Setmortgage(bool mstatus)
{
	mortgaged = mstatus;
}

//int Property::CalPropertyWorth()
//{
//	
//
//	return 0;
//}

void Property::dummy()
{
}
