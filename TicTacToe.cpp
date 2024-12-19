#include<iostream>
#include<stdio.h>
void displayBoard(char ar[], int n);
using namespace std;
int main()
{
	char ar[9] = { '\0' };
	int turn = -1, i = 0, cho;
	bool over = false;

	system("color 5F");

	while (i < 9)
	{
		++turn;
		turn = turn % 2;

		system("cls");
		cout << "Tic-Tac-Toe Game" << endl;
		displayBoard(ar, 9);

		if (turn == 0)
		{
			cout << "Player 1 Turn's (O)" << endl;
		}
		else
		{
			cout << "Player 2 Turn's (X)" << endl;
		}

		cout << "Enter the place(1-9) you want to add your marker: ";
		cin >> cho;
		cho = cho - 1;

		while (cho < 0 || cho >= 9 || ar[cho] != '\0')
		{
			cout << "Invalid Index" << endl;
			cout << "Please Enter the valid place(1-9) you want to add your marker: ";
			cin >> cho;
			cho = cho - 1;
		}

		if (turn == 0)
		{
			ar[cho] = 'O';
		}
		else
		{
			ar[cho] = 'X';
		}


		if ((ar[0] == ar[1] && ar[1] == ar[2] && ar[0] != '\0') || (ar[3] == ar[4] && ar[4] == ar[5] && ar[3] != '\0') ||
			(ar[6] == ar[7] && ar[7] == ar[8] && ar[6] != '\0') || (ar[0] == ar[3] && ar[3] == ar[6] && ar[0] != '\0') ||
			(ar[1] == ar[4] && ar[4] == ar[7] && ar[1] != '\0') || (ar[2] == ar[5] && ar[5] == ar[8] && ar[2] != '\0') ||
			(ar[0] == ar[4] && ar[4] == ar[8] && ar[0] != '\0') || (ar[2] == ar[4] && ar[4] == ar[6] && ar[2] != '\0'))
		{
			system("cls");
			displayBoard(ar, 9);
			if (turn == 0)
			{
				cout << "Player 1 Won!" << endl;
			}
			else
			{
				cout << "Player 2 Won!" << endl;
			}
			over = true;
		}

		if (over == true)
		{
			cout << "Game over";
			return 0;
		}
		if (i == 8)
		{
			system("cls");
			displayBoard(ar, 9);
			cout << "It's a Draw!" << endl;

		}

		++i;
	}

	return 0;


}
void displayBoard(char ar[], int n)
{
	cout << endl;
	cout << " " << (ar[0] == '\0' ? '1' : ar[0]) << " | " << (ar[1] == '\0' ? '2' : ar[1]) << " | " << (ar[2] == '\0' ? '3' : ar[2]) << endl;
	cout << "---|---|---" << endl;
	cout << " " << (ar[3] == '\0' ? '4' : ar[3]) << " | " << (ar[4] == '\0' ? '5' : ar[4]) << " | " << (ar[5] == '\0' ? '6' : ar[5]) << endl;
	cout << "---|---|---" << endl;
	cout << " " << (ar[6] == '\0' ? '7' : ar[6]) << " | " << (ar[7] == '\0' ? '8' : ar[7]) << " | " << (ar[8] == '\0' ? '9' : ar[8]) << endl;
	cout << endl;
}
