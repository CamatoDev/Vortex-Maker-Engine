#include <Unitest/Unitest.h>
#include <iostream>

#include <Logger/Log.h>
#include <string>

int main(int argc, char** argv) {
    
    // Ajout des cibles : Console, File et GUI simulé.
    logger.AddTarget(std::make_unique<ConsoleLogger>());
    logger.AddTarget(std::make_unique<FileLogger>("log.txt"));
    logger.AddTarget(std::make_unique<GuiLogger>());


    std::cout << "Hello World!!!\nJe suis dans TestUnitest\n";
    std::cout << "\n";

    BasicTest *unitest = new BasicTest();

    // Lancement des tests
    unitest->TestAdd();
    unitest->TestSub();
    unitest->TestMul();
    unitest->TestDiv();

    std::cout << "\n";

    // Si tout les test sont reussie.
    std::cout << "Tout les test sont possitif !\n";

    return 0;
}