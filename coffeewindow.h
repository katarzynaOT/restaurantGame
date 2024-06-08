#ifndef COFFEEWINDOW_H
#define COFFEEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>
#include <QListWidget>
#include <QLabel>
#include <QCheckBox>

namespace Ui {
class CoffeeWindow;
}

class CoffeeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CoffeeWindow(QWidget *parent = nullptr);
    ~CoffeeWindow();

private:
    Ui::CoffeeWindow *ui;
    QGraphicsScene *Scene1; //displayalbe 2D image
    QLabel* labelPicOfCoffee;
    QListWidget* coffeeListWidget;
    QCheckBox* isCustomAvailable;

    QPushButton* addEsspressoButton;
    QPushButton* addCappucinoButton;
    QPushButton* addMochaButton;
    QPushButton* addAmericanoButton;
    QPushButton* addConPannaButton;
    QPushButton* addIrishCoffeeButton;
    QPushButton* customMadeButton;
    QPushButton* showOrderButton;


private slots:
    void addEsspresso();
    void addCappucino();
    void addMocha();
    void addAmericano();
    void addConPanna();
    void addIrishCoffee();
    void makeCustomMade();
    void showOrder();
};

#endif // COFFEEWINDOW_H
