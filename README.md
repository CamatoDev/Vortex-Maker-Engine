# Vortex Maker Engine

🚀 **Vortex Maker Engine** est un moteur de jeu en C++ conçu pour être multiplateforme et extensible.

## 📜 Fonctionnalités principales

- 🖥️ **Gestion des fenêtres et des entrées**
- 🎨 **Rendu graphique** (OpenGL, SDL)
- 🖼️ **Chargement d'images et gestion des textures**
- 🛠️ **Interface utilisateur pour outils de debug et éditeur**
- 📝 **Formats de configuration et sauvegarde**
- 🔄 **Langages de scripting** (principalement C++)
- 🏗️ **Moteur physique**
- 📐 **Mathématiques et gestion des vecteurs/matrices** (développement d'une bibliothèque mathématique maison)
- 📝 **Système de log** (logger interne pour journalisation et gestion des erreurs)
- 🎭 **Système ECS (Entity Component System)** développé from scratch
- 🔧 **Gestion de projet et compilation** avec Premake5

## 📂 Structure du projet

```
VORTEX-MAKER-ENGINE/
│-- Build/
│-- Core/
│   │-- Pch/
│   │-- Src/
│   │-- Logger/
│   │-- Unittest/
│-- Engine/
│   │-- VmEditor/
│   │   │-- Src/
│   │-- VortexMakerEngine/
│   │   │-- Pch/
│   │   │-- Src/
│-- External/
│   │-- Bin/
│   │-- Libs/
│-- Scripts/
│-- Tests/
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

## 🚀 Installation et Utilisation

1. **Cloner le projet** :
   ```sh
   git clone https://github.com/votre-repo/VortexMakerEngine.git
   cd VortexMakerEngine
   ```
2. **Générer les fichiers du projet** :
   ```sh
   ./gen.bat
   ```
3. **Compiler le projet** :
   ```sh
   ./build.bat
   ```
4. **Exécuter le moteur** :
   ```sh
   ./run.bat
   ```

## 📜 Licence
Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

🔥 **Vortex Maker Engine est en développement actif !** Toute contribution est la bienvenue !

