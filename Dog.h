#pragma once
#include<iostream>
#include "Pet.h"
class Dog : public Pet
{
	int loyalty;
public:
	
	Dog() :Pet()
	{
		loyalty = 0;
		
	}

	Dog(string n, int h, int s, int hp, int c, int l) :Pet(n, h, s, hp, c)
	{
		loyalty = l;
	}

	int getLoyality();
	
	void setLoyality(int j);

	void interaction1();  //train

	void interaction2();  //walk
	
	void interaction3();  //playcatch

	void status();

	void detail();

	void saveFile(string filename);

	string petType();

	void nextHour(int time);
	
};