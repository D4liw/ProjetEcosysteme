#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"
#include <time.h>

int main(void) {
    Animal *liste_proie = NULL;
    Animal *liste_predateur = NULL;
    float energie = 10.0;

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        int x = rand() % SIZE_X;
        int y = rand() % SIZE_Y;
        ajouter_animal(x, y, energie, &liste_proie);
    }

    for (int i = 0; i < 20; i++) {
        int x = rand() % SIZE_X;
        int y = rand() % SIZE_Y;
        ajouter_animal(x, y, energie, &liste_predateur);
    }

    afficher_ecosys(liste_proie, liste_predateur);

    enlever_animal(&liste_proie, liste_proie); 
    enlever_animal(&liste_predateur, liste_predateur); 

    afficher_ecosys(liste_proie, liste_predateur);

    liberer_liste_animaux(liste_proie);
    liberer_liste_animaux(liste_predateur);

    return 0;
}

