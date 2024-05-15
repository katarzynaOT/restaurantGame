//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>  //!!klasa string jest czescia podprzestrzeni std
//using namespace std;

struct Coffee
{
    //std::string name;
    float steamedMilk, milkFoam, cream, whiskey, espresso, water, chocolate;
    bool whippedCream;
};

Coffee Espresso = { 0, 0, 0, 0, 1, 0, 0, 0 };
Coffee Cappucino = { 0.3, 0.3, 0, 0, 0.3, 0, 0, 0 };
Coffee Mocha = { 0.25, 0.25, 0, 0, 0.25, 0, 0.25, 1 };
Coffee Americano = { 0, 0, 0, 0, 0.3, 0.7, 0, 0 };
Coffee ConPanna = { 0, 0, 0.7, 0, 0.3, 0, 0, 0 };
Coffee IrishCoffe = { 0, 0, 0.4, 0.3, 0.3, 0, 0, 0 };

Coffee tabOfCoffies[6] = { Espresso, Cappucino, Mocha, Americano, ConPanna, IrishCoffe };
