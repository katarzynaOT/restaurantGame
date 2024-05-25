#include <iostream>
#include <string>

void zamowKawe() {
    std::cout << "Witaj! Jak? kaw? chcia?by? dzisiaj zamówi??" << std::endl;
    std::cout << "1. Espresso" << std::endl;
    std::cout << "2. Latte" << std::endl;
    std::cout << "3. ConPanna" << std::endl;
    std::cout << "4. Americano" << std::endl;
    std::cout << "5. Mocha" << std::endl;
    std::cout << "6. IrishCoffee" << std::endl;
    std::cout << "Prosz? wybierz numer odpowiadaj?cy twojej kawie: ";

    int wybor;
    std::cin >> wybor;

    std::string kawa;

    switch (wybor) {
    case 1:
        kawa = "Espresso";
        break;
    case 2:
        kawa = "Latte";
        break;
    case 3:
        kawa = "Cappuccino";
        break;
    case 4:
        kawa = "Americano";
        break;
    case 5:
        kawa = "Mocha";
        break;
    case 6:
        std::cout << "Prosz? podaj nazw? kawy: ";
        std::cin.ignore(); 
        std::getline(std::cin, kawa);
        break;
    default:
        std::cout << "Nieprawid?owy wybór, prosz? spróbuj ponownie." << std::endl;
        return; 
    }

    std::cout << "Wybra?e? kaw?: " << kawa << std::endl;
}

int main() {
    zamowKawe();
    return 0;
}


