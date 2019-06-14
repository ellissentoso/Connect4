/*——————————————————————————————————————————————-—————————————————————————————————————*/
// Name: Ellis Sentoso
// Email: esentoso@go.pasadena.edu
// Assignment: Connect 4 Finals for CS2
// Last Changed: 6/9/19
/*——————————————————————————————————————————————-—————————————————————————————————————*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <QPainter>
#include <QMessageBox>
/*——————————————————————————————————————————————-—————————————————————————————————————*/
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(click()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(click()),this,SLOT(digit_pressed2()));
    connect(ui->pushButton_3,SIGNAL(click()),this,SLOT(digit_pressed3()));
    connect(ui->pushButton_4,SIGNAL(click()),this,SLOT(digit_pressed4()));
    connect(ui->pushButton_5,SIGNAL(click()),this,SLOT(digit_pressed5()));
    connect(ui->pushButton_6,SIGNAL(click()),this,SLOT(digit_pressed6()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool Board::ai_move(int ai_id, int ai_column) {

    ai_column = rand()%7 + 1;

    bool available = isColAvailable(ai_column);

    while (!available) {
        ai_column = rand()%6;

    }
    if (available) {
        for (int i = 5; i >= 3; i--){
            // AI's blocking algorithm
            for (int j  = 0; j < 6; j++) {
                if (board[i][j] == 1 && board[i-1][j] == 1 && board[i-2][j] == 1 && board[i-3][j] == 0) {
                    board[i-3][j] = ai_id;
                    cout << "block " << endl;
                    break;
                }
            }
            // not blocking
            if (board[i][ai_column] == 0) {
                board[i][ai_column] = ai_id;
                break;

            }
        }
    }
    else {
        return false;
    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void Board::set_board() {

    for (int i = 0; i < ROW; i++) {
        switch (i) {
        case 0:
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
            board[i][j] = 0;
            cout<<" |";
        }

        cout<<endl;
    }
    cout<<"__________________________________"<<endl;
    cout<<"  0    1    2    3    4     5    6"<<endl;
    cout<<"----------------------------------"<<endl;
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool Board::checker(int row, int col, int add_row, int add_col) {


    for (int i = 0; i < 3; i++)
    {
        if (board[row][col] != board[row + add_row][col + add_col] || board[row][col] == 0 || board[row + add_row][col + add_col] == 0)
        {
            return false;
        }

        row += add_row;
        col += add_col;
    }

    return true;
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void Board::menu(int& choice) {
    choice = 0;
    do {
        cout << "Press [1] to player against AI" << endl;
        cin>>choice;
        cin.clear();
    } while (choice < 0 || choice > 1);
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool Board::isColAvailable(int column) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][column] == 0) {
            return true;
        }
        else {
            return false;
        }
    }

}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
bool Board::place_coin(int col, int& player_id, int &i, int &j) {

    cout<<"Pick a column to insert coin from [0 to 6]"<<endl;
    cin>>col; // coin is the column slot

    bool available = isColAvailable(col);

    if (available) {
        for (int row = 5; row >= 0; row--)
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
void MainWindow::on_pushButton_clicked()
{
    if (ui->toolButton_16->text() == "") {
        ui->toolButton_16->setText("X");
        ui->toolButton_16->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_13->text() == "") {
        ui->toolButton_13->setText("X");
        ui->toolButton_13->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_10->text() == "") {
        ui->toolButton_10->setText("X");
        ui->toolButton_10->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_7->text() == "") {
        ui->toolButton_7->setText("X");
        ui->toolButton_7->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_4->text() == "") {
        ui->toolButton_4->setText("X");
        ui->toolButton_4->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton->text() == "") {
        ui->toolButton->setText("X");
        ui->toolButton->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }

    if (ui->toolButton_16->text() == "X" && ui->toolButton_13->text() == "X" && ui->toolButton_10->text() == "X")
    {
        ui->toolButton_7->setText("O");
        ui->toolButton_7->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_13->text() == "X" && ui->toolButton_10->text() == "X" && ui->toolButton_7->text() == "X")
    {
        ui->toolButton_4->setText("O");
        ui->toolButton_4->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_10->text() == "X" && ui->toolButton_7->text() == "X" && ui->toolButton_4->text() == "X")
    {
        ui->toolButton->setText("O");
        ui->toolButton->setStyleSheet("background-color: blue");

    }

    // Horizontal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_17->text() == "X" &&
            ui->toolButton_18->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_24->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_10->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_7->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_4->text() == "X" &&
            ui->toolButton_5->text() == "X" &&
            ui->toolButton_6->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton->text() == "X" &&
            ui->toolButton_2->text() == "X" &&
            ui->toolButton_3->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_13->text() == "X" &&
            ui->toolButton_10->text() == "X" &&
            ui->toolButton_7->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_10->text() == "X" &&
            ui->toolButton_7->text() == "X" &&
            ui->toolButton_4->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_10->text() == "X" &&
            ui->toolButton_7->text() == "X" &&
            ui->toolButton_4->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_10->text() == "X" &&
            ui->toolButton_7->text() == "X" &&
            ui->toolButton_4->text() == "X" &&
            ui->toolButton->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("O");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }


        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_13->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_4->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_4->text() == "O" &&
                ui->toolButton->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_13->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");

        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_2_clicked()
{
    if (ui->toolButton_17->text() == "") {
        ui->toolButton_17->setText("X");
        ui->toolButton_17->setStyleSheet("background-color: red");


    }
    else if (ui->toolButton_14->text() == "") {
        ui->toolButton_14->setText("X");
        ui->toolButton_14->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_11->text() == "") {
        ui->toolButton_11->setText("X");
        ui->toolButton_11->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_8->text() == "") {
        ui->toolButton_8->setText("X");
        ui->toolButton_8->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_5->text() == "") {
        ui->toolButton_5->setText("X");
        ui->toolButton_5->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_2->text() == "") {
        ui->toolButton_2->setText("X");
        ui->toolButton_2->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_2->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_17->text() == "X" && ui->toolButton_14->text() == "X" && ui->toolButton_11->text() == "X")
    {
        ui->toolButton_8->setText("O");
        ui->toolButton_8->setStyleSheet("background-color: blue");

    }

    if (ui->toolButton_14->text() == "X" && ui->toolButton_11->text() == "X" && ui->toolButton_8->text() == "X")
    {
        ui->toolButton_5->setText("O");
        ui->toolButton_5->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_11->text() == "X" && ui->toolButton_8->text() == "X" && ui->toolButton_5->text() == "X")
    {
        ui->toolButton_2->setText("O");
        ui->toolButton_2->setStyleSheet("background-color: blue");

    }


    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Horizontal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_17->text() == "X" &&
            ui->toolButton_18->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_24->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_10->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_7->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_4->text() == "X" &&
            ui->toolButton_5->text() == "X" &&
            ui->toolButton_6->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton->text() == "X" &&
            ui->toolButton_2->text() == "X" &&
            ui->toolButton_3->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_17->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_8->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_5->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_11->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_5->text() == "X" &&
            ui->toolButton_2->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_5->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }

        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }


        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");

        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }


        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }


        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_17->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_2->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_5->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }

}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_3_clicked()
{

    if (ui->toolButton_18->text() == "") {
        ui->toolButton_18->setText("X");
        ui->toolButton_18->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_15->text() == "") {
        ui->toolButton_15->setText("X");
        ui->toolButton_15->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_12->text() == "") {
        ui->toolButton_12->setText("X");
        ui->toolButton_12->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_9->text() == "") {
        ui->toolButton_9->setText("X");
        ui->toolButton_9->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_6->text() == "") {
        ui->toolButton_6->setText("X");
        ui->toolButton_6->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_3->text() == "") {
        ui->toolButton_3->setText("X");
        ui->toolButton_3->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_3->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }

    if (ui->toolButton_18->text() == "X" && ui->toolButton_15->text() == "X" && ui->toolButton_12->text() == "X")
    {
        ui->toolButton_9->setText("O");
        ui->toolButton_9->setStyleSheet("background-color: blue");

    }

    if (ui->toolButton_15->text() == "X" && ui->toolButton_12->text() == "X" && ui->toolButton_9->text() == "X")
    {
        ui->toolButton_6->setText("O");
        ui->toolButton_6->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_12->text() == "X" && ui->toolButton_9->text() == "X" && ui->toolButton_6->text() == "X")
    {
        ui->toolButton_3->setText("O");
        ui->toolButton_3->setStyleSheet("background-color: blue");

    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }


    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Horizontal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_17->text() == "X" &&
            ui->toolButton_18->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_24->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_10->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_7->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_4->text() == "X" &&
            ui->toolButton_5->text() == "X" &&
            ui->toolButton_6->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton->text() == "X" &&
            ui->toolButton_2->text() == "X" &&
            ui->toolButton_3->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_18->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_9->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_6->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_6->text() == "X" &&
            ui->toolButton_3->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_6->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");
        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");
            ui->toolButton_9->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");
            ui->toolButton_19->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_4_clicked()
{
    if (ui->toolButton_21->text() == "") {
        ui->toolButton_21->setText("X");
        ui->toolButton_21->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_32->text() == "") {
        ui->toolButton_32->setText("X");
        ui->toolButton_32->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_24->text() == "") {
        ui->toolButton_24->setText("X");
        ui->toolButton_24->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_30->text() == "") {
        ui->toolButton_30->setText("X");
        ui->toolButton_30->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_26->text() == "") {
        ui->toolButton_26->setText("X");
        ui->toolButton_26->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_29->text() == "") {
        ui->toolButton_29->setText("X");
        ui->toolButton_29->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_29->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }

    if (ui->toolButton_21->text() == "X" && ui->toolButton_32->text() == "X" && ui->toolButton_24->text() == "X")
    {
        ui->toolButton_30->setText("O");
        ui->toolButton_30->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_32->text() == "X" && ui->toolButton_24->text() == "X" && ui->toolButton_30->text() == "X")
    {
        ui->toolButton_26->setText("O");
        ui->toolButton_26->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_24->text() == "X" && ui->toolButton_30->text() == "X" && ui->toolButton_26->text() == "X")
    {
        ui->toolButton_29->setText("O");
        ui->toolButton_29->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_33->text() == "X" &&
            ui->toolButton_37->text() == "X" &&
            ui->toolButton_34->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_36->text() == "X" &&
            ui->toolButton_22->text() == "X" &&
            ui->toolButton_40->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_19->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_27->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_25->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_39->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_35->text() == "X" &&
            ui->toolButton_28->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }


    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Horizontal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_17->text() == "X" &&
            ui->toolButton_18->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_13->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_24->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_11->text() == "X" &&
            ui->toolButton_10->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_7->text() == "X" &&
            ui->toolButton_8->text() == "X" &&
            ui->toolButton_9->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_4->text() == "X" &&
            ui->toolButton_5->text() == "X" &&
            ui->toolButton_6->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton->text() == "X" &&
            ui->toolButton_2->text() == "X" &&
            ui->toolButton_3->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_21->text() == "X" &&
            ui->toolButton_32->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_32->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_24->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_26->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_26->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 3) {
        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");
        }
        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");
            ui->toolButton_9->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");
            ui->toolButton_19->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_5_clicked()
{
    if (ui->toolButton_34->text() == "") {
        ui->toolButton_34->setText("X");
        ui->toolButton_34->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_22->text() == "") {
        ui->toolButton_22->setText("X");
        ui->toolButton_22->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_27->text() == "") {
        ui->toolButton_27->setText("X");
        ui->toolButton_27->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_20->text() == "") {
        ui->toolButton_20->setText("X");
        ui->toolButton_20->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_23->text() == "") {
        ui->toolButton_23->setText("X");
        ui->toolButton_23->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_28->text() == "") {
        ui->toolButton_28->setText("X");
        ui->toolButton_28->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_28->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_34->text() == "X" && ui->toolButton_22->text() == "X" && ui->toolButton_27->text() == "X")
    {
        ui->toolButton_20->setText("O");
        ui->toolButton_20->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_22->text() == "X" && ui->toolButton_27->text() == "X" && ui->toolButton_20->text() == "X")
    {
        ui->toolButton_23->setText("O");
        ui->toolButton_23->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_27->text() == "X" && ui->toolButton_20->text() == "X" && ui->toolButton_23->text() == "X")
    {
        ui->toolButton_28->setText("O");
        ui->toolButton_28->setStyleSheet("background-color: blue");

    }


    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Horizontal check
    if (ui->toolButton_33->text() == "X" &&
            ui->toolButton_37->text() == "X" &&
            ui->toolButton_34->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_36->text() == "X" &&
            ui->toolButton_22->text() == "X" &&
            ui->toolButton_40->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_19->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_27->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_25->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_39->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_35->text() == "X" &&
            ui->toolButton_28->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
        if (ui->toolButton_34->text() == "X" &&
                ui->toolButton_22->text() == "X" &&
                ui->toolButton_27->text() == "X" &&
                ui->toolButton_20->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_22->text() == "X" &&
                ui->toolButton_27->text() == "X" &&
                ui->toolButton_20->text() == "X" &&
                ui->toolButton_23->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_27->text() == "X" &&
                ui->toolButton_20->text() == "X" &&
                ui->toolButton_23->text() == "X" &&
                ui->toolButton_28->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "X" &&
                ui->toolButton_20->text() == "X" &&
                ui->toolButton_27->text() == "X" &&
                ui->toolButton_22->text() == "X") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");
            ui->toolButton_9->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");
            ui->toolButton_19->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_7_clicked()
{
    if (ui->toolButton_37->text() == "") {
        ui->toolButton_37->setText("X");
        ui->toolButton_37->setStyleSheet("background-color: red");
    }
    else if (ui->toolButton_40->text() == "") {
        ui->toolButton_40->setText("X");
        ui->toolButton_40->setStyleSheet("background-color: red");
    }
    else if (ui->toolButton_38->text() == "") {
        ui->toolButton_38->setText("X");
        ui->toolButton_38->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_41->text() == "") {
        ui->toolButton_41->setText("X");
        ui->toolButton_41->setStyleSheet("background-color: red");
    }
    else if (ui->toolButton_39->text() == "") {
        ui->toolButton_39->setText("X");
        ui->toolButton_39->setStyleSheet("background-color: red");
    }
    else if (ui->toolButton_42->text() == "") {
        ui->toolButton_42->setText("X");
        ui->toolButton_42->setStyleSheet("background-color: red");
    }
    else if (ui->toolButton_42->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_37->text() == "X" && ui->toolButton_40->text() == "X" && ui->toolButton_38->text() == "X")
    {
        ui->toolButton_41->setText("O");
        ui->toolButton_41->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_40->text() == "X" && ui->toolButton_38->text() == "X" && ui->toolButton_41->text() == "X")
    {
        ui->toolButton_39->setText("O");
        ui->toolButton_39->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_38->text() == "X" && ui->toolButton_41->text() == "X" && ui->toolButton_39->text() == "X")
    {
        ui->toolButton_42->setText("O");
        ui->toolButton_42->setStyleSheet("background-color: blue");

    }

    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Horizontal check
    if (ui->toolButton_33->text() == "X" &&
            ui->toolButton_37->text() == "X" &&
            ui->toolButton_34->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_36->text() == "X" &&
            ui->toolButton_22->text() == "X" &&
            ui->toolButton_40->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_19->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_27->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_25->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_39->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_35->text() == "X" &&
            ui->toolButton_28->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_37->text() == "X" &&
            ui->toolButton_40->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_41->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_40->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_39->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_38->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_39->text() == "X" &&
            ui->toolButton_42->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_39->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_40->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }
        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_13->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_4->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_4->text() == "O" &&
                ui->toolButton->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_13->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }
        // Diagonal check
        if (ui->toolButton_42->text() == "O" &&
                ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_31->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_20->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_17->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_15->text() == "O" &&
                ui->toolButton_24->text() == "O" &&
                ui->toolButton_20->text() == "O" &&
                ui->toolButton_31->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Diagonal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_14->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_12->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_23->text() == "O" &&
                ui->toolButton_35->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","You Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_23->text() == "O" &&
                ui->toolButton_30->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_14->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

        // Horizontal check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_17->text() == "O" &&
                ui->toolButton_18->text() == "O" &&
                ui->toolButton_21->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_14->text() == "O" &&
                ui->toolButton_15->text() == "O" &&
                ui->toolButton_32->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_24->text() == "O" &&
                ui->toolButton_12->text() == "O" &&
                ui->toolButton_11->text() == "O" &&
                ui->toolButton_10->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_7->text() == "O" &&
                ui->toolButton_8->text() == "O" &&
                ui->toolButton_9->text() == "O" &&
                ui->toolButton_30->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_5->text() == "O" &&
                ui->toolButton_6->text() == "O" &&
                ui->toolButton_26->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton->text() == "O" &&
                ui->toolButton_2->text() == "O" &&
                ui->toolButton_3->text() == "O" &&
                ui->toolButton_29->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        // Vertical check
        if (ui->toolButton_16->text() == "O" &&
                ui->toolButton_13->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_13->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_4->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_10->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_4->text() == "O" &&
                ui->toolButton->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }
        if (ui->toolButton_4->text() == "O" &&
                ui->toolButton_7->text() == "O" &&
                ui->toolButton_10->text() == "O" &&
                ui->toolButton_13->text() == "O") {
            QMessageBox messageBox;
                    messageBox.critical(0,"Error","AI Won!");
                    messageBox.setFixedSize(500,200);
        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");

        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");
            ui->toolButton_19->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");

        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_6_clicked()
{
    if (ui->toolButton_33->text() == "") {
        ui->toolButton_33->setStyleSheet("background-color: red");
        ui->toolButton_33->setText("X");
    }
    else if (ui->toolButton_36->text() == "") {
        ui->toolButton_36->setStyleSheet("background-color: red");
        ui->toolButton_36->setText("X");
    }
    else if (ui->toolButton_19->text() == "") {
        ui->toolButton_19->setStyleSheet("background-color: red");
        ui->toolButton_19->setText("X");

    }

    else if (ui->toolButton_25->text() == "") {
        ui->toolButton_25->setText("X");
        ui->toolButton_25->setStyleSheet("background-color: red");

    }

    else if (ui->toolButton_31->text() == "") {
        ui->toolButton_31->setText("X");
        ui->toolButton_31->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_35->text() == "") {
        ui->toolButton_35->setText("X");
        ui->toolButton_35->setStyleSheet("background-color: red");

    }
    else if (ui->toolButton_35->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","This slot is full. Please select another slot");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() != "" && ui->toolButton_35->text() != ""&&
            ui->toolButton_28->text() != "" && ui->toolButton_29->text() != ""&&
            ui->toolButton_3->text() != "" && ui->toolButton_2->text() != "" &&
            ui->toolButton->text() != "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","It's Time to Start a New Game");
        messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_33->text() == "X" && ui->toolButton_36->text() == "X" && ui->toolButton_19->text() == "X")
    {
        ui->toolButton_25->setText("O");
        ui->toolButton_25->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_36->text() == "X" && ui->toolButton_19->text() == "X" && ui->toolButton_25->text() == "X")
    {
        ui->toolButton_31->setText("O");
        ui->toolButton_31->setStyleSheet("background-color: blue");

    }
    if (ui->toolButton_19->text() == "X" && ui->toolButton_25->text() == "X" && ui->toolButton_31->text() == "X")
    {
        ui->toolButton_35->setText("O");
        ui->toolButton_35->setStyleSheet("background-color: blue");

    }


    // Diagonal check
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_20->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_15->text() == "X" &&
            ui->toolButton_17->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_15->text() == "X" &&
            ui->toolButton_24->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Horizontal check
    if (ui->toolButton_33->text() == "X" &&
            ui->toolButton_37->text() == "X" &&
            ui->toolButton_34->text() == "X" &&
            ui->toolButton_21->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_36->text() == "X" &&
            ui->toolButton_22->text() == "X" &&
            ui->toolButton_40->text() == "X" &&
            ui->toolButton_32->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_19->text() == "X" &&
            ui->toolButton_38->text() == "X" &&
            ui->toolButton_27->text() == "X" &&
            ui->toolButton_24->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_25->text() == "X" &&
            ui->toolButton_41->text() == "X" &&
            ui->toolButton_20->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_39->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_26->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_42->text() == "X" &&
            ui->toolButton_35->text() == "X" &&
            ui->toolButton_28->text() == "X" &&
            ui->toolButton_29->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }

    // Diagonal check
    if (ui->toolButton_16->text() == "X" &&
            ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_14->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_12->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_23->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_23->text() == "X" &&
            ui->toolButton_30->text() == "X" &&
            ui->toolButton_12->text() == "X" &&
            ui->toolButton_14->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    // Vertical check
    if (ui->toolButton_33->text() == "X" &&
            ui->toolButton_36->text() == "X" &&
            ui->toolButton_19->text() == "X" &&
            ui->toolButton_25->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_36->text() == "X" &&
            ui->toolButton_19->text() == "X" &&
            ui->toolButton_25->text() == "X" &&
            ui->toolButton_31->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_19->text() == "X" &&
            ui->toolButton_25->text() == "X" &&
            ui->toolButton_31->text() == "X" &&
            ui->toolButton_35->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    if (ui->toolButton_31->text() == "X" &&
            ui->toolButton_25->text() == "X" &&
            ui->toolButton_19->text() == "X" &&
            ui->toolButton_36->text() == "X") {
        QMessageBox messageBox;
                messageBox.critical(0,"Error","You Won!");
                messageBox.setFixedSize(500,200);
    }
    int ai = rand()%7+1;
    cout<<ai;
    if (ai == 1) {

        if (ui->toolButton_16->text() == "") {
            ui->toolButton_16->setText("O");
            ui->toolButton_16->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_13->text() == "") {
            ui->toolButton_13->setText("O");
            ui->toolButton_13->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_10->text() == "") {
            ui->toolButton_10->setText("O");
            ui->toolButton_10->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_7->text() == "") {
            ui->toolButton_7->setText("O");
            ui->toolButton_7->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_4->text() == "") {
            ui->toolButton_4->setText("X");
            ui->toolButton_4->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton->text() == "") {
            ui->toolButton->setText("O");
            ui->toolButton->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 2) {

        if (ui->toolButton_17->text() == "") {
            ui->toolButton_17->setText("O");
            ui->toolButton_17->setStyleSheet("background-color: blue");

        }
        else if (ui->toolButton_14->text() == "") {
            ui->toolButton_14->setText("O");
            ui->toolButton_14->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_11->text() == "") {
            ui->toolButton_11->setText("O");
            ui->toolButton_11->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_8->text() == "") {
            ui->toolButton_8->setText("O");
            ui->toolButton_8->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_5->text() == "") {
            ui->toolButton_5->setText("O");
            ui->toolButton_5->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_2->text() == "") {
            ui->toolButton_2->setText("O");
            ui->toolButton_2->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 3) {

        if (ui->toolButton_18->text() == "") {
            ui->toolButton_18->setText("O");
            ui->toolButton_18->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_15->text() == "") {
            ui->toolButton_15->setText("O");
            ui->toolButton_15->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_12->text() == "") {
            ui->toolButton_12->setText("O");
            ui->toolButton_12->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_9->text() == "") {
            ui->toolButton_9->setText("O");
            ui->toolButton_9->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_6->text() == "") {
            ui->toolButton_6->setText("O");
            ui->toolButton_6->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_3->text() == "") {
            ui->toolButton_3->setText("O");
            ui->toolButton_3->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 4) {

        if (ui->toolButton_21->text() == "") {
            ui->toolButton_21->setText("O");
            ui->toolButton_21->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_32->text() == "") {
            ui->toolButton_32->setText("O");
            ui->toolButton_32->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_24->text() == "") {
            ui->toolButton_24->setText("O");
            ui->toolButton_24->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_30->text() == "") {
            ui->toolButton_30->setText("O");
            ui->toolButton_30->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_26->text() == "") {
            ui->toolButton_26->setText("O");
            ui->toolButton_26->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_29->text() == "") {
            ui->toolButton_29->setText("O");
            ui->toolButton_29->setStyleSheet("background-color: blue");

        }

    }
    else if (ai == 5) {

        if (ui->toolButton_34->text() == "") {
            ui->toolButton_34->setText("O");
            ui->toolButton_34->setStyleSheet("background-color: blue");


        }
        else if (ui->toolButton_22->text() == "") {
            ui->toolButton_22->setText("O");
            ui->toolButton_22->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_27->text() == "") {
            ui->toolButton_27->setText("O");
            ui->toolButton_27->setStyleSheet("background-color: blue");


        }

        else if (ui->toolButton_20->text() == "") {
            ui->toolButton_20->setText("O");
            ui->toolButton_20->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_23->text() == "") {
            ui->toolButton_23->setText("O");
            ui->toolButton_23->setStyleSheet("background-color: blue");

        }

        else if (ui->toolButton_28->text() == "") {
            ui->toolButton_28->setText("O");
            ui->toolButton_28->setStyleSheet("background-color: blue");

        }

    }

    else if (ai == 6) {

        if (ui->toolButton_33->text() == "") {
            ui->toolButton_33->setText("O");
            ui->toolButton_33->setStyleSheet("background-color: blue");
            board[5][5] = 2;

        }
        else if (ui->toolButton_36->text() == "") {
            ui->toolButton_36->setText("O");
            ui->toolButton_36->setStyleSheet("background-color: blue");
            board[4][5] = 2;

        }

        else if (ui->toolButton_19->text() == "") {
            ui->toolButton_19->setText("O");
            ui->toolButton_19->setStyleSheet("background-color: blue");
            board[3][5] = 2;

        }

        else if (ui->toolButton_25->text() == "") {
            ui->toolButton_25->setText("O");
            ui->toolButton_25->setStyleSheet("background-color: blue");
            board[2][5] = 2;

        }

        else if (ui->toolButton_31->text() == "") {
            ui->toolButton_31->setText("O");
            ui->toolButton_31->setStyleSheet("background-color: blue");
            board[1][5] = 2;

        }

        else if (ui->toolButton_35->text() == "") {
            ui->toolButton_35->setText("O");
            ui->toolButton_35->setStyleSheet("background-color: blue");
            board[0][5] = 2;

        }

    }
    else if (ai == 7) {

        if (ui->toolButton_37->text() == "") {
            ui->toolButton_37->setText("O");
            ui->toolButton_37->setStyleSheet("background-color: blue");
            board[5][6] = 2;


        }
        else if (ui->toolButton_40->text() == "") {
            ui->toolButton_40->setText("O");
            ui->toolButton_40->setStyleSheet("background-color: blue");
            board[4][6] = 2;
        }

        else if (ui->toolButton_38->text() == "") {
            ui->toolButton_38->setText("O");
            ui->toolButton_38->setStyleSheet("background-color: blue");
            board[3][6] = 2;

        }

        else if (ui->toolButton_41->text() == "") {
            ui->toolButton_41->setText("O");
            ui->toolButton_41->setStyleSheet("background-color: blue");
            board[2][6] = 2;

        }

        else if (ui->toolButton_39->text() == "") {
            ui->toolButton_39->setText("O");
            ui->toolButton_39->setStyleSheet("background-color: blue");
            board[1][6] = 2;

        }

        else if (ui->toolButton_42->text() == "") {
            ui->toolButton_42->setText("O");
            ui->toolButton_42->setStyleSheet("background-color: blue");
            board[0][6] = 2;
        }

    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
void Board::print_board() {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout<<"|";
            cout<< board[i][j];
            cout<<"|";
        }
        cout<<endl;
    }
}
/*——————————————————————————————————————————————-—————————————————————————————————————*/
int Board::processing(int choice) {
    int player1_id = 1;
    int player2_id = 2;

    int count = 0;
    int col = 0;
    int ai_col = 0;

    int j = 0;
    int i = 0;

    char go_again;

    Board boardgame;

    switch (choice) {
    case 1:
        boardgame.set_board();

        do {
            place_coin(col, player1_id,i,j);
            if (checker(i, j, 1,1) ||
                    checker(i, j, 1,0)||
                    checker(i, j, 0,1) ||
                    checker(i, j, -1,0) ||
                    checker(i, j, 0,-1) ||
                    checker(i, j, 1,-1) ||
                    checker(i, j, -1,1)) {
                boardgame.print_board();
                cout << "win" << endl;
                return 0;
            }
            if (ai_move(player2_id,ai_col)) {
                if  (checker(i, ai_col, 1,1) ||
                     checker(i,ai_col, 1,0)||
                     checker(i,ai_col, 0,1) ||
                     checker(i,ai_col, -1,0) ||
                     checker(i,ai_col, 0,-1) ||
                     checker(i,ai_col, 1,-1) ||
                     checker(i,ai_col, -1,1)){
                    boardgame.print_board();
                    cout << "win" << endl;
                    return 0;
                }

            }
            boardgame.print_board();
            go_again = 'y';
        } while (go_again == 'y' || go_again == 'Y');

        break;


    }
    return 1;
}

/*——————————————————————————————————————————————-—————————————————————————————————————*/
void MainWindow::on_pushButton_8_clicked()
{
    ui->toolButton->setText("");
    ui->toolButton->setStyleSheet("background-color: #F1F1F1");
    ui->toolButton_2->setText("");
    ui->toolButton_2->setStyleSheet("background-color: #F1F1F1");
    ui->toolButton_3->setText("");
    ui->toolButton_3->setStyleSheet("background-color: #F1F1F1");
    ui->toolButton_4->setText("");
    ui->toolButton_4->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_5->setText("");
    ui->toolButton_5->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_6->setText("");
    ui->toolButton_6->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_7->setText("");
    ui->toolButton_7->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_8->setText("");
    ui->toolButton_8->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_9->setText("");
    ui->toolButton_9->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_10->setText("");
    ui->toolButton_10->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_11->setText("");
    ui->toolButton_11->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_12->setText("");
    ui->toolButton_12->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_13->setText("");
    ui->toolButton_13->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_14->setText("");
    ui->toolButton_14->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_15->setText("");
    ui->toolButton_15->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_16->setText("");
    ui->toolButton_16->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_17->setText("");
    ui->toolButton_17->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_18->setText("");
    ui->toolButton_18->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_19->setText("");
    ui->toolButton_19->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_20->setText("");
    ui->toolButton_20->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_21->setText("");
    ui->toolButton_21->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_22->setText("");
    ui->toolButton_22->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_23->setText("");
    ui->toolButton_23->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_24->setText("");
    ui->toolButton_24->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_25->setText("");
    ui->toolButton_25->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_26->setText("");
    ui->toolButton_26->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_27->setText("");
    ui->toolButton_27->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_28->setText("");
    ui->toolButton_28->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_29->setText("");
    ui->toolButton_29->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_30->setText("");
    ui->toolButton_30->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_31->setText("");
    ui->toolButton_31->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_32->setText("");
    ui->toolButton_32->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_33->setText("");
    ui->toolButton_33->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_34->setText("");
    ui->toolButton_34->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_35->setText("");
    ui->toolButton_35->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_36->setText("");
    ui->toolButton_36->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_37->setText("");
    ui->toolButton_37->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_38->setText("");
    ui->toolButton_38->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_39->setText("");
    ui->toolButton_39->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_40->setText("");
    ui->toolButton_40->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_41->setText("");
    ui->toolButton_41->setStyleSheet("background-color: #F1F1F1");

    ui->toolButton_42->setText("");
    ui->toolButton_42->setStyleSheet("background-color: #F1F1F1");


}
void MainWindow::on_radioButton_clicked()
{

}

