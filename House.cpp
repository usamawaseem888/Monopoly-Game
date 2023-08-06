#include "House.h"

House::House()
{
	gas = 0;
	wifi = 0;
	electricity = 0;
}

House::House(bool g, bool w, bool e)
{
	gas = g;
	wifi = w;
	electricity = e;

}

bool House::getGas()
{
	return gas;
}

bool House::getwifi()
{
	return wifi;
}
bool House::getelectricity()
{
	return electricity;
}

void House::Setgas(bool gas)
{
	this->gas = gas;
}

void House::Setwifi(bool wifi)
{
	this->wifi = wifi;
}

void House::Setelec(bool elec)
{
	electricity = elec;
}