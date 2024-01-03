#include <iostream>
#include <string>
using namespace std;

int menu();
int boardSize(int& size);
void constructBoard(char board[10][10], int& size);
void printBoard(char board[10][10], int& size);
void playerInput(char board[][10], int& size, int& gamemode, bool& player1, bool& player2);
void AI_Input(char board[][10], int& size);
bool checkRow(char board[][10], int& size);
bool checkTie(char board[][10], int& size);
bool checkColumn(char board[][10], int& size);
bool checkDiagonal(char board[][10], int& size);
bool checkOffDiagonal(char board[][10], int& size);
bool detectGameOver(char board[][10], int& size);


int main()
{
	char board[10][10];
	int size = 0;
	int gamemode;
	bool gameOver = false;
	bool player1 = true;
	bool player2 = false;


	gamemode = menu();
	boardSize(size);
	constructBoard(board, size);
	printBoard(board, size);

	while (!gameOver)
	{
		if (gamemode == 1)
		{
			playerInput(board, size, gamemode, player1, player2);
			printBoard(board, size);
			gameOver = detectGameOver(board, size);

			if (gameOver == true) {
				break;
			}
			AI_Input(board, size);
			printBoard(board, size);
			gameOver = detectGameOver(board, size);
		}
		else
		{
			playerInput(board, size, gamemode, player1, player2);
			printBoard(board, size);
			gameOver = detectGameOver(board, size);
		}
	}
	return 0;
}
int menu()
{
	int userChoice;
	cout << "\n\n*Tic Tac Toe*"
		<< "\n1. Single Player"
		<< "\n2. Multiplayer"
		<< "\nEnter Here: "; cin >> userChoice;
	return userChoice;
}
int boardSize(int& size)
{
	cout << "\nHow big do you want your board?" << endl;
	cout << "Enter here: "; cin >> size;
	return size;
}
void constructBoard(char board[10][10], int& size)
{
	cout << "Test" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			board[i][j] = '_';
		}
	}
}
void printBoard(char board[10][10], int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void playerInput(char board[][10], int& size, int& gamemode, bool& player1, bool& player2)
{
	int row, col;
	if (gamemode == 1)
	{
		cout << "Player 1: "
			<< "\nRow: "; cin >> row;
		row = row - 1;
		cout << "Col: "; cin >> col;
		col = col - 1;
		board[row][col] = 'X';
	}
	else
	{
		if (player1 == true)
		{
			cout << "Player 1: "
				<< "\nRow: "; cin >> row;
			row = row - 1;
			cout << "Col: "; cin >> col;
			col = col - 1;
			board[row][col] = 'X';
			player1 = false;
			player2 = true;
		}
		else
		{
			cout << "Player 2: "
				<< "\nRow: "; cin >> row;
			row = row - 1;
			cout << "Col: "; cin >> col;
			col = col - 1;
			board[row][col] = 'O';
			player1 = true;
			player2 = false;
		}
	}
}
void AI_Input(char board[][10], int& size)
{
	int row, col;
	srand(time(0));
	cout << "AI TURN" << endl;
	row = rand() % size;
	col = rand() % size;
	board[row][col] = 'O';
}

bool checkRow(char board[][10], int& size)
{
	///detect row wins
	int xCounter = 0, oCounter = 0;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[j][i] == 'X')
			{
				xCounter++;
				if (xCounter == size)
				{
					cout << "X Wins!";
					return true;
				}
			}
			else if (board[j][i] == 'O')
			{
				oCounter++;
				if (oCounter == size)
				{
					cout << "O Wins!";
					return true;
				}
			}
		}
		xCounter = 0;
		oCounter = 0;

	}
	return false;
}
bool checkOffDiagonal(char board[][10], int& size)
{
	{
		int xCounter = 0, oCounter = 0;
		for (int i = 0; i < size; i++)
		{
			if (board[i][size - i - 1] == 'X')
			{
				xCounter++;
			}
			if (board[i][size - i - 1] == 'O')
			{
				oCounter++;
			}
		}
		if (xCounter == size)
		{
			cout << "X Wins!";
			return true;
		}
		if (oCounter == size)
		{
			cout << "O Wins!";
			return true;
		}
		return false;
	}
}
bool checkDiagonal(char board[][10], int& size)
{
	int xCounter = 0;
	int oCounter = 0;
	for (int i = 0; i < size; i++)
	{
		if (board[i][i] == 'X')
		{
			xCounter++;
		}
		else if (board[i][i] == 'O')
		{
			oCounter++;
		}
	}
	if (xCounter == size)
	{
		cout << "X Wins!";
		return true;
	}
	if (oCounter == size)
	{
		cout << "O Wins!";
		return true;
	}
	return false;
}
bool checkColumn(char board[][10], int& size)
{
	///detect column wins
	int xCounter = 0, oCounter = 0;
	for (int j = 0; j < size; j++)
	{

		for (int i = 0; i < size; i++)
		{
			if (board[i][j] == 'X')
			{
				xCounter++;
				if (xCounter == size)
				{
					cout << "X Wins!";
					return true;
				}
			}
			else if (board[i][j] == 'O')
			{
				oCounter++;
				if (oCounter == size)
				{
					cout << "O Wins!";
					return true;
				}
			}
		}
		xCounter = 0;
		oCounter = 0;
	}
	return false;
}
bool checkTie(char board[][10], int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == '_')
			{
				return false;
			}
		}
	}
	return true;
}

bool detectGameOver(char board[][10], int& size)
{
	bool gameover = false;
	gameover = checkRow(board, size);
	if (gameover)
	{
		cout << "Game Over!" << endl;
		return true;
	}
	gameover = checkColumn(board, size);
	if (gameover)
	{
		return true;
	}
	gameover = checkDiagonal(board, size);
	if (gameover)
	{
		return true;
	}
	gameover = checkOffDiagonal(board, size);
	if (gameover)
	{
		return true;
	}
	gameover = checkTie(board, size);
	if (gameover)
	{
		cout << "It's a Tie!" << endl;
		return true;
	}
	return false;
}
