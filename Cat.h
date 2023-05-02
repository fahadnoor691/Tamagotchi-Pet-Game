#pragma once
#include "Pet.h"

class Cat : public Pet
{
private:
	int independence;
public:
	
	Cat() :Pet()
	{
		independence = 0;
	}
	
	Cat(string n, int h, int s, int hp, int c, int l) : Pet(n, h, s, hp, c)
	{
		independence = l;
	}

	int getIndependence();

	void setindependence(int i);

	void interaction1(); //brushfur

	void interaction2(); //ignore

	void interaction3();

	void status();

	void detail();

	void saveFile(string filename);

	string petType();

	void nextHour(int time);
};
