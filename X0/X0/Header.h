#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


//welcome screen - rules..
void welcome();

//settings: 1vs1; 1vsC
void settings();

//first player
void firstPlayer();

//cout turn
void printTurn();

//human moves
void playerMove();

//computer moves: easy AI
void AI1Move();

//computer moves: medium AI
void AI2Move();

//computer moves: hard AI
void AI3Move();

//end game - we have a winner
void winner();

//end game - we don't have a winner
void tieGame();
