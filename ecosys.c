#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"

/* PARTIE 1*/
/* Fourni: Part 1, exercice 4, question 2 */
Animal *creer_animal(int x, int y, float energie) {
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni: Part 1, exercice 4, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire. Part 1, exercice 6, question 2 */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
  assert(x >= 0 && x < SIZE_X);
  assert(y >= 0 && y < SIZE_Y);
  Animal *animal = (Animal *)malloc(sizeof(Animal));
  		animal->x=x;
  		animal->y=y;
  		animal->suivant=(*liste_animal);
  		*liste_animal=animal;
  }

/* A Faire. Part 1, exercice 5, question 5 */
void enlever_animal(Animal **liste, Animal *animal) {
    if (liste == NULL || *liste == NULL || animal == NULL) {
        return;
    }

    if (*liste == animal) {
        Animal *tmp = *liste;           
        *liste = (*liste)->suivant;    
        free(tmp);                     
        return;
    }

    Animal *current = (*liste)->suivant;
    Animal *previous = *liste;

    while (current != NULL) {
        if (current == animal) {
            previous->suivant = current->suivant;  
            free(current);  
            return;
        }
        previous = current;
        current = current->suivant;
    }
}


/* A Faire. Part 1, exercice 6, question 7 */
Animal* liberer_liste_animaux(Animal *liste) {
   while (liste){
   	Animal *tmp=liste;
   	liste=liste->suivant;
   	free(tmp);
   }
   	
   return NULL;
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la=la->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 5, question 1, ATTENTION, ce code est susceptible de contenir des erreurs... */

void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
    unsigned int i, j;
    char ecosys[SIZE_X][SIZE_Y];
    Animal *pa = NULL;

    /* Initialisation du tableau */
    for (i = 0; i < SIZE_X; ++i) {
        for (j = 0; j < SIZE_Y; ++j) {
            ecosys[i][j] = ' '; // Vide initialement
        }
    }

    /* Ajouter les proies */
    pa = liste_proie;
    while (pa) {
        if (pa->x < SIZE_X && pa->y < SIZE_Y) {  // Vérification des limites
            ecosys[pa->x][pa->y] = '*';  // '*' pour les proies
        }
        pa = pa->suivant;
    }

    /* Ajouter les prédateurs */
    pa = liste_predateur;
    while (pa) {
        if (pa->x < SIZE_X && pa->y < SIZE_Y) {  // Vérification des limites
            if (ecosys[pa->x][pa->y] == '*') {
                ecosys[pa->x][pa->y] = '@';  // '@' pour proies et prédateurs au même endroit
            } else {
                ecosys[pa->x][pa->y] = 'O';  // 'O' pour les prédateurs seuls
            }
        }
        pa = pa->suivant;
    }

    /* Affichage du tableau */
    printf("+");
    for (j = 0; j < SIZE_X; ++j) {
        printf("-");
    }
    printf("+\n");

    for (i = 0; i < SIZE_Y; ++i) {  // Les lignes correspondent à Y
        printf("|");
        for (j = 0; j < SIZE_X; ++j) {  // Les colonnes correspondent à X
            putchar(ecosys[j][i]);  // Affichage dans le bon ordre
        }
        printf("|\n");
    }

    printf("+");
    for (j = 0; j < SIZE_X; ++j) {
        printf("-");
    }
    printf("+\n");

    /* Compte et affichage des proies et prédateurs */
    int nbproie = compte_animal_it(liste_proie);
    int nbpred = compte_animal_it(liste_predateur);

    printf("Nb proies : %5d\tNb predateurs : %5d\n", nbproie, nbpred);
}





void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* Part 2. Exercice 4, question 1 */
void bouger_animaux(Animal *la) {
    /*A Completer*/

}

/* Part 2. Exercice 4, question 3 */
void reproduce(Animal **liste_animal, float p_reproduce) {
   /*A Completer*/

}


/* Part 2. Exercice 6, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
    /*A Completer*/

}

/* Part 2. Exercice 7, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
    /*A Completer*/

  return NULL;
} 

/* Part 2. Exercice 7, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
   /*A Completer*/

}

/* Part 2. Exercice 5, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){

   /*A Completer*/


}

