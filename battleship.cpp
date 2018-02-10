#include "battleship.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/*---------------------------------------
Constructor
PARAMETER(S):ifstream from main
POSTCONDITION(S):Constructs the playerGrid to emptyspaces
sets the solutionGrid to what the input file states
sets maxmoves and movesmade to 20 and 0 respectively.
essentially sets the game up.
---------------------------------------*/
battleship::battleship(ifstream& in)
{
	char c;
h
	for(int i = 0; i < ROWS; i++)
   		for(int j = 0; j < COLUMNS; j++){
    		in >> c;
    		if(c == '1')
    			solutionGrid[i][j] = 1;
      		if(c == '0')
        		solutionGrid[i][j] = 0;
    }
	
	for(int c = 0; c < ROWS; c++)
		for(int j = 0; j < COLUMNS; j++)
			playerGrid[j][c] = ' ';
	
	maxMoves = 20;
	movesMade = 0;
	for(int c = 0; c < ROWS; c++)
		for(int j = 0; j < COLUMNS; j++){
			if(j==9)
				cout << '\n';
			cout << solutionGrid[c][j];
		}
}
/*---------------------------------------
FUNCTION NAME:
PARAMETER(S):
RETURN TYPE:
POSTCONDITION(S):
---------------------------------------*/
char battleship::fire(char x, int y)
{
	int a = x - 65;
	



	if(a > 9 or a < 0 or y > 9 or y < 0){
		return 'E';
	}
	if(solutionGrid[a][y]){
		playerGrid[a][y] = 'X';
		return 'H';
	}else{
		return 'M';
	}
}
/*---------------------------------------
FUNCTION NAME:
PARAMETER(S):
RETURN TYPE:
POSTCONDITION(S):
---------------------------------------*/
char battleship::isOver() const
{
	if((movesMade == maxMoves)and(remaining() > 0))
		return 'L';
	if(remaining() == 0)
		return 'W';
	else
		return 'C';
}
/*---------------------------------------
FUNCTION NAME:GetGrid
PARAMETER(S):None
RETURN TYPE:string
POSTCONDITION(S):Outputs a string that forms a grid that contains
the playerGrid with labels
---------------------------------------*/
string battleship::getGrid() const
{
	string board = "  1 2 3 4 5 6 7 8 9 10 \n";
	char alph = 65;
	for(int c = 0; c < 10; c++){
		board += alph;
		for(int r = 0; r < 10; r++){
			board += '|';
			board += playerGrid[c][r];
		}
		board += '|';
		alph++;
		board += '\n';	
	}
	return board;
}
/*---------------------------------------
FUNCTION NAME:
PARAMETER(S):
RETURN TYPE:
POSTCONDITION(S):
---------------------------------------*/
int battleship::remaining() const
{
	int total = 3;
	return total;
}