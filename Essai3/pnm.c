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
#include <string.h>

#include "pnm.h"


struct PNM_t{     char*           format;
                  int             dimension[2];
                  char**          donnees;               };



int load_pnm(PNM **image, char* filename) {

   FILE * fp;
   short int TAMPON = 1000;
   char phrase[TAMPON];
   *image = malloc(sizeof(PNM));

   if(    (fp = fopen(filename , "r") ) )
   {
   
      char booleen_format_fait      = 0;
      char booleen_dimension_faite  = 0;
      int compteur[]            = {0,0};
      char* mot;

         while( (fgets (phrase, 60, fp) != NULL) ) {

            mot = strtok(phrase, " ");
            compteur[0]+=1;
            printf("\n\nboucle : %d\n\n", compteur[0]);
            //if (compteur[0]>3) return 0;

            if(phrase[0] != '#'){

                  
                  
                  while(mot)
                  {    
                        printf( "%s ", mot);
                        if(!booleen_format_fait)
                        {

                           if(comparer_phrase(mot, "P1"))
                           {
                              (*image)->format = "PBM";
                           }

                           else if (comparer_phrase(mot, "P2"))
                           {
                              (*image)->format = "PGM";
                           }

                           else if (comparer_phrase(mot, "P3"))
                           {
                              (*image)->format = "PPM";
                           }

                           else
                           {
                              return -99;
                           }
                           booleen_format_fait = 1;
                           
                        }

                     else if(!booleen_dimension_faite)
                        {  
                           
                           if((*image)->dimension[0] <= 0) 
                           {(*image)->dimension[0] =  mot;}

                           else if ((*image)->dimension[1] <= 0)
                           {(*image)->dimension[1] =  mot;}

                           else
                           {booleen_dimension_faite = (char) 1; 

                           printf("dimension = [%d, %d]", (*image)->dimension[0], (*image)->dimension[1]);}
                           
                        } 

                        else
                           {

                              (*image)->donnees[compteur[0]][compteur[1]] =  mot;

                              compteur[0]++;
                              if (compteur[0]>= (*image)->dimension[0])
                              {
                                 compteur[0] = 0;
                                 compteur[1]++;
                              }
                     
                           }
                        mot = strtok(NULL, " ");
                  }
                  
         }
         
       }

   }

   





   fclose(fp);
   return 0;
}

int write_pnm(PNM *image, char* filename) {

   return 0;
}

