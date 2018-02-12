#include <iostream>
#include <fstream>
#include <cstdlib>
#include "battleship.h"
using namespace std;

int main(){

	string name;
	ifstream in;
		cout << "Enter filename: ";
		cin >> name;
		in.open(name);
	
	battleship ship(in);

	while(ship.isOver() == 'C'){
		char x;
		int y;
		cout << "Enter coordinates: ";
		cin >> x; 
		cin >> y;
		x = toupper(x);
		char result = ship.fire(x,y);

		if(result == 'E')
			cout << "you out of range bro" << endl;
		if(result == 'H')
			cout << "you hit son" << endl;
		if(result == 'M')
			cout << "You missed son" << endl;

		cout << "Current status:" << endl << ship.getGrid() << endl;

		cout << "Ammo remaining: " << ship.remaining() << endl;;
	}
	if(ship.isOver() == 'L'){
		cout <<"Die cock fucker";
	}


	return 0;
}