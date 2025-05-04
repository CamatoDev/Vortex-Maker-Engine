#include "pch.h"
#include "Unitest.h"
#include <stdio.h>
#include <string.h>

void Unitest::RegisterTest(const std::string& name, const std::string& description){
    //Enregistrement de tout les test à effetuer
    /*Créer une array qui vas repertorier le nombre de fonction enregistré pour le test.*/
}
void Unitest::InitTest(){
    //Initialisation des test 
}
void Unitest::Main(){
    //
}
void Unitest::RunAllTest(){
    
    // Affichage d'un message de bienvenue avec des couleurs et des sauts de ligne
    std::string message;
    message = "\n\n";
    message += "********************************************************\n";
    message += "**  Bienvenue dans l'application de tests unitaire !  **\n";
    message += "********************************************************\n\n";
    std::cout << message << "\n";

    // Exécution des tests
    /*Appeller chacune des fonctions les une après les autres.*/

    // Affichage d'un message de fin avec des couleurs et des sauts de ligne
    message = "\n\n";
    message += "********************************************************\n";
    message += "**  Tous les tests ont ete executes.  **\n";
    message += "********************************************************\n\n";

    std::cout << message << "\n";
}


// // Fonction addition
// int Addition(int a, int b) {
//     return a + b;
// }

// // Fonction sosutraction
// int Substract(int a, int b) {
//     return a - b;
// }

// // Fonction multiplication
// float Multiply(float a, float b) {
//     return a * b;
// }

// // Fonction division
// float Divide(float a, float b) {
//     return a / b;
// }

// void BasicTest::TestAdd(){
//     logger.Assert(Addition(2, 3) == 5, "Addition Failed");
//     logger.Assert(Addition(-1, 1) == 0, "Addition Failed");
//     logger.Assert(Addition(0, 0) == 0, "Addition Failed");
//     // Si tout les test sont reussie.
//     std::cout << "Test addition possitif !\n";
// }

// void BasicTest::TestSub(){
//     logger.Assert(Substract(10, 5) == 5, "Substract Failed");
//     logger.Assert(Substract(-1, 1) == -2, "Substract Failed");
//     logger.Assert(Substract(0, 0) == 0, "Substract Failed");
//     // Si tout les test sont reussie.
//     std::cout << "Test soustraction possitif !\n";
// }

// void BasicTest::TestMul(){
//     logger.Assert(Multiply(2, 3) == 6, "Multiply Failed");
//     logger.Assert(Multiply(-1, 1) == -1, "Multiply Failed");
//     logger.Assert(Multiply(0, 0) == 0, "Multiply Failed");
//     // Si tout les test sont reussie.
//     std::cout << "Test multication possitif !\n";
// }

// void BasicTest::TestDiv(){
//     logger.Assert(Divide(20, 5) == 4, "Divide Failed");
//     logger.Assert(Divide(-1, 1) == -1, "Divide Failed");
//     logger.Assert(Divide(0, 100) == 0, "Divide Failed");
//     // Si tout les test sont reussie.
//     std::cout << "Test division possitif !\n";
// }