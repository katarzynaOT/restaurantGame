#include "coffeewindow.h"
#include "ui_coffeewindow.h"

#include <QFile> //QStringList
#include <QMessageBox>

QStringList coffeeList = { "Espresso", "Cappucino", "Mocha", "Americano", "ConPanna", "IrishCoffe" };

CoffeeWindow::CoffeeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoffeeWindow)
{
    ui->setupUi(this);

    //showing list of coffees in wigdet
    ui->listWidgetOfCoffies->addItems(coffeeList);
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
    QTextStream out(&mFile);
    out << coffeeName << "\n";

    mFile.flush();
    mFile.close();
}
