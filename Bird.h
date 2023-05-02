#pragma once
#include "Pet.h"
class Bird : public Pet
{
private:
	int fly;
public:
	
	Bird() :Pet()
	{
		fly = 0;
	}

	Bird(string n, int h, int s, int hp, int c, int sing) :Pet(n, h, s, hp, c)
	{
		fly = sing;
	}

	void setSinging(int s);

	void interaction1();  //teachsong

	void interaction2();  //fly

	void interaction3();  //pat bird

	void status();

	void saveFile(string filename);

	void detail();

	string petType();

	void nextHour(int time);
};
