#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Pet.h"
#include "Bird.h"
#include"Cat.h"
#include "Dog.h"
using namespace std;

Pet* createPet()
{
	int choice = 1;
	int* var = new int;


	Pet* pet;
	while (choice == 1 || choice == 2 || choice == 3)
	{
		cout << endl << endl;
		cout << "1. Cat" << endl;
		cout << "2. Dog" << endl;
		cout << "3. Bird" << endl << endl;

		cout << "Choose Pet Type : ";
		cin >> choice;
		if (choice == 1)
		{
			pet = new Cat();
			return pet;
		}
		else if (choice == 2)
		{
			pet = new Dog();
			return pet;
		}
		else if (choice == 3)
		{
			pet = new Bird();
			return pet;
		}
		else
		{
			cout << "Enter valid choice" << endl;
		}

	}
}
bool checkFile(string filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Failed to open up a file." << endl;
		return false;
	}
	return true;
}

Pet* loadPet(string filename)
{

	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Failed to open up a file." << endl;
	}

	string name;

	string petType;
	int hunger, sleep, clean, happy, loy;

	file >> name;
	file >> hunger >> sleep >> happy >> clean >> loy;
	file >> petType;

	Pet* pet;

	if (petType == "Cat")
	{
		pet = new Cat(name, hunger, sleep, happy, clean, loy);
	}
	else if (petType == "Dog")
	{
		pet = new Dog(name, hunger, sleep, happy, clean, loy);
	}
	else
	{
		pet = new Bird(name, hunger, sleep, happy, clean, loy);
	}

	//pet->set(hunger, sleep, bored, happy);

	return pet;
}

void dogMenu(Pet* pet)
{
	cout << endl << endl;
	cout << "1. Feed " << pet->getname() << endl;
	cout << "2. Sleep " << pet->getname() << endl;
	cout << "3. Play " << pet->getname() << endl;
	cout << "4. Bath " << pet->getname() << endl;
	cout << "5. Train " << pet->getname() << endl;
	cout << "6. Walk " << pet->getname() << endl;
	cout << "7. Play Catch " << pet->getname() << endl;
	cout << "8. Save " << endl;
	cout << "9. Exit" << endl;
	cout << endl << endl;
}

void catMenu(Pet* pet)
{
	cout << endl << endl;
	cout << "1. Feed " << pet->getname() << endl;
	cout << "2. Sleep " << pet->getname() << endl;
	cout << "3. Play " << pet->getname() << endl;
	cout << "4. Bath " << pet->getname() << endl;
	cout << "5. Brush Fur " << pet->getname() << endl;
	cout << "6. Ignore " << pet->getname() << endl;
	cout << "7. Cuddle " << pet->getname() << endl;
	cout << "8. Save" << endl;
	cout << "9. Exit" << endl;
	cout << endl << endl;
}

void birdMenu(Pet* pet)
{
	cout << endl << endl;
	cout << "1. Feed " << pet->getname() << endl;
	cout << "2. Sleep " << pet->getname() << endl;
	cout << "3. Play " << pet->getname() << endl;
	cout << "4. Bath " << pet->getname() << endl;
	cout << "5. Teach Song " << pet->getname() << endl;
	cout << "6. Fly " << pet->getname() << endl;
	cout << "7. Pat " << pet->getname() << endl;
	cout << "8. Save" << endl;
	cout << "9. Exit" << endl;
	cout << endl << endl;
}

void gameLoop()
{

	int choice = 0;

	cout << "**********************************************************************************" << endl << endl;
	cout << "                          Welcome to Virtual Pet Game" << endl << endl;
	cout << "**********************************************************************************" << endl << endl;

	cout << "\t1. Create new pet" << endl;
	cout << "\t2. Load a pet" << endl;
	cout << "\t3. Exit" << endl << endl << endl;

	Pet* pet;
	while (choice != 3)
	{
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			pet = createPet();
			string name;
			cout << "Enter nickname for your new pet: ";
			cin >> name;
			pet->setName(name);
			system("cls");

			//cout << endl << endl;
			cout << "*********************************** Virtual Pet Game ***********************************" << endl << endl;

			cout << "\t\t\t\t" << name << " is your new pet" << endl << endl << endl;
			int menuchoice = 0;
			int time = 0;
			while (menuchoice != 9)
			{
				//cout << "*********************************** Virtual Pet Game ***********************************" << endl << endl;

				pet->status();

				if (pet->petType() == "Dog")
				{
					dogMenu(pet);
				}
				else if (pet->petType() == "Cat")
				{
					catMenu(pet);
				}
				else
				{
					birdMenu(pet);
				}

				cout << "Enter Choice: ";
				cin >> menuchoice;
				if (menuchoice == 1)
				{
					pet->feed();
				}
				else if (menuchoice == 2)
				{
					pet->petsleep();
				}
				else if (menuchoice == 3)
				{
					pet->play();
				}
				else if (menuchoice == 4)
				{
					pet->wash();
				}
				else if (menuchoice == 5)
				{
					pet->interaction1();
				}
				else if (menuchoice == 6)
				{
					pet->interaction2();
				}
				else if (menuchoice == 7)
				{
					pet->interaction3();
				}
				else if (menuchoice == 8)
				{
					string name;
					cout << endl;
					cout << "Enter File Name: " << endl;
					cin >> name;
					pet->saveFile(name);
				}
				else if (menuchoice == 9)
				{
					return;
				}
				else
				{
					cout << "Enter valid choice" << endl;
				}
				time += 10;
				pet->nextHour(time);

				system("cls");
				cout << "\t\t\t\Time: " << time << " minutes" << endl << endl;
				pet->detail();

			}
		}


		else if (choice == 2)
		{
			int time = 0;
			cout << "Enter file name: ";
			string filename;
			cin >> filename;
			if (!checkFile(filename))
			{
				return;
			}
			pet = loadPet(filename);

			int menuchoice = 0;
			while (menuchoice != 8)
			{
				//cout << "*********************************** Virtual Pet Game ***********************************" << endl << endl;

				pet->status();

				if (pet->petType() == "Dog")
				{
					dogMenu(pet);
				}
				else if (pet->petType() == "Cat")
				{
					catMenu(pet);
				}
				else
				{
					birdMenu(pet);
				}

				cout << "Enter CHoice: ";
				cin >> menuchoice;
				if (menuchoice == 1)
				{
					pet->feed();
				}
				else if (menuchoice == 2)
				{
					pet->petsleep();
				}
				else if (menuchoice == 3)
				{
					pet->play();
				}
				else if (menuchoice == 4)
				{
					pet->wash();
				}
				else if (menuchoice == 5)
				{
					pet->interaction1();
				}
				else if (menuchoice == 6)
				{
					pet->interaction2();
				}
				else if (menuchoice == 7)
				{
					pet->interaction3();
				}
				else if (menuchoice == 8)
				{
					pet->saveFile(filename);
				}
				else if (menuchoice == 9)
				{
					return;
				}
				else
				{
					cout << "Enter valid choice" << endl;
				}

				time += 10;
				pet->nextHour(time);

				system("cls");
				cout << "\t\t\t\Time: " << time << " minutes" << endl << endl;
				pet->detail();
			}
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			cout << "Enter valid choice" << endl;
		}
	}

}

int main()
{
	gameLoop();
}