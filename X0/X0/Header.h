#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


//welcome screen - rules..
void welcome();

//settings:  easy-1, medium-2; hard-3;
int settingLevel();

//setings: 1vs1-0; 1vsC-1;
bool settingPlayer();

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
bool winner();

//end game - we don't have a winner
bool tieGame();

void startGame();