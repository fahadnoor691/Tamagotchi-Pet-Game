#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Pet
{
public:
	string name;
	int hunger;
	int sleep;
	int happy;
	int cleanliness;

public:
	
	Pet();
	
	Pet(string n, int h, int s, int hp, int c);

	string getname();
	
	int getHunger();
	
	int getSleep();
	
	int getCleanliness();
	
	int getHappy();
	
	void setName(string n);
	
	void set(int h, int s, int c, int hp);

	void play();

	void feed();

	void petsleep();
	
	void wash();

	virtual void nextHour(int time);

	virtual void detail();

	virtual void status();
	
	virtual void saveFile(string filename);
	
	virtual string petType() = 0;
	virtual void interaction1() = 0;
	virtual void interaction2() = 0;
	virtual void interaction3() = 0;
};