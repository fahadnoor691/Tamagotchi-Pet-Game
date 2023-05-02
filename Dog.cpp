#include "Dog.h"
using namespace std;

int Dog::getLoyality()
{
	return loyalty;
}

void Dog::setLoyality(int j)
{
	loyalty = j;
}


void Dog::interaction1()  //train
{
	loyalty = loyalty + 15;
	if (loyalty > 100)
	{
		loyalty = 100;
	}

	hunger -= 10;
	if (hunger < 0)
	{
		hunger = 0;
	}
}

void Dog::interaction2()  //walk
{
	loyalty = loyalty + 10;
	if (loyalty > 100)
	{
		loyalty = 100;
	}

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
}

void Dog::interaction3()  //playcatch
{
	happy = happy + 15;
	if (happy > 100)
	{
		happy = 100;
	}

	hunger -= 10;
	if (hunger < 0)
	{
		hunger = 0;
	}

	sleep -= 10;
	if (sleep < 0)
	{
		sleep = 0;
	}
}

void Dog::status()
{
	Pet::status();
	cout << "| Loyality: " << loyalty << "%\t\t\t\t\t| " << endl;
	cout << "|\t    \t\t\t\t\t|" << endl;
}

void Dog::detail()
{
	Pet::detail();
	if (loyalty < 40)
	{
		cout << name << " is less loyal to you try to go for a walk or train " << name << endl;
	}

}

void Dog::saveFile(string filename)
{
	ofstream file(filename, ios::app);

	if (file.is_open()) {
		Pet::saveFile(filename);
		file << loyalty << endl;
		file << "Dog" << endl;
	}
	else {
		cout << "Failed to open file." << endl;
	}
}

string Dog::petType()
{
	return "Dog";
}

void Dog::nextHour(int time)
{
	if (time % 60 == 0)
	{
		Pet::nextHour(time);
		loyalty -= 5;
		if (loyalty < 0)
		{
			loyalty = 0;
		}
	}
}