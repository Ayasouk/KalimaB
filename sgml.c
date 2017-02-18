#include <stdio.h>
#include <stdlib.h>
//#include "sgml.h"


typedef enum Etats{
    E0_debut,
    E1_Baliseo,
    E2_Fermeture,
    E3_Lectbalise,
    E4_Balisef
} E_Etats;

char * etat_str(E_Etats et){
	switch(et){
		case E0_debut: return "E0_debut";
		case E1_Baliseo : return "E1_Baliseo";
		case E2_Fermeture: return "E2_Fermeture";
		case E3_Lectbalise: return "E3_Lectbalise";
		case E4_Balisef: return "E4_Balisef";
	}
}

int main(){
    FILE *fd;
    char c;
    char nom_balise[32]="";
    char chaine_dbt[64]="";
    char contenuBalise[256]="";
    E_Etats etat_cur = E0_debut;
    if((fd=fopen("/home/oukache/Bureau/parseur/data.txt","r")))
    {
		printf("\nOuverture du fichier ... Done\n");
        for(c=fgetc(fd);feof(fd);c=fgetc(fd)){
            printf("caractere : %c  %d  --  ")
            switch(etat_cur){
             //si l'automate est a l'etat 0(debut)
             case E0_debut:
                 if(c=='<')
                    printf("chaine_dbt : %s   changement d'etat E0 a E1",chaine_dbt);
                    etat_cur=E1_Baliseo;
                 if(c!='<'){
                    sprintf(chaine_dbt,"%s%c",chaine_dbt,c);
                 }
                break;
            //si l'automate est a l'etat 1(balise ouvrante)
             case E1_Baliseo:
                 if(c=='\\'){
                    etat_cur=E2_Fermeture;
                 }
                 if(c=='>'){
                    printf("entrer dans la balise : %s\n",nom_balise);
                    etat_cur=E3_Lectbalise;
                 }
                 if(c!='\\'&&c!='>'){
                    sprintf(nom_balise,"%s%c",nom_balise,c);
                 }
                break;
            //si l'automate est a l'etat 2(lecture d'une balise fermante)
             case E2_Fermeture:
                 if(c!='>'){
                    sprintf(nom_balise,"%s%c",nom_balise,c);
                 }
                 if(c=='>'){
                    printf("nom de la balise : %s",nom_balise);
                    // empiler le nom de la balise ouvrante
                 }
                break;
            //si l'automate est a l'etat 3(lecture du contenu de balise)
             case E3_Lectbalise:
                 if(c!='<'){
                    sprintf(contenuBalise,"%s%c",contenuBalise,c);
                 }
                 if(c=='<'){
                    etat_cur=E1_Baliseo;
                 }
                break;
            //si l'automate est a l'etat 4(balise fermante)
             case E4_Balisef:
                 if(c=='>'){
                    printf("nom de la balise : %s\n",nom_balise);
                    //verifier que le nom de la balise correspond a celuio en tete de la pile
                    //sinon il y a une erreur
                    break;
                 }
                 if(c!='>'){
                    sprintf(nom_balise,"%s%c",nom_balise,c);
                 }
                break;
            }
        }
    }
    fclose(fd);
    printf("Fermeture de fichier ... Done");
}
