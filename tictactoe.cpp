#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>> &board);
void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char>> &board, char currentPlayer);
bool checkDraw(const vector<vector<char>> &board);
char switchPlayer(char currentPlayer);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 game board
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        initializeBoard(board);

        while (true) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                } else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    break;
                }

                currentPlayer = switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    } while (true);

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(vector<vector<char>> &board, char currentPlayer, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>> &board, char currentPlayer) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Column win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // The game is not a draw
            }
        }
    }
    return true; // The game is a draw
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}
