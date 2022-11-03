/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int main()
{
    int lignes1, colonnes1;
    int lignes2, colonnes2;
    int extX1=50;
    int extY1=50;
    int extX2=100;
    int extY2=100;
    int *p_lignes = 0, *p_colonnes = 0;
    int maxval;
    int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
    char nom2[MAX_CHAINE] = "resultats.pgm";
    char nom3[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.ppm";
    char nom4[MAX_CHAINE] = "resultats.ppm";
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

	// exemple d'appel de fonction
    ppm_lire(nom3, imageRGB1, &lignes1, &colonnes1, &maxval, &metadonnees);
    ppm_lire(nom3, imageRGB2, &lignes2, &colonnes2, &maxval, &metadonnees);
    retour = ppm_sont_identiques(imageRGB1, lignes1, colonnes1, imageRGB2, lignes2, colonnes2);
	
                      
     /*retour = pgm_ecrire(nom2, image1, lignes1, colonnes1, maxval, metadonnees);*/
     
     //test de la fonction histogramme
	   /*pgm_lire(nom, image1, &lignes1, &colonnes1, &maxval, &metadonnees);
	   retour = pgm_couleur_preponderante(image1, lignes1, colonnes1);*/
	   //test de fontion identique
	   /*pgm_lire(nom, image1, &lignes1, &colonnes1, &maxval, &metadonnees);
	   
	  
	   retour =  pgm_extraire(image1, extX1, extY1, extX2, extY2, &p_lignes, &p_colonnes);
		pgm_ecrire(nom2, image1, lignes1, colonnes1, maxval, metadonnees);*/
	   

	//test de la fonction copier
   /* retour = pgm_lire(nom, image1, &lignes1, &colonnes1, &maxval, &metadonnees);
				pgm_copier(image1, lignes1, colonnes1, image2, &lignes2, &colonnes2);
				pgm_ecrire(nom2, image2, lignes2, colonnes2, maxval, metadonnees);*/
	

	// exemple detraitement d'un code de retour (erreur ou reussite)
	printf("-> Retour: ");
	if (retour == 1)
		printf("-> diff");
	else
		printf("-> ERREUR");
	printf("\n");

	/*// autre exemple d'appel de fonction
    //pgm_ecrire(nom2, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees);*/
               
    
	

    printf("-> Fin!\n");

    return 0;
}
