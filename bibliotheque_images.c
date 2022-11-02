/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"
#include <string.h>
#include <stdlib.h> 


int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	FILE *fp2;
	
	fp2 = fopen("Sherbrooke_Frontenac_nuit.pgm", "r");
	while (1)
	{
			char fileType[100];
		if (fp2 != NULL)
		{
			printf("success!\n");
			fscanf(fp2, "%s", fileType);
			printf("%s", fileType);
			if (strcmp(fileType, "P2") == 0)
			{
				printf("\nformat pgm\n");
			}
			else 
			{
				printf("\nerreur format");
				break;
				return ERREUR_FORMAT;
			}

			fscanf(fp2, "%d", &*p_lignes);
			if (*p_lignes>256)
			{
				printf("image trop grande");
				break;
				return ERREUR_TAILLE;
			}
				
			printf("\n\nNOMBREDELIGNES %d\n\n", *p_lignes);
			fscanf(fp2, "%d", &*p_colonnes);
			
			
			if (*p_colonnes>256)
			{
				printf("image trop grande");
				break;
				return ERREUR_TAILLE;
			}
			
			printf("\n\nNOMBREDECOLONNES %d\n\n", *p_colonnes);
			fscanf(fp2, "%d", p_maxval);
			printf("\n\nVALEUR MAX %d\n\n", *p_maxval);

			printf("image en format pgm:\n\n");	


			 


			for(int i=0;i< *p_lignes;i++)
			{
				for(int j=0;j< *p_colonnes;j++)
				{
					fscanf(fp2,"%d", &matrice[i][j]);
					printf("%d ",matrice[i][j]);
				}
				
				printf("\n");
			}
		
			
			fclose(fp2);
			break;
		}
		
			
		else
		{
			break;
			return ERREUR_FICHIER;
			
		}
		
	}
	
	
    return 0;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
            	{
				FILE* fp1;  
				fp1 =fopen("resultat.pgm", "w+"); 
				if (fp1 == NULL) 
				{ 
				printf("erreur"); 
				} 
				else 
				{
				
				fprintf(fp1,"%s", "P2\n");
				fprintf(fp1, "%d %d\n",lignes,colonnes); 
				for(int i=0;i< lignes;i++)
				{
				for(int j=0;j< colonnes;j++)
				{
					fprintf(fp1,"%d", matrice[i][j]);
					fprintf(fp1,"%s", " ");
				}
				
				fprintf(fp1, "%s", "\n");
				} 
				} 
				if (fp1!=NULL) 
				{ 
				fclose(fp1); 
				} 
					return OK; 
				}
