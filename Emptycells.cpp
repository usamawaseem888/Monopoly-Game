#include "Emptycells.h"
#include <iostream>
using namespace std;


Emptycells::Emptycells()
{
	start = 0;
	parking = 0;
	jailcell = 0;
	gotojail = 0;
}

Emptycells::Emptycells(bool start, bool parking, bool jailcell, bool gotojail, char *name, int position):Cell(name , position)
{
	this->start = start;
	this->parking = parking;
	this->jailcell = jailcell;
	this->gotojail = gotojail;
}


Emptycells::~Emptycells()
{
}

void Emptycells::dummy()
{
}

bool Emptycells::getstart()
{
	return start;
}

bool Emptycells::getpark()
{
	return parking;
}

bool Emptycells::getjail()
{
	return jailcell;
}

bool Emptycells::getgojail()
{
	return gotojail;
}


