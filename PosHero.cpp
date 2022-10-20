#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "PosHero.h"

PosHero::PosHero() {
	setName();
	setWeapon();
	setSkills();
}
void PosHero::setName() {
	cout << "Positive hero`s name: ";
	getline(cin, name);
}
void PosHero::setWeapon() {
	cout << "Positive hero`s weapon: ";
	getline(cin, weapon);
}
void PosHero::setSkills() {
	cout << "Positive hero`s skills: ";
	getline(cin, skills);
}
void PosHero::printData()
{
	cout << "\033[32mPositive hero\033[0m" << endl;
	cout << "Name: ";
	cout << name<<endl;
	cout << "Weapon: ";
	cout << weapon << endl;
	cout << "Skills: ";
	cout << skills<<endl;
	cout << "Health: ";
	cout << health << endl;
	cout << "Damage: ";
	cout << damage << endl;
	cout << endl;

}
void PosHero::edit() {
	setName();
	setWeapon();
	setSkills();

	cout << endl;
}
void PosHero::writeToFile(ofstream& file) {
	file << "Positive hero" << "\n";
	file << name << "\n";
	file << weapon << "\n";
	file << skills << "\n";
	file << health << "\n";
	file << damage << "\n";
}
