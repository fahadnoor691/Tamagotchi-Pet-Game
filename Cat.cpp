#include "Cat.h"
using namespace std;

int Cat::getIndependence()
{
	return independence;
}

void Cat::setindependence(int i)
{
	independence = i;
}

void Cat::interaction1() //brushfur
{
	happy = happy + 15;
	if (happy > 100)
	{
		happy = 100;
	}
	independence -= 10;
	if (independence < 0)
	{
		independence = 0;
	}
}

void Cat::interaction2() //ignore
{
	happy -= 10;
	independence += 15;
	if (independence > 100)
	{
		independence = 100;
	}
	if (happy < 0)
	{
		happy = 0;
	}
}

void Cat::interaction3()
{
	happy += 10;
	independence -= 10;
	if (happy > 100)
	{
		happy = 100;
	}
	if (independence < 0)
	{
		independence = 0;
	}
}

void Cat::status()
{
	Pet::status();
	cout << "| Independence: " << independence << "%\t\t\t\t| " << endl;
	cout << "|\t    \t\t\t\t\t|" << endl;
}

void Cat::detail()
{
	Pet::detail();
	if (independence < 40)
	{
		cout << name << " needs to be more independent." << endl;
	}
}

void Cat::saveFile(string filename)
{
	ofstream file;
	file.open(filename, ios::app);

	Pet::saveFile(filename);
	file << independence << endl;
	file << "Cat";
}

string Cat::petType()
{
	return "Cat";
}

void Cat::nextHour(int time)
{
	if (time % 60 == 0)
	{
		Pet::nextHour(time);
		independence -= 5;
		if (independence < 0)
		{
			independence = 0;
		}
	}
}