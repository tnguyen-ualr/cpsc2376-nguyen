// project01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

enum class Cell { BLANK, X, O };
enum class GameStatus { ONGOING, X_WON, O_WON, DRAW };

//make a blank board
void makeBoard(vector<vector<Cell>>& board) {
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            board[row][col] = Cell::BLANK; // Set all cells to blank
        }
    }
}

//display the board
void displayBoard(const vector<vector<Cell>>& board) {
    for (int row = 0; row < 6; row++) {
        cout << "+---+---+---+---+---+---+---+" << endl;
        for (int col = 0; col < 7; col++) {
            char cellChar = '.';
            if (board[row][col] == Cell::X) {
                cellChar = 'X';
            }
            else if (board[row][col] == Cell::O) {
                cellChar = 'O';
            }
            cout << "| " << cellChar << " ";
        }
        cout << "|" << endl;
    }
    cout << "+---+---+---+---+---+---+---+" << endl;
}

//check if the chosen column is full
bool isColumnFull(const vector<vector<Cell>>& board, int col) {
    return board[0][col] != Cell::BLANK;
}

//drop a piece into a column
bool dropPiece(vector<vector<Cell>>& board, int col, Cell player) {
    if (isColumnFull(board, col)) {
        return false;
    }

    for (int row = 5; row >= 0; row--) {
        if (board[row][col] == Cell::BLANK) {
            board[row][col] = player;
            return true;
        }
    }
    return false;
}

//check game status
GameStatus gameStatus(const vector<vector<Cell>>& board) {
    //check for win conditions
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] != Cell::BLANK) {
                Cell player = board[row][col];

                //horizontal check
                if (col + 3 < 7 &&
                    board[row][col + 1] == player &&
                    board[row][col + 2] == player &&
                    board[row][col + 3] == player) {
                    if (player == Cell::X) {
                        return GameStatus::X_WON;
                    }
                    else {
                        return GameStatus::O_WON;
                    }
                }

                //vertical check
                if (row + 3 < 6 &&
                    board[row + 1][col] == player &&
                    board[row + 2][col] == player &&
                    board[row + 3][col] == player) {
                    if (player == Cell::X) {
                        return GameStatus::X_WON;
                    }
                    else {
                        return GameStatus::O_WON;
                    }
                }

                //diagonal (bottom left to top right)
                if (row + 3 < 6 && col + 3 < 7 &&
                    board[row + 1][col + 1] == player &&
                    board[row + 2][col + 2] == player &&
                    board[row + 3][col + 3] == player) {
                    if (player == Cell::X) {
                        return GameStatus::X_WON;
                    }
                    else {
                        return GameStatus::O_WON;
                    }
                }

                //diagonal (top left to bottom right)
                if (row - 3 >= 0 && col + 3 < 7 &&
                    board[row - 1][col + 1] == player &&
                    board[row - 2][col + 2] == player &&
                    board[row - 3][col + 3] == player) {
                    if (player == Cell::X) {
                        return GameStatus::X_WON;
                    }
                    else {
                        return GameStatus::O_WON;
                    }
                }
            }
        }
    }

    //check for a full board
    bool isFull = true;
    for (int col = 0; col < 7; col++) {
        if (board[0][col] == Cell::BLANK) {
            isFull = false;
            break;
        }
    }

    if (isFull) {
        return GameStatus::DRAW;
    }

    return GameStatus::ONGOING;
}

//choose column to drop piece
int getColumn() {
    int column;
    while (true) {
        cout << "Enter a column (1-7): ";
        cin >> column;

        if (cin.fail() || column < 1 || column > 7) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 7." << endl;
        }
        else {
            return column - 1;
        }
    }
}

// a single turn (choose column, check fullness, check win conditions)
void play(vector<vector<Cell>>& board, GameStatus& currentStatus, int column, Cell playerSymbol) {
    if (isColumnFull(board, column)) {
        cout << "Column is full! Try another column." << endl;
        return; // If column is full, return and allow the player to pick again
    }

    if (!dropPiece(board, column, playerSymbol)) {
        cout << "Something went wrong with dropping the piece.\n";
        return;
    }

    displayBoard(board);

    //check game status after turns
    currentStatus = gameStatus(board);

    if (currentStatus == GameStatus::X_WON) {
        cout << "Player 1 (X) wins!\n";
    }
    else if (currentStatus == GameStatus::O_WON) {
        cout << "Player 2 (O) wins!\n";
    }
    else if (currentStatus == GameStatus::DRAW) {
        cout << "The game is a draw!\n";
    }
}

void play(vector<vector<Cell>>& board, GameStatus& currentStatus, int column, Cell& playerSymbol, int& currentPlayer) {
    //check if the current column is full
    if (isColumnFull(board, column)) {
        cout << "Column is full! Try another column." << endl;
        return; //if column is full, allow the player to pick again
    }

    //drop current player's piece in the chosen column
    if (dropPiece(board, column, playerSymbol)) {
        // Display the updated board after the move
        displayBoard(board);

        //check game status after turns
        currentStatus = gameStatus(board);

        if (currentStatus == GameStatus::X_WON) {
            cout << "Player 1 (X) wins!\n";
        }
        else if (currentStatus == GameStatus::O_WON) {
            cout << "Player 2 (O) wins!\n";
        }
        else if (currentStatus == GameStatus::DRAW) {
            cout << "The game is a draw!\n";
        }

        //switch players after successful turns
        if (currentPlayer == 1) {
            currentPlayer = 2;
            playerSymbol = Cell::O;
        }
        else {
            currentPlayer = 1;
            playerSymbol = Cell::X;
        }
    }
    else {
        cout << "Something went wrong with dropping the piece.\n";
    }
}

//ask user if they want to play again
bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        return true;
    }
    else if (choice == 'n' || choice == 'N') {
        return false;
    }
    else {
        cout << "Invalid input. Please enter 'y' for Yes or 'n' for No." << endl;
        return playAgain();
    }
}

int main() {
    vector<vector<Cell>> board(6, vector<Cell>(7));
    GameStatus currentStatus;
    int currentPlayer;
    Cell playerSymbol;

    //game loop
    do {
        makeBoard(board);
        currentStatus = GameStatus::ONGOING;
        currentPlayer = 1;
        playerSymbol = Cell::X;

        cout << "Welcome to Connect 4!\nTake turns trying to connect 4 pieces in a row:\n"
            << "vertically(up and down), horizontally(left to right),\nand diagonially(top left or right to bottom left or right)." << endl;
        displayBoard(board);
        while (currentStatus == GameStatus::ONGOING) {
            int column = getColumn();
            play(board, currentStatus, column, playerSymbol, currentPlayer);
        }

        //ask if user wants to play again (y/n)
    } while (playAgain());

    cout << "Thanks for playing!" << endl;
    return 0;
}


