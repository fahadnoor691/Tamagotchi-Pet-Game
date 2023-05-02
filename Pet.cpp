#include "Pet.h"
using namespace std;

Pet::Pet()
{
	hunger = 75;
	sleep = 80;
	happy = 100;
	cleanliness = 100;
}

Pet::Pet(string n, int h, int s, int hp, int c)
{
	name = n;
	hunger = h;
	sleep = s;
	cleanliness = c;
	happy = hp;
}

string Pet::getname()
{
	return name;
}

int Pet::getHunger()
{
	return hunger;
}

int Pet::getSleep()
{
	return sleep;
}

int Pet::getCleanliness()
{
	return cleanliness;
}

int Pet::getHappy()
{
	return happy;
}

void Pet::setName(string n)
{
	name = n;
}

void Pet::set(int h, int s, int c, int hp)
{
	hunger = h;
	sleep = s;
	cleanliness = c;
	happy = hp;
}

//-----------------------------------------------//


void Pet::play()
{
	happy = happy + 15;
	hunger = hunger - 10;
	cleanliness = cleanliness - 10;

	if (hunger < 0)
	{
		hunger = 0;
	}
	if (happy > 100)
	{
		happy = 100;
	}
	if (cleanliness < 0)
	{
		cleanliness = 0;
	}

}

void Pet::feed()
{
	hunger = hunger + 15;
	if (hunger > 100)
	{
		hunger = 100;
	}

	cleanliness = cleanliness - 10;
	if (cleanliness < 0)
	{
		cleanliness = 0;
	}
}

void Pet::petsleep()
{
	sleep = sleep + 15;
	if (sleep > 100)
	{
		sleep = 100;
	}

	happy = happy + 10;
	if (happy > 100)
	{
		happy = 100;
	}

	hunger = hunger - 10;
	if (hunger < 0)
	{
		hunger = 0;
	}
}

void Pet::wash()
{
	cleanliness = cleanliness + 15;
	if (cleanliness > 100)
	{
		cleanliness = 100;
	}
	sleep = sleep - 5;
	if (sleep < 0)
	{
		sleep = 0;
	}
}

void Pet::nextHour(int time)
{
	if (time % 60 == 0)
	{

		hunger = hunger - 5;
		sleep = sleep - 5;
		happy = happy - 5;
		cleanliness = cleanliness - 5;

		if (hunger < 0)
		{
			hunger = 0;
		}
		if (happy < 0)
		{
			happy = 0;
		}
		if (cleanliness < 0)
		{
			cleanliness = 0;
		}
		if (sleep < 0)
		{
			sleep = 0;
		}
	}
}

//-----------------------------------------------------//

void Pet::detail()
{
	if (hunger < 40)
	{
		cout << name << " is hungry needs some food." << endl;
	}
	if (sleep < 40)
	{
		cout << name << " is feeling dozy need some nap." << endl;
	}
	if (happy < 40)
	{
		cout << name << " is unhappy" << endl;
	}
	if (cleanliness < 40)
	{
		cout << name << " is looking dirty and tired needs some shower" << endl;
	}
}

void Pet::status()
{
	cout << "| hunger: " << hunger << "%\t\tsleep: " << sleep << "%  \t\t|" << endl;
	cout << "|\t    \t\t\t\t\t|" << endl;
	cout << "| Cleanliness: " << cleanliness << " % \thappy : " << happy << " %  \t\t|" << endl;
	cout << "|\t    \t\t\t\t\t|" << endl;
}

void Pet::saveFile(string filename)
{
	ofstream file(filename);

	file << name << endl;
	file << hunger << endl;
	file << sleep << endl;
	file << happy << endl;
	file << cleanliness << endl;

}