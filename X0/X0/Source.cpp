#include "Header.h"

char board[3][3];
int maxTuns;
char player;
char AI;

//welcome screen - rules..
void welcome()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = '_';

	}

	cout << "X si Zero este un joc la care participa doi jucatori: unul joaca cu semnul X si celalalt joaca cu 0. Ambii muta alternativ, incepand cu jucatorul X. Ei pot muta doar in patratelele libere. Initial, tabla este alcatuita din 9 patratele goale, aliniate intr-o tabla de 3x3. Scopul jocului este de a face 3 semne proprii pe o linie, coloana sau diagonala. Daca tabla este plina dar nici un jucator nu a reusit sa indeplineasca acest scop, atunci jocul se termina remiza.";
	cout << '\n'; cout << '\n';
}

//settings: 1vs1; 1vsC
void settings();

//first player
void firstPlayer()
{
	int r;
	srand(time(NULL));
	r = rand() % 2 + 1;

	if (r == 1)
	{
		player = 'X';
		AI = '0';
		cout << "Tu esti primul! " << '\n';
		cout << '\n';
	}
	else
	{
		player = '0';
		AI = 'X';
		cout << "Primul jucator este calculatorul!" << '\n';
		cout << '\n';
	}
}

//cout turn
void printTurn()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << board[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

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
