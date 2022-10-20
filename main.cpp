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
Keeper keeper;

void remove() {
	if (!keeper.isEmpty()) return;

	int number;
	cout << "Enter ID:";
	cin >> number;
	if (number < 0 || number>keeper.getSize())  {
		cout << "\033[31mError:that hero does not exist!\033[0m" << endl;
		return;
	}
	keeper.removeHero(number);
	cout << "\033[34mThe hero is removed successfully!\033[0m" << endl;

}

void editHero() {

	if (!keeper.isEmpty()) return;

	int number;
	cout << "Enter ID:";
	cin >> number;
	cin.ignore();
	if (number < 0 || number>keeper.getSize()) {
		cout << "\033[31mError:that hero does not exist!\033[0m" << endl;
		return;
	}

	keeper.listOfHeroes[number]->edit();
}

void fight() {
	cout << keeper.getSize() << endl;
	int num1;
	cout << "Enter ID of a first fighter:";
	cin >> num1;
	cin.ignore();
	int num2;
	cout << "Enter ID of a second fighter:";
	cin >> num2;
	cin.ignore();
	if (num1 < 0 || num1 > keeper.getSize() - 1 || num2 < 0 || num2 > keeper.getSize() - 1 || num1 == num2) {
		cout << "\033[31mError:that hero does not exist!\033[0m" << endl;
		return;
	}

	Base* hero1;
	Base* hero2;

	hero1 = keeper.listOfHeroes[num1];
	hero2 = keeper.listOfHeroes[num2];

	while (hero1->health > 0 && hero2->health > 0) {
		cout << "First hero (" << hero1->health << "hp) deals " << hero1->damage << " damage to the second hero(" << hero2->health << "hp)." << endl;
		hero2->health -= hero1->damage;

		if (hero2->health <= 0) {
			cout << "The second hero(" << hero2->health << "hp) is dead!" << endl;
			cout << "The first hero(" << hero1->health << "hp) won!" << endl;
			keeper.removeHero(num2);
			break;
		}

		cout << "Second hero(" << hero2->health << "hp) deals " << hero1->damage << " damage to the first hero(" << hero1->health << "hp)." << endl;
		hero1->health -= hero2->damage;

		if (hero1->health <= 0) {
			cout << "The first hero(" << hero1->health << "hp) dead!" << endl;
			cout << "The second hero(" << hero2->health << "hp) won!" << endl;
			keeper.removeHero(num1);
			break;
		}
	}
	
}

int menu() {
	int stop = 0;
	int command = 0;
	while (!stop) {

		cout << "Choose number of command: " << endl;
		cout << "1. Show the list of heroes. " << endl;
		cout << "2. Add positive hero. " << endl;
		cout << "3. Add villain. " << endl;
		cout << "4. Add monster. " << endl;
		cout << "5. Remove hero.  " << endl;
		cout << "6. Edit hero. " << endl;
		cout << "7. Save hero. " << endl;
		cout << "8. Load Hero. " << endl;
		cout << "9. Fight!" << endl;
		cout << "0. Exit " << endl;
		cout << endl;
		cout << "Number of a command: ";

		cin >> command;
		cin.ignore();
		switch (command)
		{
		case 0:
			stop = 1;
			break;
		case 1:
			keeper.showListOfHeroes();
			break;

		case 2:
			keeper.addHero(new PosHero());
			break;

		case 3:
			keeper.addHero(new Villain());
				break;

		case 4:
			keeper.addHero(new Monster());
				break;
		case 5:
			remove();
			break;

		case 6:
			editHero();
			break;
		case 7:
			if (!keeper.isEmpty()) continue;
			keeper.saveHero();
			break;
		case 8:
			keeper.loadHero();
			break;

		case 9:
			fight();
			break;

		default:
			cout << "Error" << endl;
			break;
		}

	}
	return 0;
}

int main() {
	srand(time(NULL));
	menu();
	return 0;
}