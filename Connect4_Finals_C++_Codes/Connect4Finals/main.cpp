/*——————————————————————————————————————————————-—————————————————————————————————————*/
// Name: Ellis Sentoso
// Email: esentoso@go.pasadena.edu
// Assignment: Connect 4 for Finals CS2
// Last Changed: 6/8/2019
/*——————————————————————————————————————————————-—————————————————————————————————————*/
#include <iostream>
#include <string>
using namespace std;
const int MAX_COL = 7; // Max column
const int MAX_ROW = 6; // Max row
/*——————————————————————————————————————————————-—————————————————————————————————————*/
class Board{
public:
    void set_board(int arr[][COL]) {

        for (int i = 0; i < ROW; i++) {
            cout << i ;
            switch (i) {

            case 0:     // This is a vertical numerical label to the left of the 2D Array
                cout<<"0";
                break;
            case 1:
                cout<<"1";
                break;
            case 2:
                cout<<"2";
                break;
            case 3:
                cout<<"3";
                break;
            case 4:
                cout<<"4";
                break;
            case 5:
                cout<<"5";
                break;

            }
            for (int j = 0; j < COL; j++) {
                cout<<"| ";
                arr[i][j] = 0;
                cout<<" |";
            }

            cout<<endl;
        }
        cout<<"__________________________________"<<endl;
        cout<<"  0    1    2    3    4     5    6"<<endl;
        cout<<"----------------------------------"<<endl;
    }
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void print_board(int arr[][COL]) {

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout<<"|";
                cout<< arr[i][j];
                cout<<"|";
            }
            cout<<endl;
        }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
int clear_board(int arr[][COL]) {

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout<<"| ";
                arr[i][j] = 0;
                cout<<" |";
            }
            cout<<endl;
        }
    }
private:
    // Board
    int array[][COL];

};

/*——————————————————————————————————————————————-—————————————————————————————————————*/
void set_board(const int board[][COL]);
// Precondition: size of the board, Row limits, and Columns limit
// Postcondition: Populated, initialized 2D Arrays
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool place_coin(int col, int board[][COL], int& player_id, int &i, int &j);
//Precondition: an array, a column, player ID, and pass by reference variables
//Postcondition: coin being placed in an available spot
/*——————————————————————————————————————————————-—————————————————————————————————————*/
int clear_board(int arr[][COL]);
//Precondition: an array
//Postcondition: all filled with 0's array
/*——————————————————————————————————————————————-—————————————————————————————————————*/
//int switch();
//int winning_strategy(int arr[][COL], int ai, int player1);
//Precondition: Take an array, the computer will look for 3 counts of the human player
//Postcondition: the computer will attempt to block
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool checker(int arr[][COL], int row, int col, int add_row, int add_col);
//Precondition: array, row, column, either plus 1,0,-1,-0 for add column and row
//Postcondition: true or false
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool ai_move(int arr[][COL], int ai_id, int ai_column);
//Precondition: array, CPU ID, the slot the CPU chooses
//Postcondition: CPU moves
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void menu(int& choice);
//Precondition:int choice
//Postcondition: either option 1 or 2 has been selected
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool isColAvailable(int column, int arr[][COL]);
//Precondition: int column and an array. It checks if a slot is full or not
//Postcondition: true or false
/*——————————————————————————————————————————————-—————————————————————————————————————*/
int processing(int choice);
//Precondition: either 1 or 2
//Postcondition: runs the entire game
int main()
{
    srand(time(0)); // Allow randomization

    int choice = 0;

    Board boardgame;    // Allows access to class
    menu(choice);       // Menu function to prompt user to choose between [1,2]
    processing(choice); // Processes the game after the user has chosen form the menu


}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
int processing(int choice) {

    int board[ROW][COL]; // This is the array board

    int player1_id = 1;  // This is player one's coin
    int player2_id = 2;  // This is player two's or CPU's coin

    int col = 0;         // This is a column variable for player one
    int ai_col = 0;      // This is a column variable for CPU player

    int j = 0;           // variable for row and column
    int i = 0;

    bool p1_turn = false; // bool to flag when user has moved or not
    bool p2_turn = false;

    bool game_over = true; // This is unused variable
    char go_again;         // Variable for character or whther to

    Board boardgame;

    switch (choice) {
    case 1:
        boardgame.set_board(board);
        while (game_over) {

            do {
                place_coin(col, board, player1_id,i,j);
                if (checker(board, i, j, 1,1) ||    // checking diagonal right
                        checker(board, i, j, 1,0)|| // checking down vertical
                        checker(board, i, j, 0,1) ||// checking horitzonal right
                        checker(board, i, j, -1,0) ||// checking vertical up
                        checker(board, i, j, 0,-1) ||// checking horizontal left
                        checker(board, i, j, 1,-1) ||// checking diagonal left
                        checker(board, i, j, -1,1)) { // checking diagonal up right
                    boardgame.print_board(board);
                    cout << "win" << endl;
                    return 0;
                }
                if (ai_move(board,player2_id,ai_col)) {
                    if  (checker(board, i, ai_col, 1,1) ||// checking diagonal right
                         checker(board, i,ai_col, 1,0)||  // checking down vertical
                         checker(board, i,ai_col, 0,1) || // checking horitzonal right
                         checker(board, i,ai_col, -1,0) || // checking vertical up
                         checker(board, i,ai_col, 0,-1) ||// checking horizontal left
                         checker(board, i,ai_col, 1,-1) ||// checking diagonal left
                         checker(board, i,ai_col, -1,1)){// checking diagonal up right
                        boardgame.print_board(board);
                        cout << "win" << endl;
                        return 0;
                    }

                }
                boardgame.print_board(board); // Print the updated state of the board game
                go_again = 'y';
            } while (go_again == 'y' || go_again == 'Y');
        }
        break;
    case 2:
        boardgame.set_board(board);
        do {
            (place_coin(col, board, player1_id,i,j));
            if  (checker(board, i, j, 1,1) ||   // checking diagonal right
                 checker(board, i,j, 1,0)||     // checking down vertical
                 checker(board, i,j, 0,1) ||    // checking horitzonal right
                 checker(board, i,j, -1,0) ||   // checking vertical up
                 checker(board, i,j, 0,-1) ||   // checking horizontal left
                 checker(board, i,j, 1,-1) ||   // checking diagonal left
                 checker(board, i,j, -1,1)){    // checking diagonal up right
                boardgame.print_board(board);
                cout << "Playere 1 wins" << endl;
                return 0;
            }

            p1_turn = true; // means player 1 has gone
            if (p1_turn) {  // When player 1 has gone, it's player2's turn
                place_coin(col, board, player2_id,i,j);

                if  (checker(board, i, j, 1,1) ||   // checking diagonal right
                     checker(board, i,j, 1,0)||     // checking down vertical
                     checker(board, i,j, 0,1) ||    // checking horitzonal right
                     checker(board, i,j, -1,0) ||   // checking vertical up
                     checker(board, i,j, 0,-1) ||   // checking horizontal left
                     checker(board, i,j, 1,-1) ||   // checking diagonal left
                     checker(board, i,j, -1,1)){    // checking diagonal up right
                    boardgame.print_board(board);
                    cout << "Player 2 wins" << endl;
                    return 0;
                }

            }
            boardgame.print_board(board);

            go_again = 'y';
        } while (go_again == 'y' || go_again == 'Y');
        break;

    }
    return 1;
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void set_board(const int board[][COL]) {

    for (int i = 0; i < ROW; i++) {
        switch (i) {
        case 0:            // This part is to print the vertical numerical label to
            cout<<"0";     // the left of the 2D array
            break;
        case 1:
            cout<<"1";
            break;
        case 2:
            cout<<"2";
            break;
        case 3:
            cout<<"3";
            break;
        case 4:
            cout<<"4";
            break;
        case 5:
            cout<<"5";
            break;

        }
        for (int j = 0; j < COL; j++) { // this is print the 2D array and setting it
            cout<<"| ";
            cout<< board[i][j];
            cout<<" |";
        }

        cout<<endl;
    }
    cout<<"__________________________________"<<endl;
    cout<<"  0    1    2    3    4     5    6"<<endl;
    cout<<"----------------------------------"<<endl;
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool checker(int arr[][COL], int row, int col, int add_row, int add_col) {
    for (int i = 0; i < 3; i++) // this is checking up to less than 3 tokens because itself is including in the counting
    {
        // If the square is not filled and there is no matching coins to beging with, trigger false
        if (arr[row][col] != arr[row + add_row][col + add_col] || arr[row][col] == 0 || arr[row + add_row][col + add_col] == 0)
        {
            return false;
        }
        // Update the states by adding the positions like 0s or 1s
        row += add_row;
        col += add_col;
    }

    return true; // Otherwise, say it's true as in there is a matching consecutive coins
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void menu(int& choice) { // Menu for the user to choose whether they wanna play against human player or CPU
    choice = 0;
    do {
        cout << "Press [1] to player against AI" << endl;
        cout << "Press [2] to player between 2 manual players" << endl;
        cin>>choice;
        cin.clear();
    } while (choice < 0 || choice > 2);
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool isColAvailable(int column, int arr[][COL]) {
    //    bool is_it_valid = true;
    for (int i = 5; i >= 0; i--) { // this check each column that has squares from [0,5]
        if (arr[i][column] == 0) {  // 5 indicates it starts at the very bottom of the column
            return true;            // if the very bottom is empty, trigger true
        }
        else {
            return false;           // Otherwise, trigger false
        }
    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool place_coin(int col, int board[][COL], int& player_id, int &i, int &j) {

    cout<<"Pick a column to insert coin from [0 to 6]"<<endl;
    cin>>col; // coin is the column slot

    isColAvailable(col, board); // check whether it is full or not

    if (isColAvailable) {       // If it is not full
        for (int row = 5; row >= 0; row--) // We can place coins in the slot
        { // Starting of for loop
            if (board[row][col] == 0) {
                board[row][col] = player_id;
                i = row;
                j = col;
                return true;

            }
        }  // End of for loop
    }

    else{
        return false;
    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool ai_move(int arr[][COL], int ai_id, int ai_column) {

    ai_column = rand()%6; // Randomize the column

    isColAvailable(ai_column,arr); // Check if it's a valid column as in is it full or not

    while (!isColAvailable) {      // If it is not valid, randomize another column slot
        ai_column = rand()%6;

    }
    if (isColAvailable) { //When it is a valid column slot
        for (int i = 5; i >= 3; i--){   // check up to 3 positions at a time. That's our boundary
            // AI's blocking algorithm
            for (int j  = 0; j < 6; j++) { // Check each slots
                if (arr[i][j] == 1 && arr[i-1][j] == 1 && arr[i-2][j] == 1 && arr[i-3][j] == 0) {
                    arr[i-3][j] = ai_id; // Block human player by CPU per column slot
                    cout <<"AI blocks"<<endl;
                    return true;
                }
            }
            // not blocking
            if (arr[i][ai_column] == 0) { // Otherwise, just do a random move for the CPU player
                arr[i][ai_column] = ai_id;// If there is not blocking human player needed
                return true;

            }
        }
    }
    else {
        return false; // If there is not valid column, return false
    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/



