#pragma once
#include"Cell.h"
#include"Player.h"
#include<string>
using namespace std;
class Monopoly
{
	Cell**cells;
	Player**players;
	int Noofplayers;
	bool win;
	int who_win;
	
public:
	Monopoly();
	Monopoly(int);
	~Monopoly();
	void TurnTaking();
    string Checkcell(int);
	void Celloperation(int ,string);
	void Buyproperty(int,int,string);
	void Bidproperty(int,int,string);
	void Setpropertyprice(int, int, string);
	int Getpropertyrent(int,string);
	int Getpropertyprice(int, string);

	void testboard();

};

