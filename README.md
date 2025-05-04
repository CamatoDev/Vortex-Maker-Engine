# Vortex Maker Engine

🚀 **Un moteur de jeu C++ modulaire et multiplateforme**

Vortex Maker Engine est un moteur de jeu conçu pour être flexible, performant et adapté à la création de jeux vidéo sur plusieurs plateformes. Il est développé en C++ et intègre plusieurs fonctionnalités essentielles pour le développement de jeux.

## 📌 Fonctionnalités principales

✅ **Gestion des fenêtres et des entrées** 🖥️  
✅ **Rendu graphique** 🎨  
✅ **Gestion des textures et du chargement d'images** 🖼️  
✅ **Système de log (from scratch)** 📝 

Le moteur dispose d'un **système de log avancé** permettant un suivi efficace des événements et erreurs. Il prend en charge plusieurs niveaux de log :
- **DEBUG** : Informations utiles au débogage.
- **INFO** : Messages informatifs standards.
- **WARNING** : Indique un potentiel problème.
- **ERROR** : Signale une erreur ayant un impact sur l'exécution.
- **ASSERT** : Nouveau niveau de log permettant d'effectuer des **vérifications critiques** en développement.

💡 **Le système de log permet de récupérer les types de logs, les afficher au format défini, et facilitera l'analyse des logs ultérieurement.**

####  Système d'Assertion
Un **système d'assertion** a été intégré afin d'améliorer la robustesse du moteur en permettant de détecter des incohérences dès l'exécution du code. Les assertions déclenchent des logs et peuvent interrompre l'exécution en cas d'échec.

✅ **Tests Unitaires🔬**  
Un premier test unitaire a été ajouté pour vérifier les **opérations mathématiques de base** :
- Addition
- Soustraction
- Multiplication
- Division

✅ **Système ECS (Entity Component System)** 🎭  
✅ **Moteur physique** 🏗️  
✅ **Mathématiques avancées (vecteurs, matrices, transformations)** 📐  
✅ **Outils d'édition et debug intégrés** 🛠️  
✅ **Support de scripting (C++)** 🔄  
✅ **Gestion de projet avec Premake5** 🔧  

## 📂 Structure du projet

```
Vortex-Maker-Engine/
│-- Build/
│-- Core/
│   ├── Core/
│   ├── Logger/
│   ├── Unittest/
│-- Engine/
│   ├── VmEditor/
│   ├── VortexMakerEngine/
│-- External/
│   ├── Bin/
│   ├── Libs/
│   ├── Scripts/
│   ├── Tests/
│-- .gitignore
│-- build.bat
│-- clear.bat
│-- gen.bat
│-- LICENSE
│-- premake5.lua
│-- README.md
│-- run.bat
│-- VortexMakerEngine.sln
```

## 🛠️ Installation et Compilation

1. Clonez le dépôt :
   ```sh
   git clone https://github.com/CamatoDev/Vortex-Maker-Engine.git
   cd Vortex-Maker-Engine
   ```
2. Génération du projet avec Premake5 :
   ```sh
   ./gen.bat
   ```
3. Compilation du moteur :
   ```sh
   ./build.bat
   ```
4. Exécution du moteur :
   ```sh
   ./run.bat
   ```

## 📢 Contribution
Les contributions sont les bienvenues ! Si vous souhaitez participer, merci de consulter les issues ouvertes et de proposer vos améliorations.

## 📜 Licence
Vortex Maker Engine est sous licence **MIT**.
