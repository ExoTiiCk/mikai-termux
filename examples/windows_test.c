#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Structure simulée pour les données NFC
typedef struct {
    char uid[8];
    int type;
    char data[256];
} nfc_card;

// Fonction simulée de détection de carte
int detect_nfc_card(nfc_card *card) {
    printf("Simulation de détection de carte NFC...\n");
    
    // Simulation d'une carte détectée après 3 secondes
    Sleep(3000);
    
    // Données de test
    strcpy(card->uid, "A1B2C3D4");
    card->type = 1;
    strcpy(card->data, "Données de test de la carte NFC");
    
    return 1; // Succès
}

int main(void) {
    printf("Démarrage du test NFC sous Windows...\n");
    printf("Ce programme simule le fonctionnement d'un lecteur NFC.\n\n");
    
    nfc_card card;
    
    printf("En attente d'une carte NFC...\n");
    printf("(Simulation - appuyez sur Ctrl+C pour quitter)\n\n");
    
    while (1) {
        if (detect_nfc_card(&card)) {
            printf("\nCarte détectée !\n");
            printf("UID: %s\n", card.uid);
            printf("Type: %d\n", card.type);
            printf("Données: %s\n\n", card.data);
            
            printf("En attente d'une nouvelle carte...\n");
        }
        
        Sleep(1000); // Attente d'une seconde
    }
    
    return 0;
} 