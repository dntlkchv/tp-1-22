#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Base.h"
using namespace std;

class Villain : public Base {
public:
	Villain();
	void setName();
	void setWeapon();
	void setCrime();
	void setHabitat();
	void setSkills();
	void printData();
	void edit();
	void writeToFile(ofstream& file);

	Villain(string valueName, string valueWeapon, string valueCrime, string valueHabitat, string valueSkills, int valueHealth, int valueDamage) {
		name = valueName;
		weapon = valueWeapon;
		crime = valueCrime;
		habitat = valueHabitat;
		skills = valueSkills;
		health = valueHealth;
		damage = valueDamage;

	};

private:
	string name;
	string weapon;
	string crime;
	string habitat;
	string skills;

};