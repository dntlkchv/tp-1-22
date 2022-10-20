#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Base {
public:
	virtual void printData()=0;
	virtual void edit() = 0;
	virtual void writeToFile(ofstream& file) = 0;
	int health = rand() % 100;
	int damage = rand() % 100;

};
