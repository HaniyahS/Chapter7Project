// Chapter7Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

// Function prototypes
void getLocation(int& row, int& column);
void initializeBoard(char(&board)[3][3]);
void displayBoard(char board[3][3]);
bool placeToken(char(&board)[3][3], int row, int column, char token);
bool checkWin(const char(&board)[3][3], char token); // Function to check win condition



int main() {

    int row = 0, column = 0;
    char board[3][3];
    int playerTurn = 0; // 0 for Player 1 (X), 1 for Player 2 (O)
    char currentPlayerToken;

    initializeBoard(board);


    // Game loop (e.g., up to 9 turns or until a win/draw)
    for (int turn = 0; turn < 9; ++turn) {

        displayBoard(board);

        // Determine current player's token
        if (playerTurn == 0) {
            currentPlayerToken = 'X';
            cout << "\nPlayer X's turn.\n";

        }
        else {

            currentPlayerToken = 'O';
            cout << "\nPlayer O's turn.\n";

        }

        getLocation(row, column);
        placeToken(board, row, column, currentPlayerToken);


        // Check for win condition after each move
        if (checkWin(board, currentPlayerToken)) {

            displayBoard(board);
            std::cout << "\nPlayer " << currentPlayerToken << " wins!\n";
            break; // Exit the game loop

        }

        // Check for draw condition
        if (turn == 8) { // If it's the 9th turn and no one won

            displayBoard(board);
            std::cout << "\nIt's a draw!\n";
            break;

        }

        playerTurn = 1 - playerTurn; // Switch to the other player's turn (toggles between 0 and 1)

    }

    return 0;

}

void initializeBoard(char(&board)[3][3]) {

    // Correct way to initialize the array

    for (int i = 0; i < 3; ++i) {

        for (int j = 0; j < 3; ++j) {

            board[i][j] = '*';

        }

    }

}

void displayBoard(char board[3][3]) {
    cout << "\t1\t2\t3"
        << "\n\t------------------";

    cout << "\n1 |\t" << board[0][0] << "\t" << board[0][1] << "\t" << board[0][2]; //add first row
    cout << "\n\n2 |\t" << board[1][0] << "\t" << board[1][1] << "\t" << board[1][2]; //add second row
    cout << "\n\n3 |\t" << board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << "\n"; //add third row

}

void getLocation(int& row, int& column) {
    int inputRow , inputColumn;

    cout << "\nEnter row: ";
    cin >> inputRow;

    while (inputRow != 3 && inputRow != 2 && inputRow != 1) {

        cout << "\nError please enter 1 , 2, or 3\nEnter row: ";
        cin >> inputRow;

    }

    cout << "\nEnter column: ";
    cin >> inputColumn;

    while (inputColumn != 3 && inputColumn != 2 && inputColumn != 1) {

        cout << "\nError please enter 1 , 2, or 3\nEnter column: ";
        cin >> inputColumn;
     
    }
    row = inputRow;
    column = inputColumn;
}

bool placeToken(char(&board)[3][3], int row, int column, char token) {

    // Adjust for 0-based array indexing

    row--;
    column--;

    // Check if the spot is already taken

    if (board[row][column] == '*') {

        board[row][column] = token;

        return true; // Token placed successfully

    }
    else {

        return false; // Spot already taken

    }

}



bool checkWin(const char(&board)[3][3], char token) {
    // Check rows
    for (int i = 0; i < 3; ++i) {

        if (board[i][0] == token && board[i][1] == token && board[i][2] == token) {

            return true;

        }

    }

    // Check columns
    for (int j = 0; j < 3; ++j) {

        if (board[0][j] == token && board[1][j] == token && board[2][j] == token) {

            return true;

        }

    }

    // Check diagonals
    if ((board[0][0] == token && board[1][1] == token && board[2][2] == token) || // Top-left to bottom-right
        (board[0][2] == token && board[1][1] == token && board[2][0] == token)) { // Top-right to bottom-left

        return true;

    }

    return false;
}