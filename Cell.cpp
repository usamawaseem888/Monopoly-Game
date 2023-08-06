#include "Cell.h"
#include <iostream>
using namespace std;


Cell::Cell()
{
	name = nullptr;
	position = 0;
}

Cell::Cell(char *name, int position)
{
	if (name != nullptr)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}
	this->position = position;
}


Cell::~Cell()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

char * Cell::getname()
{
	return name;
}

int Cell::getpos()
{
	return position;
}
