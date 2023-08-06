#pragma once
#include "Cell.h"
class Tax_places : public Cell
{
	int tax;
public:
	Tax_places();
	Tax_places(int, char*, int);
	~Tax_places();
	void dummy();
};

