#include "mainwindow.h"
#include <QtWidgets/QApplication>

#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
