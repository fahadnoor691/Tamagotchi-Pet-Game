#include "Bird.h"
using namespace std;

void Bird::setSinging(int s)
{
	fly = s;
}
void Bird::interaction1()  //teachsong
{
	happy += 10;
	if (happy > 100)
	{
		happy = 100;
	}

	sleep -= 10;
	hunger -= 5;
	if (sleep < 0)
	{
		sleep = 0;
	}
	if (hunger < 0)
	{
		hunger = 0;
	}
}

void Bird::interaction2()  //fly
{
	fly += 15;
	if (fly > 100)
	{
		fly = 100;
	}
	happy += 15;
	if (happy > 100)
	{
		happy = 100;
	}

	sleep -= 10;
	hunger -= 10;
	if (sleep < 0)
	{
		sleep = 0;
	}
	if (hunger < 0)
	{
		hunger = 0;
	}
}

void Bird::interaction3()  //pat bird
{
	happy += 10;
	if (happy > 100)
	{
		happy = 100;
	}
	hunger -= 10;
	if (hunger < 0)
	{
		hunger = 0;
	}
	cleanliness -= 5;
	if (cleanliness < 0)
	{
		cleanliness = 0;
	}
}

void Bird::status()
{
	Pet::status();
	cout << "| singing: " << fly << "%\t\t\t\t\t| " << endl;
	cout << "|\t    \t\t\t\t\t|" << endl;
}

void Bird::saveFile(string filename)
{
	ofstream file;
	file.open(filename, ios::app);

	Pet::saveFile(filename);
	file << fly << endl;
	file << "Bird";
}

void Bird::detail()
{
	Pet::detail();
	if (fly < 40)
	{
		cout << name << " is not able to fly." << endl;
	}
	if (sleep < 55 && sleep > 40)
	{
		cout << name << " is tired." << endl;
	}
}

string Bird::petType()
{
	return "Bird";
}

void Bird::nextHour(int time)
{
	if (time % 60 == 0)
	{
		Pet::nextHour(time);
		fly -= 5;
		if (fly < 0)
		{
			fly = 0;
		}
	}
}