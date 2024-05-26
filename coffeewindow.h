#ifndef COFFEEWINDOW_H
#define COFFEEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>


namespace Ui {
class CoffeeWindow;
}

class CoffeeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CoffeeWindow(QWidget *parent = nullptr);
    ~CoffeeWindow();
    ///Ui::CoffeeWindow *ui; ///

private:
    Ui::CoffeeWindow *ui;
    QGraphicsScene *Scene1; //displayalbe 2D image
    //QGraphicsEllipseItem *Ellipse;
    //QGraphicsRectItem *Rectangle;

private slots:
    void add_1();
    void add_2();
    void add_3();
    void add_4();
    void add_5();
    void add_6();
    void showOrder();
};

#endif // COFFEEWINDOW_H
