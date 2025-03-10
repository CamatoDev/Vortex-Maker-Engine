#include <VortexMakerEngine/VortexMakerEngine.h>
#include <Logger/Logger.h>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::cout << "Hello World!!!\nJe suis dans VMeditor\n";

    Logger logger("Bob");

    logger.Trace("Bonjour");
    logger.Assert("Bonjour");
    logger.Debug("Bonjour");
    logger.Info("Bonjour");
    logger.Warning("Bonjour");
    logger.Error("Bonjour");
    logger.Critical("Bonjour");
    logger.Fatal("Bonjour");

    return 0;
}