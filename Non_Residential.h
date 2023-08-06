#pragma once
#include "Property.h"
class Non_Residential :public Property
{
	//how many non residential properties are owned by single player
	//by that it rents will be upgraded

public:
	Non_Residential();
	Non_Residential(int price, int rent, int owner, bool mortgaged, char* name, int position);
	~Non_Residential();

	void dummy();
};

