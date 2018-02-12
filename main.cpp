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
			cout << "Error" << endl << endl;
			cin.clear();
		if(result == 'H'){
			cout << "you hit son" << endl << endl;
			cout << "Current status:" << endl << ship.getGrid() << endl;
			cout << "Ammo remaining: " << ship.remaining() << endl;;
		}
		if(result == 'M'){
			cout << "You missed son" << endl << endl;
			cout << "Current status:" << endl << ship.getGrid() << endl;
			cout << "Ammo remaining: " << ship.remaining() << endl;;
		}
	}
	if(ship.isOver() == 'W')
		cout << endl << "u fucking won" << endl;
	if(ship.isOver() == 'L')
		cout << endl << "we lost u r garbage son " << endl;


	return 0;
}