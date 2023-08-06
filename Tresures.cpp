#include "Tresures.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int Tresures::DrawnChests = 0;
int Tresures::DrawnChance = 0;
char** Tresures::ChanceCards = nullptr;
char** Tresures::ChestCards = nullptr;

int Tresures::rand_no()
{
	time_t t;
	srand((unsigned)time(&t));
	int num = rand() % 15;
	return num;
}

void Tresures::LoadCommunityChestFromFile()
{
	ifstream fin("CommunityChest.txt");
	ChestCards = new char*[15]; //Each pointer point to one chest card
	if (fin.is_open())
	{
		char temp[200];
		for (int i = 0; i < 15; i++)
		{
			fin.getline(temp, 200);
			int length = strlen(temp)+1;
			ChestCards[i] = new char[length];
			strcpy_s(ChestCards[i], length, temp);
			
		}
	}
	fin.close();
}

void Tresures::LoadChanceFromFile()
{
	ifstream fin("Chance.txt");
	ChanceCards = new char*[15];
	if (fin.is_open())
	{
		char temp[200];
		for (int i = 0; i < 15; i++)
		{
			fin.getline(temp, 200);
			int length = strlen(temp) + 1;
			ChanceCards[i] = new char[length];
			strcpy_s(ChanceCards[i], length, temp);
		}
	}
	fin.close();
}

Tresures::Tresures()
{
	chest = 0;
	chance = 0;
	ChestCards = nullptr;
	ChanceCards = nullptr;
}

Tresures::Tresures(bool chest, bool chance, char *name, int position , bool shuffle):Cell(name,position)
{
	this->chance = chance;
	this->chest = chest;
	if (shuffle) //This will only be called one time when first treasure object is created 
	{
		ShuffleCards();
	}

}

Tresures::~Tresures()
{
	if (ChestCards != nullptr)
	{
		for (int i = 0; i < 15; i++)
		{
			delete[] ChestCards[i];
		}
		delete[]ChestCards; 
	}
	if (ChanceCards != nullptr)
	{
		for (int i = 0; i < 15; i++)
		{
			delete[] ChanceCards[i];
		}
		delete[]ChanceCards;

	}
}

bool Tresures::getchest()
{
	return chest;
}

bool Tresures::getchance()
{
	return chance;
}

void Tresures::ShuffleCards()
{
	LoadChanceFromFile();
	LoadCommunityChestFromFile();
	for (int i = 0; i < 15; i++)
	{
		int shuffle_chest = rand_no();
		swap(ChestCards[i], ChestCards[shuffle_chest]);
		//cout << ChestCards[i] << endl;
		//cout << ChestCards[shuffle_chest] << endl;
	}
	for (int i = 0; i < 15; i++)
	{
		int shuffle_chance = rand_no();
		swap(ChanceCards[i], ChanceCards[shuffle_chance]);
	}

	//cout << ChestCards[0] << endl;
	//cout << ChanceCards[0] << endl;
}

void Tresures::ApplyChestCard(Player& p)
{
	ifstream fin("CommunityChest.txt");
	char**temp_chest = new char*[15];
	if (fin.is_open())
	{
		char temp[100];
		for (int i = 0; i < 15; i++)
		{
			fin.getline(temp, 100);
			int length = strlen(temp) + 1;
			temp_chest[i] = new char[length];
			strcpy_s(temp_chest[i], length, temp);
		}
	}
	if (strcmp(temp_chest[0], ChestCards[get_DrawnChests()]) == 0)
	{
		//Advance to Go and Collect 400 PKR
		p.Setposition(0);
		p.Setcash(p.getcash() + 400);
	}
	if (strcmp(temp_chest[1], ChestCards[get_DrawnChests()]) == 0)
	{
		//Bank will pay you 200 PKR
		p.Setcash(p.getcash() + 200);
	}
	if (strcmp(temp_chest[2], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay Doctor Fee 200 PKR
		p.Setcash(p.getcash() - 200);
	}
	if (strcmp(temp_chest[3], ChestCards[get_DrawnChests()]) == 0)
	{
		//From Sale you got 50 PKR
		p.Setcash(p.getcash() + 50);
	}
	if (strcmp(temp_chest[4], ChestCards[get_DrawnChests()]) == 0)
	{
		//Get out of Jail. May be kept until needed or sold for 500 PKR.
		p.Setjailcards(p.getjailcards() + 1);
	}
	if (strcmp(temp_chest[5], ChestCards[get_DrawnChests()]) == 0)
	{
		//Income Tax refund collect 150 PKR
		p.Setcash(p.getcash() + 150);
	}
	if (strcmp(temp_chest[6], ChestCards[get_DrawnChests()]) == 0)
	{
		//Your health insurance matures collect 200 PKR
		p.Setcash(p.getcash() + 200);
	}
	if (strcmp(temp_chest[7], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay donation to Hospital 100 PKR
		p.Setcash(p.getcash() - 100);
	}
	if (strcmp(temp_chest[8], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay Student tax of 200 PKR
		p.Setcash(p.getcash() - 200);
	}
	if (strcmp(temp_chest[9], ChestCards[get_DrawnChests()]) == 0)
	{
		//Collect 50 PKR for your services.
		p.Setcash(p.getcash() + 50);
	}
	if (strcmp(temp_chest[10], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay Street repair charges 50 PKR per House 125 PKR per Hotel.
		//How can we distinguish in property that this iss an house or hotel or shop
	}
	if (strcmp(temp_chest[11], ChestCards[get_DrawnChests()]) == 0)
	{
		//You won prize money of 300 PKR
		p.Setcash(p.getcash() + 300);
	}
	if (strcmp(temp_chest[12], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay water bill of 50 PKR
		p.Setcash(p.getcash() - 50);
	}
	if (strcmp(temp_chest[13], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay electricity bill of 80 PKR
		p.Setcash(p.getcash() - 80);
	}
	if (strcmp(temp_chest[14], ChestCards[get_DrawnChests()]) == 0)
	{
		//Pay internet bill 50 PKR
		p.Setcash(p.getcash() - 50);
	}

	int temp = get_DrawnChests();
	temp++;
	set_DrawnChests(temp);
	if (get_DrawnChests() == 15)
	{
		DrawnChests = 0;
	}
}

void Tresures::ApplyChanceCard(Player& p)
{
	ifstream fin("Chance.txt");
	char** temp_chance = new char*[15];
	if (fin.is_open())
	{
		char temp[200];
		for (int i = 0; i < 15; i++)
		{
			fin.getline(temp, 200, '\n');//chwl deafult hi \n tkk chltaaa
			int length = strlen(temp) + 1;
			temp_chance[i] = new char[length];
			strcpy_s(temp_chance[i], length, temp);
		}
	}
	fin.close();

	/*for (int i = 0; i < 15; i++)
	{
		cout << ChanceCards[i] << endl;
	}*/

	//kiya masla ?? mazar aya ? 
	//pta lg gia... shuffle cards ma masla ha..
	int drawn = get_DrawnChance();
	cout << ChanceCards[drawn] << endl;
	if (strcmp(temp_chance[0], ChanceCards[drawn]) == 0)
	{
		//Advance to Go and Collect 300 PKR
		p.Setposition(0);
		p.Setcash(p.getcash() + 300);
	}
	if (strcmp(temp_chance[1], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance to DHA Phase 1.
		p.Setposition(27);
	}
	if (strcmp(temp_chance[2], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance token to nearest utility. If unowned by from Bank. If owned, pay to owner 5X the amount shown on dice.

	}
	if (strcmp(temp_chance[3], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance token to nearest Station. If unowned by from Bank. If owned, pay to owner the double amount.

	}
	if (strcmp(temp_chance[4], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance token to nearest Station. If unowned by from Bank. If owned, pay to owner the double amount.
	}
	if (strcmp(temp_chance[5], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance to Model Town 1. If you pass Go collect 300 PKR
		if (p.getpos() > 17)
		{
			p.Setposition(17);
			p.Setcash(p.getcash() + 300);
		}
		else
		{
			p.Setposition(17);
		}
	}
	if (strcmp(temp_chance[6], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Bank pay you 100 PKR
		p.Setcash(p.getcash() + 100);
	}
	if (strcmp(temp_chance[7], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Get out of Jail. May be kept until needed or sold for 500 PKR
		p.Setjailcards(p.getjailcards() + 1);
	}
	if (strcmp(temp_chance[8], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Go back 4 blocks.
		p.Setposition(p.getpos() - 4);
	}
	if (strcmp(temp_chance[9], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Make repair on your property. For each house pay 50 PKR For each hotel pay 100 PKR

	}
	if (strcmp(temp_chance[10], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Pay small Tax of 25 PKR
		p.Setcash(p.getcash() - 25);
	}
	if (strcmp(temp_chance[11], ChanceCards[get_DrawnChance()]) == 0)
	{
		//You have been elected as chairperson. Pay 25 PKR to each player.

	}
	if (strcmp(temp_chance[12], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Collect 150 PKR from the Bank.
		p.Setcash(p.getcash() + 150);
	}
	if (strcmp(temp_chance[13], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance to Airport and not pay any Tax there.

	}
	if (strcmp(temp_chance[14], ChanceCards[get_DrawnChance()]) == 0)
	{
		//Advance token to Metro Station.
		p.Setposition(5);
	}

	int temp = get_DrawnChance();
	temp++;
	set_DrawnChance(temp);
	if (get_DrawnChance() == 15)
	{
		DrawnChance = 0;
	}


}

int Tresures::get_DrawnChests()
{
	return DrawnChests;
}

void Tresures::set_DrawnChests(int c)
{
	DrawnChests = c;
}

int Tresures::get_DrawnChance()
{
	return DrawnChance;
}

void Tresures::set_DrawnChance(int c)
{
	DrawnChance = c;
}

void Tresures::dummy()
{
}
