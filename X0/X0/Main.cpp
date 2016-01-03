#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;
fstream file("scor.txt");


int main()
{
	int totalGames=0, winGames=0;

	file << "0";
	file >> totalGames;

	//file >> totalGames;
	//file >> winGames;


	startGame(totalGames, winGames);
	cout << totalGames<<" "<<winGames;
	file << totalGames<<'\n';
	//file << winGames;
	file.close();
	system("pause");
	return 0;
}