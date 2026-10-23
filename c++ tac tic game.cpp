#include <iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

void drawBoard()
{
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placemarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else
    {
        return false;
    }
}

int winner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}

void swapPlayerandMarker()
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
        currentMarker = 'O';
    }
    else
    {
        currentPlayer = 1;
        currentMarker = 'X';
    }
}

void game()
{
    cout << "Player 1 choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    // Validate input and convert to uppercase
    markerP1 = toupper(markerP1);
    while (markerP1 != 'X' && markerP1 != 'O')
    {
        cout << "Invalid marker. Please choose X or O: ";
        cin >> markerP1;
        markerP1 = toupper(markerP1);
    }

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int playerwon = 0;
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot, please try again.\n";
            i--;
            continue;
        }
        if (!placemarker(slot))
        {
            cout << "Slot occupied! Try again.\n";
            i--;
            continue;
        }
        drawBoard();

        playerwon = winner();

        if (playerwon == 1)
        {
            cout << "Player 1 wins!\n";
            break;
        }
        else if (playerwon == 2)
        {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerandMarker();
    }

    if (playerwon == 0)
    {
        cout << "It's a tie!\n";
    }
}

int main()
{
    game();
    return 0;
}

