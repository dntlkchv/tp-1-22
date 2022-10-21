#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Keeper {
public:
	
	void showListOfHeroes();
	Keeper& operator += (Base* hero);
	void removeHero(int ID);
	void saveHero();
	void loadHero();
	bool isEmpty();
	~Keeper();
	
	Base** listOfHeroes;
	int getSize();

	Keeper() {
		listOfHeroes = new Base*[0];
	};

private:
	int size = 0;
	
};
