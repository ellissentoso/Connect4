#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

using namespace std;

const int COL = 6;
const int ROW = 7;
const int MAX = 9999999;

class Board {
public:
    int digit_pressed();
    int clear_board();

    void set_board();
    void print_board();
    void menu(int& choice);

    bool checker(int row, int col, int add_row, int add_col);
    bool isColAvailable(int column);

    bool place_coin(int col, int& player_id, int &i, int &j);
    bool ai_move(int ai_id, int ai_column);

    int processing(int choice);


    private:

        int board[ROW][COL];

};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Board screen;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_radioButton_clicked();



private:

    Ui::MainWindow *ui;
    int board[ROW][COL];

public slots:

};

#endif // MAINWINDOW_H
