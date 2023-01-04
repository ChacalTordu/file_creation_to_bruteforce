#include <stdio.h>
#include <string.h>

// Fonction récursive qui génère toutes les combinaisons de chaînes de caractères de taille n
void genererCombinaisons(char* combinaisonActuelle, int n, FILE* fichier) {
    // Si n est égal à 0, cela signifie que nous avons atteint la fin de la chaîne de caractères,
    // donc nous pouvons écrire la combinaison actuelle dans le fichier
    if (n == 0) {
        fprintf(fichier, "%s\n", combinaisonActuelle);
        return;
    }

    // Pour chaque lettre de l'alphabet, ajoutez-la à la combinaison actuelle et appelez la fonction récursive
    for (char c = 'a'; c <= 'z'; c++) {
        combinaisonActuelle[strlen(combinaisonActuelle)] = c;
        genererCombinaisons(combinaisonActuelle, n - 1, fichier);
        combinaisonActuelle[strlen(combinaisonActuelle) - 1] = '\0';
    }
}

int main() {
    // Ouvrez le fichier en mode écriture
    FILE* fichier = fopen("combinaisons.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    // Allouez de la mémoire pour la chaîne de caractères de combinaison actuelle
    char* combinaisonActuelle = malloc(7 * sizeof(char));
    combinaisonActuelle[6] = '\0';

    // Appelez la fonction récursive
    genererCombinaisons(combinaisonActuelle, 6, fichier);

    // Libérez la mémoire et fermez le fichier
    free(combinaisonActuelle);
    fclose(fichier);

    return 0;
}
