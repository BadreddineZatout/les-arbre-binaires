  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <time.h>
  #include "fonction.h"
    int main()
    {
        srand(time(0));

        /***************************************************** initilaisation ********************************************************************/

     text=fopen("texte.txt","r");
     print=fopen("result.txt","w");
     Ch = malloc(255 * sizeof(string255));
     mot = malloc(255 * sizeof(string255));
     Allouer_RAs(&L ) ;
     Aff_adrd_RAs(L , L ) ;
     Aff_adrg_RAs(L , L ) ;
     Aff_val_RAs(L,0);

        /******************************************************** le programme principale ********************************************************/

   welcome();
   system("pause");
   system("cls");
   system("color C");
   while (!feof(text))
     {
         fscanf(text,"%s",Ch);
         regle_ch(Ch,mot);             /*Eliminer les caractere speciaux si ils existent*/
         Ch=mot;
         fprintf(print,"%s ",Ch);

        /******************************************************** creation de la structure ********************************************************/

         Rech_bi ( & Ch , & L , & B , & Trouve ) ;
         if( Trouve )
            {
               if( ( Valeur_RAs(L ) == NULL ))
                 {
                    Creernoeud_As(&R ) ;
                    Aff_info_As(R , Ch ) ;
                    Aff_val_RAs(L , R ) ;
                 }
               else
                 {
                    R  =  Valeur_RAs(B ) ;
                    Ins ( & Ch , & R ) ;
                 }
            }
       else
         {
            Creernoeud_As(&R ) ;
            Allouer_RAs(&Lb ) ;
            Aff_val_RAs(Lb , R ) ;
            Aff_info_As(R , Ch ) ;
            if( Longchaine(Ch ) > Longchaine(Info_As(Valeur_RAs(B ) ) ))
                {
                   Aff_adrg_RAs(Suivant_RAs(B ) , Lb ) ;
                   Aff_adrd_RAs(Lb , Suivant_RAs(B ) ) ;
                   Aff_adrd_RAs(B , Lb ) ;
                   Aff_adrg_RAs(Lb , B ) ;
                }
            else
                {
                   Aff_adrd_RAs(Precedent_RAs(B ) , Lb ) ;
                   Aff_adrg_RAs(Lb , Precedent_RAs(B ) ) ;
                   Aff_adrg_RAs(B , Lb ) ;
                   Aff_adrd_RAs(Lb , B ) ;
                }
       }
       if( ( Longchaine(Ch) < Longchaine(Info_As(Valeur_RAs(L ) ) ) ))
            {
               L  =  Lb ;
            }
     }
     fclose(print);
     fclose(text);

    /*************************************** verification que le structure est bien construite ************************************************/

    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\tLa structure est construite\n\n\n");
    printf("\t\t\tAppuyez sur ENTREE pour afficher le contenu de chaque arbre\n\n\n\n\t\t\t");
    system("pause");
    system("cls");
    system("color C");


     printf("\n\t\t\t\t********** affichege de l'arbre en preordre **********\n\n");
     B=L;
     I=1;
     while (Suivant_RAs(B)!=L)
     {
         printf("\n\t*******************************************************************************************************\n");
         printf("l''arbre des chaine avec une longueur : %d\n\n",Longchaine(Info_As(Valeur_RAs(B))));
         inordre(Valeur_RAs(B));
         B=Suivant_RAs(B);
         I++;
         system("pause");
     }
     printf("\n\t*******************************************************************************************************\n");
     printf("l''arbre des chaine avec une longueur : %d\n\n",Longchaine(Info_As(Valeur_RAs(B))));
     inordre(Valeur_RAs(B));
     printf("\n\t*******************************************************************************************************\n");

        /*************************************** la partie du suppression ************************************************/

    /* B=L;
     print=fopen("result.txt","r");
     while (!feof(print))
      {
        fscanf(print,"%s ",Ch);
        Supp ( & Ch , & L ) ;
      }
     if( L == NULL)   {
       system("cls");
       printf ( "\n\n\n\n\t\t\t\t\t\tla liste est vide\n\n\n" ) ;
     }*/
    }
