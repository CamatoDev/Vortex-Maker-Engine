#include <VortexMakerEngine/VortexMakerEngine.h>
#include <iostream>

#include <Logger/Log.h>
#include <string>

#define logger logger__.Source()
Logger logger__("Unkeny Editor");

int main() {
    // Ajout des cibles : Console, File et GUI simulé.
    logger.AddTarget(std::make_unique<ConsoleLogger>());
    logger.AddTarget(std::make_unique<FileLogger>("log.txt"));
    logger.AddTarget(std::make_unique<GuiLogger>());

    int Valeur = 42;
    std::string Utilisateur = "Alice";

    // Appels directs : std::source_location est capturé automatiquement,
    // ou via la méthode Source() si besoin.
    logger.Debug("Valeur de {0} pour l'utilisateur {1}", Valeur, Utilisateur);
    logger.Info("Initialisation du système avec l'ID {0}", 12345);
    logger.Warning("Attention : la variable {0} dépasse la limite de {1}", "température", 100);
    logger.Error("Erreur critique dans le module {0} : code {1}", "auth", -1);

    // Test du assert
    int x = 6;
    int y = 3;

    logger.Assert(y != 0, "Erreur : Division par 0 impossible !");
    int z = x / y;
    std::cout << "Le resultat est : " << z << "\n";

    return 0;
}