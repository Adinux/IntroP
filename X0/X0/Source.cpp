#include "Header.h"
#include <cstring>

char board[3][3];
int maxTurns = 0;
char player;
char opponent;
char AI;
int line;
int column;
int AItype;
int setP, setL;
char winnar;

struct Player {
	char mark;
	int id;
};

Player gamer1, gamer2;
//welcome screen - rules..
void welcome()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = '_';

	}

	cout << "X si Zero este un joc la care participa doi jucatori: \nunul joaca cu semnul X si celalalt joaca cu 0. \nAmbii muta alternativ, incepand cu jucatorul X. \nEi pot muta doar in patratelele libere. \nInitial, tabla este alcatuita din 9 patratele goale, \naliniate intr-o tabla de 3x3. \nScopul jocului este de a face 3 semne proprii pe o linie, coloana sau diagonala. \nDaca tabla este plina dar nici un jucator nu a reusit sa indeplineasca acest scop, atunci jocul se termina remiza.";
	cout << '\n'; cout << '\n';
}

void welcomePlayers()
{
	char input[10];

	cout << "Introduceti id-ul primului jucator: ";

	fgets(input, 10, stdin);
	while (atof(input) == 0)
	{
		cout << "Date incorecte!\n";
		fgets(input, 10, stdin);
	}

	gamer1.id = atoi(input);

	cout << "Introduceti id-ul jucatorului al doilea: ";

	fgets(input, 10, stdin);
	while (atof(input) == 0)
	{
		cout << "Date incorecte!\n";
		fgets(input, 10, stdin);
	}

	gamer2.id = atoi(input);
	cout << '\n';
}

//settings:  easy-1, medium-2; hard-3;
int settingLevel()
{
	char input[10];
	
	cout << "Alegeti dificultatea jocului: \nEasy -> 1 \nMedium -> 2 \nHard -> 3 \n";

	fgets(input, 10, stdin);

	while (atof(input) != 2 && atof(input) !=2 && atof(input) !=3 )
	{
		cout << "Date incorecte!\n";
		fgets(input,10, stdin);
	}

	return atoi(input);

}

//setings: 1vs1-2; 1vsC-1;
int settingPlayer()
{
	cout << "Alegeti tipul jocului: \nPlayer vs Computer -> 1 \nPlayer vs Player ->2 \n";
	
	char input[10];


	fgets(input, 10, stdin);

	while (atof(input) != 2 && atof(input) != 2)
	{
		cout << "Date incorecte!\n";
		fgets(input, 10, stdin);
	}

	return atoi(input);
}

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
		cout << "Primul jucator esti tu! " << '\n';
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

void firstPlayerVsPlayer()
{
	int r;
	srand(time(NULL));
	r = rand() % 2 + 1;

	if (r == 1)
	{
		gamer1.mark = 'X';
		gamer2.mark = '0';
		cout << "Primul jucator este " << gamer1.id << '\n';
		cout << '\n';
	}
	else
	{
		gamer1.mark = '0';
		gamer2.mark = 'X';
		cout << "Primul jucator este " << gamer2.id << '\n';
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

//coordinates - validation
void coordinates()
{
	cout << "Introduceti coordonatele: " << '\n';

	cout << "Introduceti linia: ";
	cin >> line;
	while (line >= 3)
	{
		cout << "Date incorecte. Introduceti o valoare valida: \n";
		cin >> line;
	}

	cout << "Introduceti coloana: ";
	cin >> column;
	while (column >= 3)
	{
		cout << "Date incorecte. Introduceti o valoare valida: \n";
		cin >> column;
	}

}
//human moves
void playerMove(int player)
{
	coordinates();
	if (board[line][column] == '_')
	{
		board[line][column] = player;
		maxTurns++;
	}
	else
	{
		while (board[line][column] != '_')
		{
			cout << "Aceasta pozitie este ocupata! \n";

			coordinates();
		}
		board[line][column] = player;
		maxTurns++;

	}
	

}

//computer moves: easy AI
void AI1Move()
{
	int AIline, AIcolumn, ok = 0;
	srand(time(NULL));
	AIline = rand() % 3 ;
	AIcolumn = rand() % 3 ;
	while (board[AIline][AIcolumn] != '_')
	{
		for (int i = 0; i <= 2 && ok==0; i++)
			if (board[AIline][i] == '_')
			{
				AIcolumn = i;
				ok = 1;
			}
		
		for (int i = 0; i <= 2 && ok == 0; i++)
			if (board[i][AIcolumn] == '_')
			{
				AIline = i;
				ok = 1;
			}

		if (ok == 0)
		{
			srand(time(NULL));
			AIline = rand() % 3;
			AIcolumn = rand() % 3;
		}

	}
		
	board[AIline][AIcolumn] = AI;
	maxTurns++;

}


void getPosition(int &x, int &y)
{
	int positionsTaken = 0;
	int line, column;
	//lines
	for (line = 0; line <= 2; line++)
	{
		if (board[line][0] == board[line][1] && board[line][0] == player && board[line][2] == '_')
		{
			x = line; y = 2;
			return;
		}

		else
			if (board[line][0] == board[line][2] && board[line][0] == player && board[line][1] == '_')
		{
			x = line; y = 1;
			return;
		}

		else
			if (board[line][1] == board[line][2] && board[line][1] == player && board[line][0] == '_')
		{
			x = line; y = 0;
			return;
		}

	}

	//columns

	for (column = 0; column <= 2; column++)
	{
		if (board[0][column] == board[1][column] && board[0][column] == player && board[2][column] == '_')
		{
			x = 2; y = column;
			return;
		}
		else
		{
			if (board[1][column] == board[2][column] && board[1][column] == player && board[0][column] == '_')
			{
				x = 0; y = column;
				return;
			}
			else
				if (board[0][column] == board[2][column] && board[0][column] == player && board[1][column] == '_')
				{
					x = 1; y = column;
					return;
				}
		}
	}


	//first diagonal
	if (board[0][0] == board[1][1] && board[0][0] == player && board[2][2] == '_')
	{
		x = 2; y = 2;
		return;
	}

	if (board[0][0] == board[2][2] && board[0][0] == player && board[1][1] == '_')
	{
		x = 1; y = 1;
		return;
	}

	if (board[1][1] == board[2][2] && board[1][1] == player && board[0][0] == '_')
	{
		x = 0; y = 0;
		return;
	}

	//diagonal 2

	if (board[2][0] == board[1][1] && board[1][1] == player &&board[0][2] == '_')
	{
		x = 0; y = 2;
		return;
	}

	if (board[2][0] == board[0][1] && board[2][0] == player &&board[1][1] == '_')
	{
		x = 1; y = 1;
		return;
	}

	if (board[0][2] == board[1][1] && board[1][1] == player &&board[2][0] == '_')
	{
		x = 2; y = 0;
		return;
	}


}

void getCorner(int &x, int &y)
{
	if (board[0][0] == '_')
	{
		x = 0; y = 0;
		return;
	}
	
	if (board[0][2] == '_')
	{
		x = 0; y = 2;
		return;
	}

	if (board[2][0] == '_')
	{
		x = 2; y = 0;
		return;
	}

	if (board[2][2] == '_')
	{
		x = 2; y = 2;
		return;
	}

}

//computer moves: medium AI
void AI2Move()
{
	
	int x = -1, y = -1;

	if (board[1][1] == '_')
		{
			board[1][1] = AI;
			maxTurns++;
			return;
		}
	
	else
	{
		getPosition(x, y);
		if (x != -1 && y != -1)
		{
			board[x][y] = AI;
			maxTurns++;
			return;
		}
		else
		{
			x = -1; y = -1;
			getCorner(x, y);
			if (x != -1 && y != -1)
			{
				board[x][y] = AI;
				maxTurns++;
				return;
			}
			else
			{
				for (int i = 0; i <= 2; i++)
					for (int j = 0; j <= 2; j++)
						if (board[i][j] == '_')
						{
							board[i][j] = AI;
							maxTurns++;
						}
			}

		}
	}

	//AI1Move();

}

//computer moves: hard AI
void AI3Move();


void move(int a)
{
	if (a == 1)
		AI1Move();
	else if (a == 2)
		AI2Move();

}


//end game - we have a winner
bool winner()
{
	//diagonale
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '_')
	{
		winnar = board[0][0];
		return 1;
	}
		
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != '_')
	{
		winnar = board[2][0];
		return 1;
	}

	//linii
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][1] != '_')
	{
		winnar = board[0][0];
		return 1;
	}
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != '_')
	{
		winnar = board[1][0];
		return 1;
	}
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] != '_')
	{
		winnar = board[2][0];
		return 1;
	}

	//coloane
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] != '_')
	{
		winnar = board[0][0];
		return 1;
	}
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != '_')
	{
		winnar = board[0][1];
		return 1;
	}
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != '_')
	{
		winnar = board[0][2];
		return 1;
	}

	return 0;
}

//end game - we don't have a winner
bool tieGame()
{
	if (maxTurns >= 9)
		return 1;
	return 0;
}


void playerVsComputer(int &totalGames, int &winGames)
{
	totalGames++;

	while (tieGame() == 0 && winner() == 0)
	{
		if (player == 'X')
		{
			playerMove(player);
			printTurn();

			if (winner())
			{
				printTurn();
				cout << "A castigat jucatorul " << winnar << '\n';
				if (winnar == player)
					winGames++;
				break;
			}
			else
			{
				if (!tieGame())
				{
					move(setL);
					if (winner())
					{
						printTurn();
						cout << "A castigat jucatorul " << winnar << '\n';
						if (winnar == player)
							winGames++;
						break;
					}
					else 
						printTurn();
				}
			}

		}
		else
		{
			if (winner())
			{
				printTurn();
				cout << "A castigat jucatorul " << winnar << '\n';
				if (winnar == player)
					winGames++;
				break;
			}
			else
			{
				if (!tieGame())
					move(setL);
				printTurn();
				if (winner())
					cout << "A castigat jucatorul " << winnar << '\n';
				if (winnar == player)
					winGames++;
				else
					if (!tieGame() && !winner())
					{
						playerMove(player);
						printTurn();
						if (winner())
							cout << "A castigat jucatorul " << winnar << '\n';
						if (winnar == player)
							winGames++;
					}
			}

		}

	}
	/*
	if (AI == '0')
		printTurn();*/

	if (tieGame())
		cout << "Nimeni nu a castigat!\n";

	cout << "Jocuri totale: " << totalGames << '\n';
	cout << "Jocuri castigate: " << winGames << '\n';
	//cout << (float)totalGames / winGames;

}


void playerVsPlayer()
{

	while (winner() == 0 && tieGame() == 0)
	{
		if (gamer1.mark == 'X')
		{
			playerMove(gamer1.mark);
			printTurn();

			if (winner())
			{
				printTurn();
				cout << "A castigat jucatorul: " << gamer1.id << '\n';
				break;
			}
			else {
				if (!tieGame())
				{
					playerMove(gamer2.mark);
					if (winner())
					{
						printTurn();
						cout << "A castigat jucatorul: " << gamer2.id << '\n';
						break;
					}
					else printTurn();
				}
			}
		}
		else
		{
			playerMove(gamer2.mark);
			printTurn();
			if (winner())
			{
				printTurn();
				cout << "A castigat jucatorul: " << gamer2.id << '\n';
				break;
			}
			else {
				if (!tieGame())
				{
					playerMove(gamer1.mark);
					if (winner())
					{
						printTurn();
						cout << "A castigat jucatorul: " << gamer1.id << '\n';
						break;
					}
					else printTurn();
				}
			}


		}
	}

	if (tieGame())
		cout << "Nimeni nu a castigat!\n";

}


void startGame(int &totalGames, int &winGames)
{
	welcome();
	printTurn();
	setP = settingPlayer();
	if (setP == 1)
	{
		setL = settingLevel();
		firstPlayer();
		playerVsComputer(totalGames,winGames);
	}
	else
	{
		welcomePlayers();
		firstPlayerVsPlayer();
		playerVsPlayer();
	}
}