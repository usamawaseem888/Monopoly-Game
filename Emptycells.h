#pragma once
#include "Cell.h"
class Emptycells :	public Cell
{
	bool start;
	bool parking;
	bool jailcell;
	bool gotojail;
public:
	Emptycells();
	Emptycells(bool, bool, bool, bool, char*, int);
	~Emptycells();
	void dummy();
	bool getstart();
	bool getpark();
	bool getjail();
	bool getgojail();
};

