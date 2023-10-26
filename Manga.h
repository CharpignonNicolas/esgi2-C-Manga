#ifndef MANGA_H
#define MANGA_H

// Définition de la structure Manga
typedef struct {
    char titre[50];
    int ageRequis;
    float prix;
} Manga;

// Fonction pour créer un manga en demandant à l'utilisateur de saisir les détails
Manga *creerManga();

// Fonction pour afficher les informations de tous les mangas stockés dans le tableau
void afficherManga(Manga **mangas, int taille);

// Fonction pour afficher les informations des mangas accessibles à partir de 16 ans
void afficherManga16(Manga **mangas, int taille);

// Fonction pour chercher un manga par son titre et renvoyer son prix
float chercherManga(Manga **mangas, int taille, char *titre);

// Nouvelle fonction pour ajouter les mangas préférés (Variante 1 : Tableau contenant des structures Manga)
Manga *ajouterMANGAPreferencesStructures(int n);

// Nouvelle fonction pour ajouter les mangas préférés (Variante 2 : Tableau contenant les adresses des structures Manga)
Manga **ajouterMANGAPreferencesAdresses(int n);

#endif
