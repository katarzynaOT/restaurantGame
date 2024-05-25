#include "coffeewindow.h"
#include "ui_coffeewindow.h"

#include <QFile> //QStringList
#include <QMessageBox>

#include <unistd.h> //time delay
unsigned int microsecond = 1000000;


QStringList coffeeList = { "Espresso", "Cappucino", "Mocha", "Americano", "ConPanna", "IrishCoffe" };

CoffeeWindow::CoffeeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoffeeWindow)
{
    ui->setupUi(this);

    //showing list of coffees in wigdet
    ui->listWidgetOfCoffies->addItems(coffeeList);

    //show graphic of coffee in graphic view
    Scene1 = new QGraphicsScene(this);
    Scene1 -> addPixmap(QPixmap(QCoreApplication::applicationDirPath() + "/esspresso1.jpg")); //image path
    ui -> graphicsView->setScene(Scene1);
}

CoffeeWindow::~CoffeeWindow()
{
    delete ui;
}

void WriteToFile(QString fileName, QString coffeeName)
{
    QFile mFile(fileName);
    if (!mFile.open(QFile::Append | QFile::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("This cannot be add to your list");
        //msgBox.setText("Could not open file to write");
        msgBox.setWindowTitle("Sorry :(");
        msgBox.exec();
        return;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Wait a couple of seconds for your coffee :) \nDon't leave Cofee Maker or someone will steal your order!");
        msgBox.setWindowTitle("Order taken");
        msgBox.exec();
    }
    QTextStream out(&mFile);
    out << coffeeName << "\n";

    mFile.flush();
    mFile.close();
}

void CoffeeWindow::add_first()
{
    WriteToFile("CoffeeFile.txt", coffeeList[0]);
    usleep(10 * microsecond);//sleeps for 3 second


}
