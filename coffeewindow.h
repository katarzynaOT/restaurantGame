#ifndef COFFEEWINDOW_H
#define COFFEEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QDebug>
#include <QListWidget>

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
    QGraphicsScene *Scene1;

private slots:
    void add_first();
};

#endif // COFFEEWINDOW_H
