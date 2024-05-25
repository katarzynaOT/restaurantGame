#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "coffeewindow.h"

#include <QStringList>
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Scene = new QGraphicsScene(this);
    //Scene ->addPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/esspresso1.jpg")); //image path
    //ui -> graphicsView->setScene(Scene);
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

    //the working code:
    CoffeeWindow coffeeWindow;
    coffeeWindow.setModal(true);
    coffeeWindow.exec();
}

/*
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
*/
