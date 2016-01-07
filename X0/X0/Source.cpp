#include "Header.h"

char board[3][3];
int maxTurns = 0;
char player;
char AI;
int line;
int column;
int AItype;
int setP, setL;
char winnar;

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

//settings:  easy-1, medium-2; hard-3;
int settingLevel()
{
	cout << "Alegeti dificultatea jocului: \nEasy -> 1 \nMedium -> 2 \nHard -> 3 \n";
	int choice;//caracter=> convertit in cifra.
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << "Alegere incorecta! Introduceti alte date: ";
		cin >> choice;
	}

	return choice;

}

//setings: 1vs1-0; 1vsC-1;
bool settingPlayer()
{
	cout << "Alegeti tipul jocului: \nPlayer vs Player -> 0 \nPlayer vs Computer ->1 \n";
	
	char input;
	int choice;
	cin >> choice;

	while (choice < 0 || choice > 1)
	{
		cout << "Alegere incorecta! Introduceti alte date: ";
		cin >> choice;

	}

	return choice;
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
void playerMove()
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

void startGame(int &totalGames, int &winGames)
{
	totalGames++;
	welcome();
	printTurn();
	setP = settingPlayer();
	if (setP == 1)
		setL = settingLevel();
	
	firstPlayer();
	while (tieGame()==0 || winner()==0)
	{
		if (player == 'X')
		{
			playerMove();
			printTurn();

			if (winner())
			{
				printTurn();
				cout << "A castigat jucatorul "<<winnar<<'\n';
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
						playerMove();
			}
			
		}

	}
	if(AI=='0')
		printTurn();
}