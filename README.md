# Vortex Maker Engine

🚀 **Un moteur de jeu C++ modulaire et multiplateforme**

Vortex Maker Engine est un moteur de jeu conçu pour être flexible, performant et adapté à la création de jeux vidéo sur plusieurs plateformes. Il est développé en C++ et intègre plusieurs fonctionnalités essentielles pour le développement de jeux.

## 📌 Fonctionnalités principales

✅ **Gestion des fenêtres et des entrées** 🖥️  
✅ **Rendu graphique** (OpenGL, SDL) 🎨  
✅ **Gestion des textures et du chargement d'images** 🖼️  
✅ **Système de log (from scratch)** 📝  
   - Supporte plusieurs niveaux de sévérité : `TRACE`, `ASSERT`, `INFO`, `DEBUG`, `WARNING`, `ERROR`, `CRITICAL`, `FATAL`
   - Méthodes pour récupérer les types de logs
   - Affichage des logs dans un format défini
   - Préparation pour l'analyse avancée des logs
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
   git clone <repo_url>
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
