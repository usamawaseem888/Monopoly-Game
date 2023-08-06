#include "Player.h"
#include <iostream>
#include"Non_Residential.h"
#include "Residential.h"
using namespace std;


Player::Player()
{
	name = nullptr;
	cash = 0;
	properties = nullptr;
	propertycount = 0;
	position = 0;
	jail = 0;
	jailcards = 0;
	bankrupcy = 0;
}

Player::Player(int cash, char *name,char sign)
{
	if (name != nullptr)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
		}
	this->cash = cash;
	properties = nullptr;
	propertycount = 0;
	position = 0;
	jail = 0;
	jailcards = 0;
	bankrupcy = 0;
	playerSign = sign;
}


Player::~Player()
{
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
	}
}

void Player::DiceRoll(int playno)
{
	srand(NULL);
	int dice = rand() % 7;
	cout << "Player-" << playno << " got:" << dice;
	position = position + dice;
	if (position > 39)
	{
		position = position - 39;
		cash = cash + 500;
	}
}

int Player::getpos()
{
	return position;
}

int Player::getcash()
{
	return cash;
}

bool Player::getjail()
{
	return jail;
}

char Player::getsign()
{
	return playerSign;
}

int Player::getjailcards()
{
	return jailcards;
}

int Player::getporpertycount()
{
	return propertycount;
}

Property ** Player::getproperty()
{
	return properties;
}

void Player::Setcash(int cash)
{
	this->cash = cash;
}

void Player::Setpropertycount(int props)
{
	propertycount = props;
}

void Player::SetJail(bool jail)
{
	this->jail = jail;
}

void Player::Setjailcards(int cards)
{
	jailcards = cards;
}

void Player::Setposition(int pos)
{
	position = pos;
}

void Player::Setbankrupcy(bool b)
{
	bankrupcy = b;
}

void Player::Addproperty(Cell *obj,string Cellname, int which_player)
{
	if (Cellname == "class Non_Residential")
	{
		Non_Residential*temp_new = dynamic_cast<Non_Residential*>(obj); //property to be added
		int index = propertycount;
		propertycount++;
		Property**temp = new Property*[propertycount];
		string property_name;
		Residential* temp_property;
		for (int i = 0; i < index; i++)
		{
			property_name = typeid(*(properties[i])).name();
			if (property_name == "class Non_Residential")
			{
				temp[i] = new Non_Residential(properties[i]->getprice(), properties[i]->getrent(), properties[i]->getowner(), properties[i]->getmortgage(), properties[i]->getname(), properties[i]->getpos());
			}
			if (property_name == "class Residential")
			{
				temp_property = dynamic_cast<Residential*>(properties[i]);
				temp[i] = new Residential(temp_property->getblock(), temp_property->gethouse(), temp_property->getpayrent(), temp_property->getshops(), temp_property->gethotel(), temp_property->getgas(), temp_property->getwifi(), temp_property->getelectricity(), temp_property->getprice(), temp_property->getrent(), temp_property->getowner(), temp_property->getmortgage(), temp_property->getname(), temp_property->getpos());
			}
		}
		temp[index] = new Non_Residential(temp_new->getprice(), temp_new->getrent(), temp_new->getowner(), temp_new->getmortgage(), temp_new->getname(), temp_new->getpos());
		temp_new[index].Setowner(which_player);
		delete[]properties;
		properties = temp;
		temp = nullptr;
	}
	else if (Cellname == "class Residential")
	{
		Residential*temp_new = dynamic_cast<Residential*>(obj); //property to be added
		int index = propertycount;
		propertycount++;
		Property** temp = new Property*[propertycount];
		Residential* temp_property;
		string property_name;
		for (int i = 0; i < propertycount - 1; i++)
		{
			property_name = typeid(*(properties[i])).name();
			if (property_name == "class Non_Residential")
			{
				temp[i] = new Non_Residential(properties[i]->getprice(), properties[i]->getrent(), properties[i]->getowner(), properties[i]->getmortgage(), properties[i]->getname(), properties[i]->getpos());
			}
			if (property_name == "class Residential")
			{
				temp_property = dynamic_cast<Residential*>(properties[i]);
				temp[i] = new Residential(temp_property->getblock(), temp_property->gethouse(), temp_property->getpayrent(), temp_property->getshops(), temp_property->gethotel(), temp_property->getgas(), temp_property->getwifi(), temp_property->getelectricity(), temp_property->getprice(), temp_property->getrent(), temp_property->getowner(), temp_property->getmortgage(), temp_property->getname(), temp_property->getpos());
			}
		}
		temp[index] = new Residential(temp_new->getblock() , temp_new->gethouse(), temp_new->getpayrent(), temp_new->getshops(), temp_new->gethotel(), temp_new->getgas(), temp_new->getwifi(), temp_new->getelectricity(), temp_new->getprice(), temp_new->getrent(), temp_new->getowner(), temp_new->getmortgage(), temp_new->getname(), temp_new->getpos());
		temp_new[index].Setowner(which_player);
		delete[] properties;
		properties = temp;
		temp = nullptr;
	}
}

void Player::Mortgage()
{
	//make price calculator of property
	//can only mortgage which is owned
	if (propertycount != 0)
	{
		cout << "Which property you want to mortgage ? " << endl;
		for (int i = 0; i < propertycount; i++)
		{
			cout << i + 1 << ". " << properties[i]->getname() << endl;
		}
		int which_property = 0;
		cin >> which_property;
		properties[which_property - 1]->Setmortgage(1);
		//when mortgage half price will be given even with houses

		string name = typeid(*(properties[which_property - 1])).name();

		if (name == "class Residential")
		{
			Residential* temp = dynamic_cast<Residential*>(properties[which_property - 1]);
			//cash = cash + (temp->getpayrent() / 2); //in constuctor getrent is not wotking
			if (temp->gethouse() != 0)
			{
				cash = cash + (temp->getpayrent() / 2);
			}
			if (temp->gethouse() == 0)
			{
				cash = cash + (temp->getprice() / 2);
			}

		}
		if (name == "class Non_Residential")
		{
			Non_Residential* temp = dynamic_cast<Non_Residential*>(properties[which_property - 1]);
			//cash = cash + (temp->getpayrent() / 2);
		}
	}
	else
	{
		cout << "Does not have property to mortgage " << endl;
	}
	
	//if the selected property is residential then call that get payrent
	//if the selected property is non residential call that get payrent
 
}

void Player::Redeem()
{
	cout << "Which property you want to redeem ? " << endl;
	int num = 0;
	

	//int deduct = 0;
	//for (int i = 0; i < propertycount; i++)
	//{
	//	if ()
	//	{
			for (int i = 0; i < propertycount; i++)
			{
				
					int half = properties[i]->getprice() / 2;
					int redeem_amount = (half)+((half / 100) * 20);
					if (properties[i]->getmortgage() == true && cash > redeem_amount)
					{
						cout << num + 1 << ". " << properties[i]->getname() << endl;
						num++;
					}
					else
					{
						cout << "Not enough redeem amount this property" << endl;
					}
				
				

			}
			int which_property = 0;
			cin >> which_property;

			properties[which_property - 1]->Setmortgage(0);
			cash = cash - ((properties[which_property - 1]->getprice() / 2) + ((properties[which_property - 1]->getprice() / 100) * 20));
		}
	//}
	
	/*else
	{
		cout << "Does not have property to redeem!! " << endl;
	}*/
	
	//redeem with 20% interest
	


ostream & operator<<(ostream & out,  Player & p)
{
	cout << "Player name: " << p.name << endl;
	cout << "CASH: " << p.cash << endl;
	if (p.propertycount == 0)
	{
		cout << "No. of properties " << p.propertycount << endl;
	}
	else
	{
		for (int i = 0; i < p.getporpertycount(); i++)
		{
			if (p.properties[i]->getmortgage() == false)
			{
				cout << "No. of properties " << p.propertycount << endl;
			}
		}

	}
	
	cout << "No. of Jail cards " << p.getjailcards() << endl;
	return out;

}
