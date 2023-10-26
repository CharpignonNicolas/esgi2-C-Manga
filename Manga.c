#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manga.h"

// Fonction pour créer un manga en demandant à l'utilisateur de saisir les détails
Manga *creerManga() {
    Manga *manga = malloc(sizeof(Manga));
    if (manga == NULL) {
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    printf("Veuillez saisir le titre du manga : ");
    scanf(" %[^\n]s", manga->titre);
    printf("Veuillez saisir l'âge requis pour le manga : ");
    scanf("%d", &manga->ageRequis);
    printf("Veuillez saisir le prix du manga : ");
    scanf("%f", &manga->prix);
    return manga;
}

// Fonction pour afficher les informations de tous les mangas stockés dans le tableau
void afficherManga(Manga **mangas, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("Le manga %s est pour les %d ans et coûte %.2f euros\n", mangas[i]->titre, mangas[i]->ageRequis, mangas[i]->prix);
    }
}

// Fonction pour afficher les informations des mangas accessibles à partir de 16 ans
void afficherManga16(Manga **mangas, int taille) {
    for (int i = 0; i < taille; i++) {
        if (mangas[i]->ageRequis >= 16) {
            printf("Le manga %s est pour les %d ans et coûte %.2f euros\n", mangas[i]->titre, mangas[i]->ageRequis, mangas[i]->prix);
        }
    }
}

// Fonction pour chercher un manga par son titre et renvoyer son prix
float chercherManga(Manga **mangas, int taille, char *titre) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(mangas[i]->titre, titre) == 0) {
            return mangas[i]->prix;
        }
    }
    return 0;
}

// Nouvelle fonction pour ajouter les mangas préférés (Variante 1 : Tableau contenant des structures Manga)
Manga *ajouterMANGAPreferencesStructures(int n) {
    Manga *preferences = (Manga *)malloc(n * sizeof(Manga));
    if (preferences == NULL) {
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        printf("Entrez le titre du manga préféré %d : ", i + 1);
        scanf(" %[^\n]s", preferences[i].titre);
        printf("Entrez l'âge requis pour le manga préféré %d : ", i + 1);
        scanf("%d", &preferences[i].ageRequis);
        printf("Entrez le prix du manga préféré %d : ", i + 1);
        scanf("%f", &preferences[i].prix);
    }
    return preferences;
}

// Nouvelle fonction pour ajouter les mangas préférés (Variante 2 : Tableau contenant les adresses des structures Manga)
Manga **ajouterMANGAPreferencesAdresses(int n) {
    Manga **preferences = (Manga **)malloc(n * sizeof(Manga *));
    if (preferences == NULL) {
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        preferences[i] = creerManga();
        if (preferences[i] == NULL) {
            // Gestion de l'erreur d'allocation de mémoire
            for (int j = 0; j < i; j++) {
                free(preferences[j]);
            }
            free(preferences);
            return NULL;
        }
    }
    return preferences;
}
