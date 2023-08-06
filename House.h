
#pragma once
using namespace std;
class House
{
	//Utilities
	bool gas;
	bool wifi;
	bool electricity;
public:
	House();
	House(bool, bool, bool);
	bool getGas();
	bool getwifi();
	bool getelectricity();
	void Setgas(bool);
	void Setwifi(bool);
	void Setelec(bool);





};
