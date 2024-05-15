#include "coffeewindow.h"
#include "ui_coffeewindow.h"

CoffeeWindow::CoffeeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CoffeeWindow)
{
    ui->setupUi(this);
}

CoffeeWindow::~CoffeeWindow()
{
    delete ui;
}
