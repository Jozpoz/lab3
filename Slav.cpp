#include "Slav.h"
#include <fstream>
#include <iterator>
#include <stdlib.h>

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	//Leniwa Inicjacja - opoznij tworzenie obiektu dopoki nie zajdzie potrzeba uzycia
	static int amountOfNames = (init(), names.size()); 
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}