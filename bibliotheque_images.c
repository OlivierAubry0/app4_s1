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

void writeMeta(struct MetaData *metadonnees, FILE *fp1)
{
	fputs("#", fp1);
	fputs((*metadonnees).auteur, fp1);
	fputs(";", fp1);
	fputs((*metadonnees).dateCreation, fp1);
	fputs(";", fp1);
	fputs((*metadonnees).lieuCreation, fp1);
	fputs("\n", fp1);
}



/*void writeMeta(FILE *fp, char *c, struct MetaData *p_metadonnees)			//Reads MetaData of image file
{
	int loops=0 , index = 0;
		if(*c == '#'){
			*c=fgetc(fp);	
			(*p_metadonnees).lieuCreation[0] = '\0';
			(*p_metadonnees).dateCreation[0] ='\0'	;
			(*p_metadonnees).auteur[0] = '\0';					
			while(*c != '\n')
			{
				while(*c!='\n' && *c!= ';')
				{
					if(loops ==0)
					{
						(*p_metadonnees).auteur[index] = *c;
					}
					if(loops ==1)
					{

						(*p_metadonnees).dateCreation[index] = *c;
					}
					if(loops ==2)
					{
						(*p_metadonnees).lieuCreation[index] = *c;
					}
					
					*c = fgetc(fp);
					index++;
				}
				
				if(loops ==0)
				{
					(*p_metadonnees).auteur[index] = '\0';
				}
				if(loops ==1)
				{

					(*p_metadonnees).dateCreation[index] = '\0';
				}
				if(loops ==2)
				{
					(*p_metadonnees).lieuCreation[index] = '\0';
				}
				if(*c == ';')
				{
					*c = fgetc(fp);
				}
				index =0;
				loops++;
			}
			if((*p_metadonnees).lieuCreation[0] == '\0' || 
			   (*p_metadonnees).dateCreation[0] =='\0' || 
			   (*p_metadonnees).auteur[0] == '\0')
			{
				return -1;
			}
		}
	
	return 0;
}*/
void ReadMeta(FILE *fp3, char *c, struct MetaData *p_metadonnees)
{
	int compteur = 1;
	int valeur = 0;
	if (*c == '#')
	{
		*c =fgetc(fp3);
		(*p_metadonnees).lieuCreation[0] = '\0';
		(*p_metadonnees).dateCreation[0] ='\0';
		(*p_metadonnees).auteur[0] = '\0';
		while (*c != '\n')
		{
			while (*c!= ';'&& *c!='\n'  )
			{
				if (compteur == 1)
				{
					(*p_metadonnees).auteur[valeur] = *c;
				}
				if (compteur == 2)
				{
					(*p_metadonnees).dateCreation[valeur] = *c;
				}
				if (compteur == 3)
				{
					(*p_metadonnees).lieuCreation[valeur] = *c;
				}
				
				*c = fgetc(fp3);
					valeur++;
			}
			if(compteur ==0)
				{
					(*p_metadonnees).auteur[valeur] = '\0';
				}
				if(compteur ==1)
				{

					(*p_metadonnees).dateCreation[valeur] = '\0';
				}
				if(compteur ==2)
				{
					(*p_metadonnees).lieuCreation[valeur] = '\0';
				}
				if(*c == ';')
				{
					*c = fgetc(fp3);
				}
				valeur =0;
				compteur++;
			}
		}
	}
	


int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	FILE *fp2;
	
	
	fp2 = fopen(nom_fichier, "r");
	char c = 'a'; 
	while (1)
	{
			char fileType[100];
		if (fp2 != NULL){
		c=fgetc(fp2);
		ReadMeta(fp2,&c, p_metadonnees);
		
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
	}
		
			
		else
		{
			break;
			return ERREUR_FICHIER;
			
		}
		
	}
	
	
    return OK;
}

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees)
{
	FILE *fp2;
	
	
	fp2 = fopen(nom_fichier, "r");
	char c = 'a'; 
	while (1)
	{
			char fileType[100];
		if (fp2 != NULL){
		c=fgetc(fp2);
		ReadMeta(fp2,&c, p_metadonnees);
		
		{
			printf("success!\n");
			fscanf(fp2, "%s", fileType);
			printf("%s", fileType);
			if (strcmp(fileType, "P3") == 0)
			{
				printf("\nformat ppm\n");
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
					fscanf(fp2,"%d", &matrice[i][j].valeurR);
					fscanf(fp2,"%d", &matrice[i][j].valeurG);
					fscanf(fp2,"%d", &matrice[i][j].valeurB);
				}
			}
		
			
			fclose(fp2);
			break;
		}
	}
		
			
		else
		{
			break;
			return ERREUR_FICHIER;
			
		}
		
	}
	
	
    return OK;
}
	

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees)
            	{
				FILE* fp1;  
				fp1 =fopen(nom_fichier, "w+"); 
				if (fp1 == NULL) 
				{ 
				printf("erreur"); 
				} 
				else 
				{
				writeMeta(&metadonnees, fp1);
				
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
				
int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees)
	{
				FILE* fp1;  
				fp1 =fopen(nom_fichier, "w+"); 
				if (fp1 == NULL) 
				{ 
				printf("erreur"); 
				} 
				else 
				{
				writeMeta(&metadonnees, fp1);
				
				fprintf(fp1,"%s", "P3\n");
				fprintf(fp1, "%d %d\n",lignes,colonnes); 
				for(int i=0;i< lignes;i++)
				{
				for(int j=0;j< colonnes;j++)
				{
					fprintf(fp1,"%d", matrice[i][j].valeurR);
					fprintf(fp1,"%s", " ");
					fprintf(fp1,"%d", matrice[i][j].valeurG);
					fprintf(fp1,"%s", " ");
					fprintf(fp1,"%d", matrice[i][j].valeurB);
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
	
				
int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
	*p_lignes2 = lignes1;
	*p_colonnes2 = colonnes1;
	
	
	for(int i=0;i< lignes1;i++)
	{
		for(int j=0;j< colonnes1;j++)
		{
			 matrice2[i][j] = matrice1[i][j];
			
		}
		
	}
	return OK;
}

int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
	*p_lignes2 = lignes1;
	*p_colonnes2 = colonnes1;
	
	
	for(int i=0;i< lignes1;i++)
	{
		for(int j=0;j< colonnes1;j++)
		{
			 matrice2[i][j].valeurR = matrice1[i][j].valeurR;
			 matrice2[i][j].valeurG = matrice1[i][j].valeurG;
			 matrice2[i][j].valeurB = matrice1[i][j].valeurB;
			 
			
		}
		
	}
	return OK;
}
				
int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
{
	int couleur = 0;
	for (int k = 0; k <(MAX_VALEUR+1); k++)
	{
		histogramme[k] = 0;
	}
	for(int i=0;i< lignes;i++)
	{
		for(int j=0;j< colonnes;j++)
		{
			couleur = matrice[i][j];
			histogramme[couleur] +=1;
			
		}
	}
	return OK;
}

int pgm_couleur_preponderante(int matrice[MAX_LARGEUR][MAX_HAUTEUR], int lignes, int colonnes)
{
	int histogramme[MAX_VALEUR+1];
	pgm_creer_histogramme(matrice, lignes, colonnes, histogramme);
	int couleurMAX = histogramme[0];
	for (int i=0; i<(MAX_VALEUR+1); i++)
	{
		if (histogramme[i]>histogramme[couleurMAX])
		{
			couleurMAX = i;
		}
	}
	printf("\n\n\n%d\n\n\n",couleurMAX);
	return couleurMAX;
}
int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	if (lignes1!=lignes2 || colonnes1!=colonnes2)
	{
		return 0;
	}
	else
	{
		for(int i=0;i< lignes1;i++)
		{
			for(int j=0;j< colonnes1;j++)
			{
				if( matrice1[i][j] != matrice2[i][j])
				{
					return 0;
				}
			
			}
		}
	return 1;
	}
}
int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	if (lignes1!=lignes2 || colonnes1!=colonnes2)
	{
		return 0;
	}
	else
	{
		for(int i=0;i< lignes1;i++)
		{
			for(int j=0;j< colonnes1;j++)
			{
				if (matrice1[i][j].valeurR != matrice2[i][j].valeurR)
				{
					return 0;
				}
				if (matrice1[i][j].valeurG != matrice2[i][j].valeurG)
				{
					return 0;
				}
				if( matrice1[i][j].valeurB!= matrice2[i][j].valeurB)
				{
					return 0;
				}
			
			}
		}
	return 1;
	}
}
	


int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes)
{
	
	
	*p_lignes = (lignes2 - lignes1)+1;
	*p_colonnes = (colonnes2 - colonnes1)+1;
	
	
	
	for(int i=0;i< *p_lignes;i++)
		{
			for(int j=0;j< *p_colonnes;j++)
			{
				matrice[i][j] = matrice[lignes1+i][colonnes1+j];
			
			}
		}
	return OK;
}

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR],  

               int lignes, int colonnes,  

               int maxval, int valeur)  

  

{   

	 for(int i=0;i<lignes;i++)  

	{  

		for(int j=0;j<colonnes;j++)  

	    {  

			  matrice[i][j] = matrice[i][j]+ valeur; 

		 

				if(matrice[i][j]>maxval)  

				{  

				matrice[i][j] = maxval;  

				}  

				if (matrice[i][j] < 0)  

				{  

				matrice[i][j] = 0;  

				}  

		} 

	} 

	 

	 return 0 ;   

}  

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)  


{  

	int lignes = *p_lignes; 

	int colonnes = *p_colonnes; 

	int matricetourner[MAX_HAUTEUR][MAX_LARGEUR]; 

	if(sens==1)// anti  

	{  

		for (int i=0; i<*p_lignes; i++)  

		{  

			for(int j=i; j<*p_colonnes; j++)  

			{	  

				matricetourner[j][*p_lignes -1 -i] = matrice[i][j]; 

			}  

		}  

	} 

	if(sens==0) 

	{  

		for (int i=0; i<*p_lignes; i++)  

		{  

			for(int j=i; j<*p_colonnes; j++)  

			{	  

				matricetourner[i][*p_colonnes -1 -j] = matrice[i][j]; 

			}  

		}  

	} 

	else 

	{ 

		return -1; 

	} 

	 

	*p_lignes = colonnes;  

	*p_colonnes = lignes; 

	

	for (int i=0; i<*p_lignes; i++)  

	{  

		for(int j=i; j<*p_colonnes; j++)  

		{	  

				matrice[i][j]= matricetourner[i][j]; 

		} 

	} 

	return 0; 

}		  

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR],int lignes, int colonnes, int maxval) 

{ 

if( lignes>MAX_HAUTEUR || colonnes>MAX_LARGEUR || matrice[MAX_HAUTEUR][MAX_LARGEUR]> maxval) 

	{ 

		return -1; 

	} 

			for (int i=0; i< MAX_HAUTEUR; i++) 

			{ 

				for(int j=i; j<MAX_LARGEUR; j++)  

				{ 

					matrice[i][j] = maxval - matrice[i][j]; 

				} 

			} 

		return 0;  

} 


int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)  

{  
	int lignes = *p_lignes; 

	int colonnes = *p_colonnes; 

	struct RGB matricetourner[MAX_HAUTEUR][MAX_LARGEUR]; 

	if(sens==1)// anti  

	{  

		for (int i=0; i<*p_lignes; i++)  

		{  

			for(int j=0; j<*p_colonnes; j++)  

			{	  

				matricetourner[j][*p_lignes -1 -i].valeurR = matrice[i][j].valeurR; 

				matricetourner[j][*p_lignes -1 -i].valeurG = matrice[i][j].valeurG; 

				matricetourner[j][*p_lignes -1 -i].valeurB = matrice[i][j].valeurB; 

			}  

		}  

	} 

	if(sens==0) 

	{  

		for (int i=0; i<*p_lignes; i++)  

		{  

			for(int j=0; j<*p_colonnes; j++)  

			{	  

				matricetourner[i][*p_colonnes -1 -j].valeurR = matrice[i][j].valeurR; 

				matricetourner[i][*p_colonnes -1 -j].valeurG = matrice[i][j].valeurG; 

				matricetourner[i][*p_colonnes -1 -j].valeurB = matrice[i][j].valeurB; 

			}  

		}  

	} 

	else 

	{ 

		return -1; 

	} 

	*p_lignes = colonnes;  

	*p_colonnes = lignes; 

	 
	for (int i=0; i<*p_lignes; i++)  

	{  

		for(int j=0; j<*p_colonnes; j++)  

		{	  

				matrice[i][j].valeurR= matricetourner[i][j].valeurR; 

				matrice[i][j].valeurR= matricetourner[i][j].valeurG; 

				matrice[i][j].valeurR= matricetourner[i][j].valeurB; 

		} 

	} 

	return 0; 

}


			
		
	
	










//int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
	
	
	
	

