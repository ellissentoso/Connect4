#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    return a.exec();
}
