#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Base.h"
#include "Keeper.h"
#include "PosHero.h"
#include "Monster.h"
#include "Villain.h"
using namespace std;

Keeper:: ~Keeper() {
	delete[]listOfHeroes;
}
int Keeper::getSize()
{
	return this->size;
}
bool Keeper::isEmpty() {
	if (size > 0) return true;

	cout << "\033[34mThere are no heroes yet. \033[0m" << endl;
	return false;
}


void Keeper::showListOfHeroes() {
	if (!isEmpty()) return;
	for (int i = 0; i < size; i++) {
		listOfHeroes[i]->printData();
	}
}


Keeper& Keeper::operator+=(Base* hero)
{
	Base** dest = new Base * [size + 1];
	for (int i = 0; i < size; i++) {
		dest[i] = listOfHeroes[i];
	}
	dest[size++] = hero;
	delete[]listOfHeroes;
	listOfHeroes = dest;

	return *this;
}

void Keeper::removeHero(int ID) {
	Base** dest = new Base * [size - 1];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (i == ID) continue;
		dest[index] = listOfHeroes[index];
		index++;
	}
	delete[]listOfHeroes;
	listOfHeroes = dest;
	size--;
}

void Keeper::saveHero() {
	ofstream fout;

	fout.open("F1.txt");

	if (fout.is_open())
	{
		fout << size << "\n";
		for (int i = 0; i < size; i++) {
			listOfHeroes[i]->writeToFile(fout);
		}

		cout << "\033[34mSuccessfully saved!\033[0m" << endl;
	}
	else {
		cout << "\033[31mCan`t open file\033[0m" << endl;
	}

	fout.close();
}

void Keeper::loadHero() {
	string buffer;
	ifstream fin("F1.txt");
	try {
		if (!fin.is_open()) throw runtime_error("Error:can`t open file!");

		int size;
		fin >> size;


		if (size <= 0) throw runtime_error("Error:file damage!");

		int cnt = 0;
		Base** dest = new Base * [size];

		while (getline(fin, buffer)) {
			if (string("Positive hero") == buffer) {
				string valueName; 
				string valueWeapon; 
				string valueSkills;
				int health;
				int damage;

				getline(fin, valueName);
				getline(fin, valueWeapon);
				getline(fin, valueSkills);
				fin >> health;
				fin >> damage;

				dest[cnt++] = new PosHero(valueName, valueWeapon, valueSkills, health, damage);
			}
			if (string("Villain") == buffer) {
				string valueName;
				string valueWeapon;
				string valueCrime;
				string valueHabitat;
				string valueSkills;
				int health;
				int damage;

				getline(fin, valueName);
				getline(fin, valueWeapon);
				getline(fin, valueCrime);
				getline(fin, valueHabitat);
				getline(fin, valueSkills);
				fin >> health;
				fin >> damage;

				dest[cnt++] = new Villain(valueName, valueWeapon, valueCrime, valueHabitat, valueSkills, health, damage);
			}
			if (string("Monster") == buffer) {
				string valueName;
				string valueDescription;
				int health;
				int damage;

				getline(fin, valueName);
				getline(fin, valueDescription);
				fin >> health;
				fin >> damage;

				dest[cnt++] = new Monster(valueName, valueDescription, health, damage);
			}
		}

		this->size = size;
		delete[]listOfHeroes;
		listOfHeroes = dest;
		cout << "\033[34mSuccessfully loaded!\033[0m" << endl;

	}
	catch (runtime_error error) {
		cout << error.what() << endl;
	}
	catch (...){
		cout << "Unknow eroor!"<<endl;
	}
	fin.close();
}