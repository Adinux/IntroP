#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	int totalGames=0, winGames=0;

	fstream f;
	f.open("Games.txt");
	f >> totalGames;
	f.close();

	fstream g;
	g.open("Wins.txt");
	g >> winGames;
	g.close();
	
	startGame(totalGames, winGames);

	f.open("Games.txt");
	g.open("Wins.txt");

	f << totalGames;
	g << winGames;

	f.close();
	g.close();

	system("pause");
	return 0;
}