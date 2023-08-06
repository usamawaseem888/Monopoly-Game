#pragma once
#include"Property.h"
#include<iostream>
using namespace std;
class Player
{
	char playerSign;
	char* name;
	int cash;
	Property**properties;
	int propertycount;
	int position;
	bool jail;
	int jailcards;
	bool bankrupcy;
	//int number of non residential properties - in buy function we need
	//to check wether the bougth property is residential or non residential
	// if non residential then add in that variable.this will help in calculating rent
	//of non residential properties
public:
	Player();
	Player(int, char*,char);
	~Player();
	
	//Getters
	int getpos();
	int getcash();
	bool getjail();
	char getsign();
	int getjailcards();
	int getporpertycount();
	Property** getproperty();
	//Setters
	void Setcash(int);
	void Setpropertycount(int);
	void SetJail(bool);
	void Setjailcards(int);
	void Setposition(int);
	void Setbankrupcy(bool);
	//Functions
	void DiceRoll(int);
	void Addproperty(Cell*,string, int which_player);
	void Mortgage();
	void Redeem();

	friend ostream& operator<<(ostream& out, Player&p);
};

