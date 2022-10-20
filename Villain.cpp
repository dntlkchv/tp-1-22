#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Villain.h"

Villain::Villain() {
	setName();
	setWeapon();
	setCrime();
	setHabitat();
	setSkills();
}
void Villain::setName() {
	cout << "Villain`s name: ";
	getline(cin, name);
}
void Villain::setWeapon() {
	cout << "Villain`s weapon: ";
	getline(cin, weapon);
}
void Villain::setCrime() {
	cout << "Villain`s crime: ";
	getline(cin, crime);
}
void Villain::setHabitat() {
	cout << "Villain`s habitat: ";
	getline(cin, habitat);

}
void Villain::setSkills() {
	cout << "Villain`s skills: ";
	getline(cin, skills);
}
void Villain::printData()
{
	cout << "\033[31mVillain\033[0m" << endl;
	cout << "Name: ";
	cout << name << endl;
	cout << "Weapon: ";
	cout << weapon << endl;
	cout << "Crime: ";
	cout << crime << endl;
	cout << "Habitat: ";
	cout << habitat << endl;
	cout << "Skills: ";
	cout << skills << endl;
	cout << "Health: ";
	cout << health << endl;
	cout << "Damage: ";
	cout << damage << endl;

	cout << endl;

}

void Villain::edit() {
	
	setName();
	setWeapon();
	setCrime();
	setHabitat();
	setSkills();

	cout << endl;
}

void Villain::writeToFile(ofstream& file)  {
	file << "Villain" << "\n";
	file << name << "\n";
	file << weapon << "\n";
	file << crime << "\n";
	file << habitat << "\n";
	file << skills << "\n";
	file << health << "\n";
	file << damage << "\n";
}