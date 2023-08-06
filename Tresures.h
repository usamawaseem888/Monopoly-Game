#pragma once
#include "Cell.h"
#include<shlobj.h>
#include "Player.h"

class Tresures : public Cell
{
	bool chest;
	bool chance;
	static char** ChestCards;
	static char** ChanceCards;
	int rand_no();
	void LoadCommunityChestFromFile();
	void LoadChanceFromFile();
	static int DrawnChance;
	static int DrawnChests; //this will help in counting how many cards have drawn and displaying which card is drawn
public:
	Tresures();
	Tresures(bool, bool, char*, int , bool shuffle);
	~Tresures();
	bool getchest();
	bool getchance();
	void ShuffleCards(); //this function is called at the beginning of game to shuffle all cards from file
	//int DrawChest();
	//int DrawChance();
	void ApplyChestCard(Player& );
	void ApplyChanceCard(Player& );
	//static void Add_DrawnCards(); May be needed later
	static int get_DrawnChests();
	static void set_DrawnChests(int);
	static int get_DrawnChance();
	static void set_DrawnChance(int);
	void dummy();
};

