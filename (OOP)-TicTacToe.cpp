#include <iostream>
#include <cstdlib>
using namespace std;
class TicTacToe 
{
private:
    int** board;  
    int win = -1;     

public:
    TicTacToe();
    void displayBoard();
    bool checkWin();
    void takeMove(int player);
};
TicTacToe::TicTacToe()
{
    board = new int* [3];
    for (int i = 0; i < 3; i++)
    {
        *(board + i) = new int [3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; ++j)
        {
            *(*(board + i) + j) = 0;

        }
    }
}
void TicTacToe::displayBoard() 
{
    system("cls");

    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << " " << *(*(board + i) + j) << " ";
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "---|---|---" << endl;
        }
    }
    cout << endl;
}
void TicTacToe::takeMove(int player) 
{
    int move;
    bool validMove = false;

    while (!validMove) 
    {
        cout << "Player " << player << " (Enter position 1-9): ";
        cin >> move;

        if (move < 1 || move > 9) 
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 0) 
        {
            *(*(board + row) + col) = player;
            validMove = true;
        }
        else 
        {
            cout << "Spot already taken. Try again." << endl;
        }
    }
}
bool TicTacToe::checkWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0))
        {
            win = board[i][0];
            return true;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)) 
    {
        win = board[1][1];
        return true;
    }

    return false;
}
int main() 
{
    TicTacToe game;
    int turns = 0, player = 0;

    cout << "--------Tic Tac Toe Game--------" << endl;
    game.displayBoard();

    while (turns < 9)
    {
        player = (turns % 2 == 0) ? 1 : 2;
        game.takeMove(player);
        game.displayBoard();

        if (game.checkWin()) 
        {
            cout << "Player " << player << " wins!" << endl;
            return 0;
        }

        turns++;
    }

    cout << "It's a draw!";
    return 0;
}
