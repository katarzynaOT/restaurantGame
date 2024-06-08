#include "coffeewindow.h"
#include "ui_coffeewindow.h"

#include <QFile> //QStringList
#include <QMessageBox>
#include <QPixmap> //pixmap for image in label
#include <QWidget>
#include <QBoxLayout>

#include <unistd.h> //time delay
unsigned int microsecond = 1000000;

QStringList coffeeList = { "Espresso", "Cappucino", "Mocha", "Americano", "ConPanna", "IrishCoffee", "Custom Made - non available" };

CoffeeWindow::CoffeeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoffeeWindow)
{
    ui->setupUi(this);

    coffeeListWidget = new QListWidget(this);
    addEsspressoButton = new QPushButton("order Espresso", this);
    addCappucinoButton = new QPushButton("order Cappucino", this);
    addMochaButton = new QPushButton("order Mocha", this);
    addAmericanoButton = new QPushButton("order Americano", this);
    addConPannaButton = new QPushButton("order ConPanna", this);
    addIrishCoffeeButton = new QPushButton("order IrishCoffee", this);
    customMadeButton = new QPushButton("make custom made coffee", this);
    showOrderButton = new QPushButton("show order", this);
    labelPicOfCoffee = new QLabel();
    isCustomAvailable = new QCheckBox();

    connect(addEsspressoButton, &QPushButton::clicked, this, &CoffeeWindow::addEsspresso);
    connect(addCappucinoButton, &QPushButton::clicked, this, &CoffeeWindow::addCappucino);
    connect(addMochaButton, &QPushButton::clicked, this, &CoffeeWindow::addMocha);
    connect(addAmericanoButton, &QPushButton::clicked, this, &CoffeeWindow::addAmericano);
    connect(addConPannaButton, &QPushButton::clicked, this, &CoffeeWindow::addConPanna);
    connect(addIrishCoffeeButton, &QPushButton::clicked, this, &CoffeeWindow::addIrishCoffee);
    connect(customMadeButton, &QPushButton::clicked, this, &CoffeeWindow::makeCustomMade);
    connect(showOrderButton, &QPushButton::clicked, this, &CoffeeWindow::showOrder);

    //adding image to label (labelPicOfCoffee) + rescaling (changins sizes)
    QPixmap pix(QCoreApplication::applicationDirPath() + "/coffee1.jpg"); //image path (/build/Destop..)
    labelPicOfCoffee->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio)); //showing image + rescaling
    labelPicOfCoffee->setAlignment(Qt::AlignCenter);

    //showing list of coffees in wigdet
    coffeeListWidget->addItems(coffeeList);

    QBoxLayout* firstLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    firstLayout->addWidget(coffeeListWidget);
    firstLayout->addWidget(addEsspressoButton);
    firstLayout->addWidget(addCappucinoButton);
    firstLayout->addWidget(addMochaButton);
    firstLayout->addWidget(addAmericanoButton);
    firstLayout->addWidget(addConPannaButton);
    firstLayout->addWidget(addIrishCoffeeButton);
    firstLayout->addWidget(customMadeButton);
    firstLayout->addWidget(labelPicOfCoffee, Qt::AlignCenter);
    firstLayout->addWidget(showOrderButton);
    firstLayout->addWidget(new QLabel("Do you want to make Custom Coffee option work?"));
    firstLayout->addWidget(isCustomAvailable, Qt::AlignCenter);
    setLayout(firstLayout);

    setWindowTitle("COFFEE");

    //clearing the file for coffees
    QFile mFile("CoffeeFile.txt");
    mFile.resize(0); //clear the file
    mFile.close();
}

CoffeeWindow::~CoffeeWindow()
{
    exit(0);
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
    try
    {
        QFile mFile(fileName);
        if (!mFile.open(QFile::ReadOnly | QFile::Text))
        {
            throw(fileName);
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
    catch(QString fileName)
    {
        QMessageBox msgBox;
        msgBox.setText("The file holding your order: " + fileName + " is not opening");
        msgBox.setWindowTitle("Sorry :(");
        msgBox.exec();
    }
}

void CoffeeWindow::makeCustomMade()
{
    if (isCustomAvailable->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setText("Your coffee will be custom made later");
        msgBox.setWindowTitle("Custom Coffee Information");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("This option is not available for now");
        msgBox.setWindowTitle("Custom Coffee Information");
        msgBox.exec();
    }
}

void CoffeeWindow::showOrder()
{
    ReadFromFile("CoffeeFile.txt");
}

void CoffeeWindow::addEsspresso() //first coffee chosen
{
    WriteToFile("CoffeeFile.txt", coffeeList[0]);
}

void CoffeeWindow::addCappucino()
{
    WriteToFile("CoffeeFile.txt", coffeeList[1]);
}

void CoffeeWindow::addMocha()
{
    WriteToFile("CoffeeFile.txt", coffeeList[2]);
}

void CoffeeWindow::addAmericano()
{
    WriteToFile("CoffeeFile.txt", coffeeList[3]);
}

void CoffeeWindow::addConPanna()
{
    WriteToFile("CoffeeFile.txt", coffeeList[4]);
}

void CoffeeWindow::addIrishCoffee()
{
    WriteToFile("CoffeeFile.txt", coffeeList[5]);
}

