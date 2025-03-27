#include <Unitest/Unitest.h>
#include <iostream>

#include <Logger/Log.h>
#include <string>


// Fonction addition
int Addition(int a, int b) {
    return a + b;
}

// Fonction sosutraction
int Substract(int a, int b) {
    return a - b;
}

// Fonction multiplication
float Multiply(float a, float b) {
    return a * b;
}

// Fonction division
float Divide(float a, float b) {
    return a / b;
}

#define logger logger__.Source()
Logger logger__("Test Unitest");
// Céation des fonction de test unitaire 

void TestAdd(){
    logger.Assert(Addition(2, 3) == 5, "Addition Failed");
    logger.Assert(Addition(-1, 1) == 0, "Addition Failed");
    logger.Assert(Addition(0, 0) == 0, "Addition Failed");
}

void TestSub(){
    logger.Assert(Substract(10, 5) == 5, "Substract Failed");
    logger.Assert(Substract(-1, 1) == -2, "Substract Failed");
    logger.Assert(Substract(0, 0) == 0, "Substract Failed");
}

void TestMul(){
    logger.Assert(Multiply(2, 3) == 6, "Multiply Failed");
    logger.Assert(Multiply(-1, 1) == -1, "Multiply Failed");
    logger.Assert(Multiply(0, 0) == 0, "Multiply Failed");
}

void TestDiv(){
    logger.Assert(Divide(20, 5) == 4, "Divide Failed");
    logger.Assert(Divide(-1, 1) == -1, "Divide Failed");
    logger.Assert(Divide(0, 100) == 0, "Divide Failed");
}


int main(int argc, char** argv) {
    
    // Ajout des cibles : Console, File et GUI simulé.
    logger.AddTarget(std::make_unique<ConsoleLogger>());
    logger.AddTarget(std::make_unique<FileLogger>("log.txt"));
    logger.AddTarget(std::make_unique<GuiLogger>());


    std::cout << "Hello World!!!\nJe suis dans TestUnitest\n";
    std::cout << "\n";

    // Lancement des tests
    TestAdd();
    TestSub();
    TestMul();
    TestDiv();

    // Si tout les test sont reussie.
    std::cout << "Tout les test sont possitif !\n";

    return 0;
}