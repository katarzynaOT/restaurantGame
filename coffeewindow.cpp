#include "coffeewindow.h"
#include "ui_coffeewindow.h"

#include <QFile> //QStringList
#include <QMessageBox>
#include <QPixmap> //pixmap for image in label

#include <unistd.h> //time delay
unsigned int microsecond = 1000000;

QStringList coffeeList = { "Espresso", "Cappucino", "Mocha", "Americano", "ConPanna", "IrishCoffe", "Custom Made - non available" };

CoffeeWindow::CoffeeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoffeeWindow)
{
    ui->setupUi(this);

    //clearing the file for coffies
    QFile mFile("CoffeeFile.txt");
    mFile.resize(0); //clear the file
    mFile.close();

    //showing list of coffees in wigdet
    ui->listWidgetOfCoffies->addItems(coffeeList);

    //adding image to label (labelPicOfCoffee) + rescaling (changins sizes)
    QPixmap pix(QCoreApplication::applicationDirPath() + "/coffee1.jpg"); //image path (/build/Destop..)
    ui->labelPicOfCoffee->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio)); //showing image + rescaling

}

CoffeeWindow::~CoffeeWindow()
{
    delete ui;
}

void WriteToFile(QString fileName, QString coffeeName)
{
    QFile mFile(fileName);
    if (!mFile.open(QFile::Append | QFile::Text)) //couldn't open file, send a message
    {
        QMessageBox msgBox;
        msgBox.setText("This cannot be add to your list");
        //msgBox.setText("Could not open file to write");
        msgBox.setWindowTitle("Sorry :(");
        msgBox.exec();
        return;
    }
    else //file opened succesfully, send a message
    {
        QMessageBox msgBox;
        msgBox.setText("Wait a couple of seconds for your coffee :)");
        msgBox.setWindowTitle("Order taken");
        msgBox.exec();
        usleep(3 * microsecond);//sleeps for 3 second
    }

    QTextStream out(&mFile);
    out << coffeeName << "\n";

    mFile.flush();
    mFile.close();
}

void ReadFromFile(QString fileName)
{
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("You cannot see your order right now");
        msgBox.setWindowTitle("Sorry :(");
        msgBox.exec();
        return;
    }
    QTextStream in(&mFile);
    QString mText = in.readAll();

    QMessageBox msgBox;
    msgBox.setText(mText);
    msgBox.setWindowTitle("order");
    msgBox.exec();

    mFile.close();
}

void CoffeeWindow::showOrder()
{
    ReadFromFile("CoffeeFile.txt");
}

void CoffeeWindow::add_1() //first coffe chosen
{
    WriteToFile("CoffeeFile.txt", coffeeList[0]);
}

void CoffeeWindow::add_2()
{
    WriteToFile("CoffeeFile.txt", coffeeList[1]);
}

void CoffeeWindow::add_3()
{
    WriteToFile("CoffeeFile.txt", coffeeList[2]);
}

void CoffeeWindow::add_4()
{
    WriteToFile("CoffeeFile.txt", coffeeList[3]);
}

void CoffeeWindow::add_5()
{
    WriteToFile("CoffeeFile.txt", coffeeList[4]);
}

void CoffeeWindow::add_6()
{
    WriteToFile("CoffeeFile.txt", coffeeList[5]);
}

