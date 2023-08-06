#include "Tax_places.h"
#include <iostream>
using namespace std;


Tax_places::Tax_places()
{
	tax = 0;
}

Tax_places::Tax_places(int tax, char *name, int pos):Cell(name ,pos)
{
	this->tax = tax;
}


Tax_places::~Tax_places()
{
}

void Tax_places::dummy()
{

}
