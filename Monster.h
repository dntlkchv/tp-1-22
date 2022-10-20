#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Base.h"
using namespace std;

class Monster : public Base {
public:
	Monster();
	void setName();
	void setDescription();
	void printData();
	void edit();
	void writeToFile(ofstream& file);
	Monster(string valueName, string valueDescription, int valueHealth, int valueDamage) {
		name= valueName;
		description = valueDescription;
		health = valueHealth;
		damage = valueDamage;
};
private:
	string name;
	string description;

};