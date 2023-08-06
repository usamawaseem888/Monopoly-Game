#include "Monopoly.h"
#include"Cell.h"
#include "Emptycells.h"
#include "Property.h"
#include "Tresures.h"
#include <string>
#include "Tax_places.h"
#include "Non_Residential.h"
#include "Residential.h"
#include <iostream>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Monopoly::Monopoly()
{
	cells = nullptr;
	players = nullptr;
	win = 0;
	who_win = 0;
	
}

Monopoly::Monopoly(int playerCount)
{
	Noofplayers = playerCount;
	//First initialize 40 cells
	//then make plyers according to number of players
	win = 0;
	who_win = 0;
	
	cells = new Cell*[40];

	//cells = new Cell*[40];
	//char block, int house, int shops, bool hotel, bool gas, bool wifi, bool electricity, int price, int rent, int owner, bool mortgaged, char*name, int position)
	cells[0] = new Emptycells(1, 0, 0, 0, "Start", 0); //start
	cells[1] = new Tresures(1, 0, "Chest", 1, 1); //chest
	cells[2] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 200, 60, -1, 0, "Johar town", 2);//JOhar town A
	cells[3] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 250, 90, -1, 0, "Johar town", 3);//JOhar town B
	cells[4] = new Non_Residential(2500, 350, -1, 0,"SUI", 4); //SUI
	cells[5] = new Non_Residential(2000, 200, -1, 0,"Metro Station", 5); //station
	cells[6] = new Tresures(0, 1, "Chance", 6, 0); //chance
	cells[7] = new Residential('A', 0, 0,0, 0, 0, 0, 0, 250, 60, -1, 0, "Iqbal town", 7); //Iqbal town A 
	cells[8] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 300, 70, -1, 0, "Iqbal town", 8);//Iqbal town B
	cells[9] = new Residential('C', 0, 0, 0, 0, 0, 0, 0, 400, 100, -1, 0, "Iqbal town", 9);//Iqbal town C
	cells[10] = new Emptycells(0, 0, 1, 0, "Jail", 10); //jail
	cells[11] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 300, 100, -1, 0, "Faisal town", 11); //Faisal town A
	cells[12] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 400, 130, -1, 0, "Faisal town", 12); //Faisal town B
	cells[13] = new Residential('C', 0, 0, 0, 0, 0, 0, 0, 400, 130, -1, 0, "Faisal town", 13); //Faisal town C
	cells[14] = new Non_Residential(4000, 400, -1, 0,"WASA", 14); // WASA
	cells[15] = new Non_Residential(2000, 200, -1, 0,"Bus Station", 15); //station
	cells[16] = new Tresures(1, 0, "Chest", 16, 0); //chest
	cells[17] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 800, 200, -1, 0, "Model town", 17); //Model Town A
	cells[18] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 850, 250, -1, 0, "Model town", 18); //Model Town B
	cells[19] = new Residential('C', 0, 0, 0, 0, 0, 0, 0, 2000, 500, -1, 0, "Model town", 19); //Model Town C
	cells[20] = new Emptycells(0, 1, 0, 0, "Parking", 20); //parking
	cells[21] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 1000, 300, -1, 0, "Gulberg", 21); //Gulberg A
	cells[22] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 1200, 350, -1, 0, "Gulberg", 22); //Gulberg B
	cells[23] = new Residential('c', 0, 0, 0, 0, 0, 0, 0, 2500, 600, -1, 0, "Gulberg", 23); //Gulberg C
	cells[24] = new Tresures(0, 1, "Chance", 24, 0); //chance
	cells[25] = new Non_Residential(2500, 350, -1, 0, "Railway Station", 25); //station
	cells[26] = new Non_Residential(5000, 450, -1, 0, "LESCO", 26); // LESCO
	cells[27] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 2000, 500, -1, 0, "DHA", 27); //DHA A
	cells[28] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 2000, 500, -1, 0, "DHA", 28); //DHA B
	cells[29] = new Residential('C', 0, 0, 0, 0, 0, 0, 0, 2000, 1000, -1, 0, "DHA", 29); //DHA C
	cells[30] = new Emptycells(0, 0, 0, 1, "GOTOJAIL", 30); //Go To Jail
	cells[31] = new Tax_places(0, "Land Tax", 31); //Land Tax
	cells[32] = new Residential('A', 0, 0, 0, 0, 0, 0, 0, 2500, 800, -1, 0, "Bahria town", 32); //Bahria Town A
	cells[33] = new Residential('B', 0, 0, 0, 0, 0, 0, 0, 3000, 900, -1, 0, "Bahria town", 33); //Bahria Town B
	cells[34] = new Residential('C', 0, 0, 0, 0, 0, 0, 0, 3000, 1000, -1, 0, "Bahria town", 34); //Bahria Town C
	cells[35] = new Non_Residential(2500, 350, -1, 0, "Orange Train", 35); //station
	cells[36] = new Tresures(0, 1, "Chance", 36, 0); //chance
	cells[37] = new Non_Residential(8000, 500, -1, 0, "PTCL", 37); // PTCL
	cells[38] = new Tresures(1, 0, "Chest", 38, 0); //chest
	cells[39] = new Tax_places(0, "Parking Tax", 39); //Parking Tax

	players = new Player*[Noofplayers];
	cout << "Enter Initial Cash Amount " << endl; //All players have same
	int cash = 0;
	cin >> cash;
	cin.ignore();
	char temp[50];
	for (int i = 0; i < Noofplayers; i++)
	{
		cout << "Enter the name of player " << i + 1 << endl;
		cin.getline(temp, 50);
		players[i] = new Player(cash, temp,65+i);
	}

}

Monopoly::~Monopoly()
{
	if (cells != nullptr)
	{
		delete[] cells;
		cells = nullptr;
	}
	if (players != nullptr)
	{
		delete[] players;
		players = nullptr;
	}
}

void Monopoly::TurnTaking()
{
	for (int i = 0; i < Noofplayers; i++)
	{
		//Print dummy game
		gotoxy(0, 10);
		testboard();
		gotoxy(0, 0);
		char ch = '\n';
		while (ch != 't')
		{
			if (true)
			{
				//ch = _getch();
				cin >> ch;
				if (ch == 't')
				{
					//DiceRoll
					players[i]->DiceRoll(i);//rolls dice and update postion also adds starting cash
				}
			}
		}

		//Print dummy game
		gotoxy(0, 10);
		testboard();
		gotoxy(0, 0);

		//Cell checking
		string Cellname = Checkcell(i);

		//Cell operation
		Celloperation(i, Cellname);
		gotoxy(0, 40);
		for (int i = 0; i < Noofplayers; i++)
		{
			cout << players[i][0] << endl;
		}

		cout << "You want to mortgage ? " << endl;
		if (true)
		{
			cout << "You want to Redeem ? " << endl;
		}
		
		cin >> ch;
		if (ch == 'm')
		{
			players[i]->Mortgage();
		}
		if (ch == 'r')
		{
			players[i]->Redeem();
		}


		//cout << players[0][0] << endl;
		//players[0]->getporpertycount() > 0 || players[1]->getporpertycount() > 0a
		if (players[i]->getcash() < 0)
		{
			//give option to declare bankrupcy  OR
	 		//give option to mortgage

			//the option of mortgage is also available to player at any time
			//the option of upgrade is also available to player at any time
			
			cout << "1. Declare bankrupcy " << endl;
			cout << "2. Mortgage " << endl;
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				players[i]->Setbankrupcy(1);
			}
			if (select == 2)
			{
				players[i]->Mortgage();
			}

		}

		system("pause");
		system("cls");
      //buy the property does not checking already owned property
	}
}

string Monopoly::Checkcell(int Playerno)
{
	int index = players[Playerno]->getpos();
	string name = typeid(*(cells[index])).name();
	return name;
}

void Monopoly::Celloperation(int Playerno, string Cellname)
{
	int index = players[Playerno]->getpos();

	//For empty Cells
	if (Cellname == "class Emptycells")
	{
		Emptycells*temp = dynamic_cast<Emptycells*>(cells[index]);
		if (temp->getstart() == true)
		{
			//do nothing
		}
		else if (temp->getpark() == true)
		{
			//pakring tax will be added if any
		}
		else if (temp->getjail() == true)
		{
			//do nothing
		}
		else if (temp->getgojail() == true)
		{
			//rent will not be charged from properties
			//remain in jail at position 10 untill give 100$
			//if plenty was not given then get out of jail after 3 turns
			//get out of jail if player has jail card
			players[Playerno]->SetJail(true);
			players[Playerno]->Setposition(10);
		}
	}

	//For Tresures
	else if (Cellname == "class Tresures")
	{
		Tresures*temp = dynamic_cast<Tresures*>(cells[index]);
		if (temp->getchest() == true)
		{
			temp->ApplyChestCard(players[Playerno][0]);
			//GetchestCard();
			//Then apply changes like reduction of rent if any etc
		}
		else if (temp->getchance() == true)
		{
			temp->ApplyChanceCard(players[Playerno][0]);
			//GetchanceCard();
		}
	}

	//For Properties
	//1:Non-Residential
	if (Cellname == "class Non_Residential")
	{
		Non_Residential*temp = dynamic_cast<Non_Residential*>(cells[index]);
		//Unowned case
		if (temp->getowner() == -1)
		{
			//Give option to buy
			cout << "Buy(1) or Bid(2)";
			//_getch();
			if (true)
			{
				//char ch = _getch();
				char ch = '\0';
				cin >> ch;
				if (players[Playerno]->getcash() >= Getpropertyprice(index, Cellname) && temp->getowner() == -1)
				{
					if (ch == 'b')
					{
						//Buy Function call

						Buyproperty(Playerno, index, Cellname);
					}
					else
					{
						Bidproperty(Playerno, index, Cellname);
					}
				}
				else if (ch == 'n')
				{
					//Bid Function call
					Bidproperty(Playerno, index, Cellname);
				}
			}
		}
		else if (temp->getowner() != Playerno)
		{
			if (players[temp->getowner()]->getjail() == false && temp->getmortgage() == false)
			{
				//Rent deduction
				int cash = players[Playerno]->getcash() - Getpropertyrent(index, Cellname);
				players[Playerno]->Setcash(cash);
				cout << "Rent taken:" << Getpropertyrent(index, Cellname);
				_getch();
			}
		}
	}
		//2:Residential
		if (Cellname == "class Residential")
		{
			Residential*temp = dynamic_cast<Residential*>(cells[index]);
			//Unowned case
			if (temp->getowner() == -1)
			{
				//Give option to buy
				cout << "Buy(1) or Bid(2)";
				//_getch();
				if (true)
				{
					char ch = '\0';
					cin >> ch;
					if (players[Playerno]->getcash() >= Getpropertyprice(index, Cellname) && temp->getowner() == -1)
					{
						if (ch == 'b')
						{
							//what if player have not cashed - then it should go for bidding
							// but it is skipping that ?
							//Buy Function call
							Buyproperty(Playerno, index, Cellname);
						}
				    }
					if (ch == 'n')
					{
						//Bid Function call
						Bidproperty(Playerno, index, Cellname);
					}
				}
			}
			else if (temp->getowner() != Playerno)
			{
				if (players[temp->getowner()]->getjail() == false && temp->getmortgage() == false)
				{
					//Rent deduction
					int cash = players[Playerno]->getcash() - Getpropertyrent(index, Cellname);
					players[Playerno]->Setcash(cash);
					cout << "Rent taken:" << Getpropertyrent(index, Cellname);
				}
			}
        }
}

int Monopoly::Getpropertyrent(int index, string Cellname)
{
	int rent = 0;
	if (Cellname == "class Non_Residential")
	{
		Non_Residential*temp = dynamic_cast<Non_Residential*>(cells[index]);
		rent = temp->getrent();
	}
	else if (Cellname == "class Residential")
	{
		Residential*temp = dynamic_cast<Residential*>(cells[index]);
		rent = temp->getrent();
	}
	return rent;
}

int Monopoly::Getpropertyprice(int index, string Cellname)
{
	int price=0;
	if (Cellname == "class Non_Residential")
	{
		Non_Residential*temp = dynamic_cast<Non_Residential*>(cells[index]);
		price = temp->getprice();
	}
	else if (Cellname == "class Residential")
	{
		Residential*temp = dynamic_cast<Residential*>(cells[index]);
		price = temp->getprice();
	}
	return price;
}

void Monopoly::testboard()
{
	////int*board = new int[40];
	//int i, j;
	//for (i = 0; i < 10; i++)
	//{
	//	// Print stars for each solid rows 
	//	if (i == 0 || i == 9)
	//	{
			for (int i = 0; i < 40; i++)
			{
				cout << "| ";
				for (int k = 0; k < Noofplayers; k++)
				{
					if (i == players[k]->getpos())
						cout << players[k]->getsign();
					else
						cout << " ";
				}
				cout << " |";
				if (i == 19)
					cout << endl;
			}
		//}
		//// stars for hollow rows 
		//else
		//{
		//	for (j = 0; j < 10; j++)
		//	{
		//		if (j == 0 || j == 9)
		//		{
		//			cout << "| ";
		//			for (int k = 0; k < Noofplayers; k++)
		//			{
		//				if (i + j == players[k]->getpos())
		//					cout << players[k]->getsign();
		//				else
		//					cout << " ";
		//			}
		//			cout << " |";
		//		}
		//		else
		//		{
		//			cout << "  ";
		//			for (int k = 0; k < Noofplayers; k++)
		//				cout << " ";
		//			cout << "  ";
		//		}
		//	}
		//	// Move to the next line/row 
		//	
		//}
		//cout << "\n";
}

void Monopoly::Setpropertyprice(int p,int index, string Cellname)
{
	if (Cellname == "class Non_Residential")
	{
		Non_Residential*temp = dynamic_cast<Non_Residential*>(cells[index]);
		temp->Setprice(p);
	}
	else if (Cellname == "class Residential")
	{
		Residential*temp = dynamic_cast<Residential*>(cells[index]);
		temp->Setprice(p);
	}
}

void Monopoly::Buyproperty(int Playerno,int index,string Cellname)
{
	int newCash=0;
	Non_Residential*temp1 = dynamic_cast<Non_Residential*>(cells[index]);
	Residential*temp2 = dynamic_cast<Residential*>(cells[index]);

		if (Cellname == "class Non_Residential")
		{
			
			newCash = players[Playerno]->getcash() - temp1->getprice();
		}
		else if (Cellname == "class Residential")
		{
			
			newCash = players[Playerno]->getcash() - temp2->getprice();
		}

		//Money deducted
		players[Playerno]->Setcash(newCash);

		//Add Property in player
		players[Playerno]->Addproperty(cells[index], Cellname, Playerno);

		cout << "Property Bought!!!\n";

	
}

void Monopoly::Bidproperty(int playerNo, int index, string Cellname)
{
	int p = playerNo;
	int totalplayers=Noofplayers;
	int bid = 0;
	int lastbid = 0;
	int*playarr = new int[totalplayers];
	int*playbids = new int[totalplayers];
	bool flag = false;
	//Array of players
	for (int i = 0; i < totalplayers; i++)
	{
		playbids[i] = 0;
		playarr[i] = p;
		p++;
		if (p > totalplayers - 1)
			p = 0;
	}
	int i = 0;
	while(i<totalplayers)
	{
		_getch();
		if (_kbhit() )
		{
			char ch = _getch();
			if (ch == 'n')
			{
				if (lastbid < players[playarr[i]]->getcash())
				{
					while (bid<playbids[i] || bid> players[playarr[i]]->getcash())
					{
						cout << "Enter bid Value" << "(" << lastbid + 1 << "-" << players[i]->getcash() << "):";
						cin >> bid;
					}
					playbids[i] = bid;
					lastbid = bid;
				}
				else
					cout << "Not available:(\n";
				flag = false;
			}
			else if (ch == 'm')
			{
				if(playarr[i]==playerNo)
				{
				//Call Mortgage func
					flag = true;
				
				}
				else
					cout << "Not available:(\n";
		   }
			else if (ch == 'f')
			{
				//removal of player from bid
				for (int j = i; j < totalplayers; j++)
					playarr[j] = playarr[j + 1];
				totalplayers--;
				//deep copy in new array
				int*temp = new int[totalplayers];
				for (int j = 0; j < totalplayers; j++)
					temp[j] = playarr[j];
				delete[]playarr;
				playarr = temp;
				temp = nullptr;

				//removal of bid value of player
				for (int j = i; j < totalplayers + 1; j++)
					playbids[j] = playbids[j + 1];
				//deep copy to new array
				temp = new int[totalplayers];
				for (int j = 0; j < totalplayers; j++)
					temp[j] = playbids[j];
				delete[]playbids;
				playbids = temp;
				temp = nullptr;
				flag = false;
			}
			if (flag == false)
				i++;
			if (i >= totalplayers)
				i = 0;
			if (totalplayers == 1)
				break;
		}
		//Last player remaining will get the property
		Setpropertyprice(playbids[0], index, Cellname);
		Buyproperty(playarr[0], index, Cellname);
		cout << "Property Auctioned!!! to player:" << playarr[0];
		}
}

