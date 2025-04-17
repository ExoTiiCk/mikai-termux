# LibMIKAI pour Termux

Ce projet est une adaptation de LibMIKAI pour fonctionner sur Termux (Android).

## Installation rapide depuis GitHub

1. Ouvrez Termux
2. Exécutez les commandes suivantes :

```bash
# Installation des dépendances
pkg update
pkg install -y git cmake libnfc gcc make

# Récupération du projet
git clone https://github.com/votre-username/mikai.git
cd mikai

# Installation
chmod +x install-termux.sh
./install-termux.sh
```

## Installation manuelle

Si vous préférez installer manuellement :

1. Ouvrez Termux
2. Installez les dépendances :
```bash
pkg update
pkg install -y cmake libnfc gcc make git
```

3. Clonez le dépôt :
```bash
git clone https://github.com/votre-username/mikai.git
cd mikai
```

4. Compilez et installez :
```bash
mkdir build && cd build
cmake ..
make
make install
```

## Configuration NFC

Pour utiliser la fonctionnalité NFC sur Termux, vous devez :

1. Accorder les permissions NFC à Termux dans les paramètres Android
2. Vérifier que votre appareil est compatible avec libnfc :
```bash
nfc-list
```

## Utilisation

Pour utiliser la bibliothèque dans vos projets :

1. Inclure l'en-tête :
```c
#include <mikai.h>
```

2. Lier avec la bibliothèque lors de la compilation :
```bash
gcc votre_programme.c -lmikai
```

## Mise à jour

Pour mettre à jour depuis GitHub :

```bash
cd ~/mikai
git pull
./install-termux.sh
```

## Dépannage

Si vous rencontrez des problèmes :

1. Vérifiez que libnfc est correctement installé :
```bash
pkg list-installed | grep libnfc
```

2. Vérifiez les permissions NFC :
```bash
termux-nfc-scan
```

3. Si nécessaire, réinstallez les dépendances :
```bash
pkg reinstall libnfc
```

## Notes importantes

- Cette version est optimisée pour fonctionner sur Android via Termux
- Certaines fonctionnalités peuvent être limitées selon le matériel NFC de votre appareil
- Assurez-vous d'avoir les dernières mises à jour de Termux et des paquets

## Support

Pour toute question ou problème, veuillez ouvrir une issue sur le dépôt GitHub du projet. 