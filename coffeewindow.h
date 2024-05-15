#ifndef COFFEEWINDOW_H
#define COFFEEWINDOW_H

#include <QDialog>

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
};

#endif // COFFEEWINDOW_H
