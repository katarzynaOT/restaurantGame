#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "coffeewindow.h"

#include <QStringList>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

QStringList coffeeList = { "Espresso", "Cappucino", "Mocha", "Americano", "ConPanna", "IrishCoffe" };


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //showing list of coffees in wigdet
    ui->listWidget->addItems(coffeeList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GoToCoffeeWindow()
{
    //stack memmory:
    //Coff coff;
    //coff.setModal(true); //open dialog window
    //coff.exec(); //show dialog window

    //heap memory:
    //cof = new CoffeeWindow(this);
    //cof->show();

    CoffeeWindow coffeeWindow;
    coffeeWindow.setModal(true);
    coffeeWindow.exec();
}

void MainWindow::Button1_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Klikniety");
    msgBox.setWindowTitle("Komunikat");
    msgBox.exec();
}

void WriteToFile(QString fileName)
{
    QFile mFile(fileName);
    if (!mFile.open(QFile::Append | QFile::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("Could not open file to write");
        msgBox.setWindowTitle("error");
        msgBox.exec();
        return;
    }
    QTextStream out(&mFile);
    out << "dane do zapisania";

    mFile.flush();
    mFile.close();
}

void ReadFromFile(QString fileName)
{
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for reading";
        return;
    }
    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.close();
}