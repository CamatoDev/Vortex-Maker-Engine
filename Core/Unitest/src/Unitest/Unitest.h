#ifndef __UNITEST_UNITEST_H__
#define __UNITEST_UNITEST_H__

#include "Logger/Log.h"
#include <string.h>

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



class CORE_API BasicTest{
    public:
    BasicTest(){
        TestAdd();
        TestSub();
        TestMul();
        TestDiv();
    }
        // Céation des fonction de test unitaire 
        void TestAdd(){
            logger.AssertFalse(Addition(2, 3) == 5, "Addition Failed");
            logger.AssertFalse(Addition(-1, 1) == 0, "Addition Failed");
            logger.AssertFalse(Addition(0, 0) == 0, "Addition Failed");
            // Si tout les test sont reussie.
            std::cout << "Test addition possitif !\n";
        }
        
        void TestSub(){
            logger.AssertFalse(Substract(10, 5) == 5, "Substract Failed");
            logger.AssertFalse(Substract(-1, 1) == -2, "Substract Failed");
            logger.AssertFalse(Substract(0, 0) == 0, "Substract Failed");
            // Si tout les test sont reussie.
            std::cout << "Test soustraction possitif !\n";
        }
        
        void TestMul(){
            logger.AssertFalse(Multiply(2, 3) == 6, "Multiply Failed");
            logger.AssertFalse(Multiply(-1, 1) == -1, "Multiply Failed");
            logger.AssertFalse(Multiply(0, 0) == 0, "Multiply Failed");
            // Si tout les test sont reussie.
            std::cout << "Test multication possitif !\n";
        }
        
        void TestDiv(){
            logger.AssertFalse(Divide(20, 5) == 4, "Divide Failed");
            logger.AssertFalse(Divide(-1, 1) == -1, "Divide Failed");
            logger.AssertFalse(Divide(0, 100) == 0, "Divide Failed");
            // Si tout les test sont reussie.
            std::cout << "Test division possitif !\n";
        }
};

class CORE_API Unitest{
    public:
        // Constructeur de la classe 
        Unitest();

        void RegisterTest(const std::string& name, const std::string& description = "");
        void InitTest();
        void Main();
        void RunAllTest();
    
        private:
            int _test_number;
            std::string _myTest[0];
};


#endif  // __UNITEST_UNITEST_H__"

/* Créer une classe registre qui vas aider à repertorier tout les tests, leurs nombre, donner 
le nombre de test réussi et le nombre de test echoué.*/
/* Penser à modifier le système d'assert pour avoir les tests réusies en vert et les echecs en rouge.*/

/*Pointeur de fonction en C et C++ - distictionnaire*/