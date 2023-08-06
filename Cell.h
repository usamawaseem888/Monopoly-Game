#pragma once
class Cell
{
	char*name;
	int position;
	//int xcoord;
	//int ycoord;
public:
	Cell();
	Cell(char*, int);
	virtual void dummy() = 0;
	virtual ~Cell();
	char*getname();
	int getpos();
};

