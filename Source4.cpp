cpp
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

class CoffeeApp : public QApplication
{
public:
    CoffeeApp(int argc, char* argv[]) : QApplication(argc, argv)
    {
        QMenuBar* menuBar = new QMenuBar();
        QMenu* coffeeMenu = menuBar->addMenu("Coffee Menu");

        QAction* espressoAction = new QAction("Espresso", this);
        coffeeMenu->addAction(espressoAction);

        QAction* latteAction = new QAction("Latte", this);
        coffeeMenu->addAction(latteAction);

        connect(espressoAction, &QAction::triggered, this, &CoffeeApp::makeEspresso);
        connect(latteAction, &QAction::triggered, this, &CoffeeApp::makeLatte);

        setMenuBar(menuBar);
    }

    void makeEspresso()
    {
        if (checkIngredients("Espresso"))
        {
            QMessageBox::information(nullptr, "Coffee Maker", "Espresso can be made!");
        }
        else
        {
            QMessageBox::warning(nullptr, "Coffee Maker", "Not enough ingredients to make Espresso!");
        }
    }

    void makeLatte()
    {
        if (checkIngredients("Latte"))
        {
            QMessageBox::information(nullptr, "Coffee Maker", "Latte can be made!");
        }
        else
        {
            QMessageBox::warning(nullptr, "Coffee Maker", "Not enough ingredients to make Latte!");
        }
    }

    bool checkIngredients(const QString& coffeeType)
    {
        // Assume we have some logic here to check if there are enough ingredients for the selected coffee type
        // For demonstration purposes, let's assume we have enough ingredients for both Espresso and Latte
        return true;
    }
};

int main(int argc, char* argv[])
{
    CoffeeApp app(argc, argv);

    return app.exec();
}