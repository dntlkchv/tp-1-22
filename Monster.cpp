#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Monster.h"

Monster::Monster() {
	setName();
	setDescription();
}
void Monster::setName() {
	cout << "Monster`s name: ";
	getline(cin, name);
}
void Monster::setDescription() {
	cout << "Monster`s description: ";
	getline(cin, description);
}
void Monster::printData()
{
	cout << "\033[35mMonster\033[0m" << endl;
	cout << "Name: ";
	cout << name << endl;
	cout << "Description: ";
	cout << description << endl;
	cout << "Health: ";
	cout << health << endl;
	cout << "Damage: ";
	cout << damage << endl;
	cout << endl;
}

void Monster::edit() {
	setName();
	setDescription();
}
void Monster::writeToFile(ofstream& file) {
	file << "Monster" << "\n";
	file << name << "\n";
	file << description << "\n";
	file << health << "\n";
	file << damage << "\n";
}