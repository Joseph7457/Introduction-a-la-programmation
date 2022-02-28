/**
 * main.c
 * 
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <string.h>

#include "pnm.h"

char debug = 1;

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


int main(int argc, char *argv[]) {


// 1) Prise des valeurs en entrée du programme

   char *optstring = ":f:i:o:";
   char val;
   char entree[50] =  { 0 };
   char sortie[50] =  { 0 };
   char format[4]  =  { 0 };

   char e = 0, s = 0, f = 0;

   while( (val = getopt(argc, argv, optstring)) != EOF)
   {
      switch(val)
      {
         case 'f':
         strcpy(format, optarg); f = 1; break;
         case 'i':
         strcpy(entree, optarg); e = 1; break;
         case 'o':
         strcpy(sortie, optarg); s = 1; break;
         case ':':
         printf("Argument manquant: %c\n", optopt); break;
         case '?':
         printf("Option inconnue : %c\n", optopt); break;
      }
   }

   // 1.1) En cas de format non-fourni 

   if(!f)
   {  
      printf( "Vous n'avez pas rentré de format. Veuillez choisir un format:\n"); 
      printf( "1. PPM\n2. PBM\n3. PGM\n4. QUITTER\n");

      int reponse = 0;

      while(reponse <1 || reponse >4)
         {scanf("%d", &reponse);}
   
      switch (reponse)
      {
         case 1:
         strcpy(format, "PPM"); f = 1;
         break;

         case 2:
         strcpy(format, "PBM"); f = 1;
         break;

         case 3:
         strcpy(format, "PGM"); f = 1;
        break;

         case 4:
         exit(0);       
         break;

         default:
         break;
      }  
   }

   if (!e)
   {
      
   }
   
   if (!s)
   {
      
   }

   // 1.2) En cas d'input non-fourni 


   

if (debug)
   {
      printf("\nInitialisation du programme :\n ---------------------------- \n");
      printf("L'input   est : %s\n", entree);
      printf("La sortie est : %s\n", sortie);
      printf("Le format est : %s\n", format);
   }

   // CRÉER UNE FONCTION QUI LIBERE PNM
   PNM *test;
   load_pnm(&test, "washington.pbm");
   write_pnm(test, "washington.pbm");
   free(test);

   
   return 0;
}

