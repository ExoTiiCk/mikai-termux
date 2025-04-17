#include <stdio.h>
#include <stdlib.h>
#include <mikai.h>
#include <nfc/nfc.h>

int main(void) {
    nfc_device *device = NULL;
    nfc_context *context;
    
    // Initialisation de libnfc
    nfc_init(&context);
    if (context == NULL) {
        printf("Erreur: Impossible d'initialiser libnfc\n");
        return EXIT_FAILURE;
    }

    // Ouverture du premier périphérique NFC trouvé
    device = nfc_open(context, NULL);
    if (device == NULL) {
        printf("Erreur: Aucun périphérique NFC trouvé\n");
        nfc_exit(context);
        return EXIT_FAILURE;
    }

    // Initialisation du périphérique
    if (nfc_initiator_init(device) < 0) {
        printf("Erreur: Impossible d'initialiser le périphérique NFC\n");
        nfc_close(device);
        nfc_exit(context);
        return EXIT_FAILURE;
    }

    printf("Périphérique NFC initialisé avec succès\n");
    printf("En attente d'une carte NFC...\n");

    // Configuration pour la détection de carte
    const nfc_modulation nm = {
        .nmt = NMT_ISO14443B,
        .nbr = NBR_106,
    };

    // Boucle de détection
    while (true) {
        if (nfc_initiator_select_passive_target(device, nm, NULL, 0, NULL) > 0) {
            printf("Carte détectée!\n");
            // Ici, vous pouvez ajouter votre logique de gestion de carte
            break;
        }
        usleep(100000); // Attente de 100ms
    }

    // Nettoyage
    nfc_close(device);
    nfc_exit(context);
    return EXIT_SUCCESS;
} 