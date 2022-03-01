/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pnm.h"


struct PNM_t {
char* format;
int   dimension[2];
int** donnees;
};


int comparer_phrase(char *phrase_1, char *phrase_2)
{
if (phrase_1 == NULL || phrase_2 == NULL)
    {  
        return 0;
    }

    int i = 0;
    while(phrase_1[i++] != EOF || phrase_2[i] != EOF)
    {
        if (phrase_1[i] != phrase_2[i])
        return -1;
    }

    if (phrase_1[i] != phrase_2[i])
    return -1;

return 1;
}

int lire_mot_par_mot(char* mot, char* phrase)
{ static int index   =  0 ;
  static int adresse =  0 ;

  if(adresse != (int) &phrase )                            // Si la phrase est différente, on remet l'index à zéro et on change l'adresse de référence;
    {adresse  = (int) &phrase; index = 0;}

   while(phrase[index++] == " " && phrase[index] != "/0"); // Sauter les espaces indésirables;

   int index_mot = 0;
   while(phrase[index] != " " || phrase[index] != "/0")
   {
      mot[index_mot++] = phrase[index++];
   }
   mot[index_mot]    = "/0"; 
   if(phrase[index] != "/0")
   {
      index = 0;
      return 0;
   }
   else{index++;}
   return 1;                        // Sortie: 1 si la fin du fichier n'eest pas atteinte. 0 si fin de de lecture.
}

char* lire_le_format(char *phrase, char *mot)
{
lire_mot_par_mot(mot, phrase);

}

int load_pnm(PNM **image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

