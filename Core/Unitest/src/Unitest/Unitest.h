#ifndef __UNITEST_UNITEST_H__
#define __UNITEST_UNITEST_H__

#include "Logger/Log.h"

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

    }
        // Céation des fonction de test unitaire 
        void TestAdd(){
            logger.Assert(Addition(2, 3) == 5, "Addition Failed");
            logger.Assert(Addition(-1, 1) == 0, "Addition Failed");
            logger.Assert(Addition(0, 0) == 0, "Addition Failed");
            // Si tout les test sont reussie.
            std::cout << "Test addition possitif !\n";
        }
        
        void TestSub(){
            logger.Assert(Substract(10, 5) == 5, "Substract Failed");
            logger.Assert(Substract(-1, 1) == -2, "Substract Failed");
            logger.Assert(Substract(0, 0) == 0, "Substract Failed");
            // Si tout les test sont reussie.
            std::cout << "Test soustraction possitif !\n";
        }
        
        void TestMul(){
            logger.Assert(Multiply(2, 3) == 6, "Multiply Failed");
            logger.Assert(Multiply(-1, 1) == -1, "Multiply Failed");
            logger.Assert(Multiply(0, 0) == 0, "Multiply Failed");
            // Si tout les test sont reussie.
            std::cout << "Test multication possitif !\n";
        }
        
        void TestDiv(){
            logger.Assert(Divide(20, 5) == 4, "Divide Failed");
            logger.Assert(Divide(-1, 1) == -1, "Divide Failed");
            logger.Assert(Divide(0, 100) == 0, "Divide Failed");
            // Si tout les test sont reussie.
            std::cout << "Test division possitif !\n";
        }
};


#endif  // __UNITEST_UNITEST_H__"