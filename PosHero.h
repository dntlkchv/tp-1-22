#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Base.h"

using namespace std;
class PosHero : public Base
{
public:
	PosHero();
	void setName();
	void setWeapon();
	void setSkills();
	void printData();
	void edit();
	void writeToFile(ofstream& file);
	PosHero(string valueName, string valueWeapon, string valueSkills, int valueHealth, int valueDamage) {
		name = valueName;
		weapon = valueWeapon;
		skills = valueSkills;
		health = valueHealth;
		damage = valueDamage;
	}

private:
	string name;
	string weapon;
	string skills;

};