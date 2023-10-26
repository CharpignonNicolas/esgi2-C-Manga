#include <stdio.h>
#include <stdlib.h>
#include "Manga.h"

int main() {
    Manga **mangas = NULL;
    int taille = 0;

    // Utilisation de la nouvelle fonction pour ajouter les mangas préférés (Variante 1)
    int n;
    printf("Combien de mangas preferes souhaitez-vous ajouter (Variante 1) ? ");
    scanf("%d", &n);
    Manga *preferencesStructures = ajouterMANGAPreferencesStructures(n);

    // Utilisation de la nouvelle fonction pour ajouter les mangas préférés (Variante 2)
    int m;
    printf("Combien de mangas prefere souhaitez-vous ajouter (Variante 2) ? ");
    scanf("%d", &m);
    Manga **preferencesAdresses = ajouterMANGAPreferencesAdresses(m);

    // Libération de la mémoire pour les mangas préférés (Variante 1)
    if (preferencesStructures != NULL) {
        free(preferencesStructures);
    }

    // Libération de la mémoire pour les mangas préférés (Variante 2)
    if (preferencesAdresses != NULL) {
        for (int i = 0; i < m; i++) {
            free(preferencesAdresses[i]);
        }
        free(preferencesAdresses);
    }

    // Libération de la mémoire pour les mangas saisis
    if (mangas != NULL) {
        for (int i = 0; i < taille; i++) {
            free(mangas[i]);
        }
        free(mangas);
    }

    return 0;
}
