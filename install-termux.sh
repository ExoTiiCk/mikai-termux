#!/data/data/com.termux/files/usr/bin/bash

# Mise à jour des paquets
pkg update -y
pkg upgrade -y

# Installation des dépendances
pkg install -y cmake
pkg install -y libnfc
pkg install -y llvm
pkg install -y make
pkg install -y git

# Clonage du projet (si nécessaire)
# git clone [URL_DU_PROJET]

# Création du dossier de build
mkdir -p build
cd build

# Configuration et compilation
cmake ..
make

# Installation
make install

echo "Installation terminée !"
echo "Pour utiliser la bibliothèque, assurez-vous d'avoir les permissions NFC nécessaires." 