#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
typedef int bool ;
  typedef char * string255 ;

  #define True 1
  #define False 0

  /** Implémentation **: LISTE BIDIRECTIONNELLE DE ARBRES BINAIRES DE CHAINES DE CARACTERES**/

                             /**************************** Arbres de recherche binaire ****************************/

  typedef string255 Typeelem_As   ;
  typedef struct Noeud_As * Pointeur_As ;

  struct Noeud_As

    {
      Typeelem_As  Val ;
      Pointeur_As Fg ;
      Pointeur_As Fd ;
      Pointeur_As Pere ;
     } ;

  Typeelem_As Info_As( Pointeur_As P )
    { return P->Val;   }

  Pointeur_As Fg_As( Pointeur_As P)
    { return P->Fg ; }

  Pointeur_As Fd_As( Pointeur_As P)
    { return P->Fd ; }

  Pointeur_As Pere_As( Pointeur_As P)
    { return P->Pere ; }

  void Aff_info_As ( Pointeur_As P, Typeelem_As Val)
    {
       strcpy( P->Val , Val );
    }

  void Aff_fg_As( Pointeur_As P, Pointeur_As Q)
    { P->Fg =  Q;  }

  void Aff_fd_As( Pointeur_As P, Pointeur_As Q)
    { P->Fd =  Q ; }

  void Aff_pere_As( Pointeur_As P, Pointeur_As Q)
    { P->Pere =  Q ; }

  void Creernoeud_As( Pointeur_As *P)
    {
      *P = (struct Noeud_As *) malloc( sizeof( struct Noeud_As))   ;
      (*P)->Val = malloc(31 * sizeof(string255));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_As( Pointeur_As P)
    { free( P ) ; }


                               /************************** Listes bidirectionnelles **************************/

  typedef Pointeur_As Typeelem_RAs   ;
  typedef struct Maillon_RAs * Pointeur_RAs ;

  struct Maillon_RAs
    {
      Typeelem_RAs  Val ;
      Pointeur_RAs Suiv ;
      Pointeur_RAs Prec ;
    };


  void Allouer_RAs (Pointeur_RAs *P)
    {
    *P = (struct Maillon_RAs *) malloc( sizeof( struct Maillon_RAs))   ;
    (*P)->Suiv = NULL;
    (*P)->Prec = NULL;
    }

  void Aff_val_RAs(Pointeur_RAs P, Typeelem_RAs Val)
    {
     P->Val = Val ;
    }

  void Aff_adrd_RAs( Pointeur_RAs P,  Pointeur_RAs Q)
    { P->Suiv = Q; }

  void Aff_adrg_RAs( Pointeur_RAs P,  Pointeur_RAs Q)
    { P->Prec = Q; }

  Pointeur_RAs Suivant_RAs(  Pointeur_RAs P)
    { return( P->Suiv );  }

  Pointeur_RAs Precedent_RAs(  Pointeur_RAs P)
    { return( P->Prec );  }

  Typeelem_RAs Valeur_RAs( Pointeur_RAs P)
    { return( P->Val) ; }

  void Liberer_RAs ( Pointeur_RAs P)
   { free (P) ; }

  /** Variables du programme principal **/
  Pointeur_RAs L;
  Pointeur_RAs B;
  Pointeur_RAs Lb;
  Pointeur_As R;
  Pointeur_As P;
  Pointeur_As Q;
  int N;
  int I,J;
  string255 Ch;
  string255 mot;
  bool Existe;
  bool Trouve;
  Pointeur_As A;
  Pointeur_As M;
  FILE *text,*print;



  /** Fonctions standards **/

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }


  /** Prototypes des fonctions **/

  void Rech_bi (string255 *Val , Pointeur_RAs *Li , Pointeur_RAs *Bi , bool *Tr);
  void Ins (string255 *V , Pointeur_As *Racine);
  void Rech_abr (string255 *V , Pointeur_As *A , Pointeur_As *P , bool *Bool);
  void regle_ch(string255 Ch,string255 mot);
  void preordre( Pointeur_As A );
  void welcome();
  void Supp (string255 *V , Pointeur_RAs *L);

  /*******************************************************/
  void Rech_bi (string255 *Val , Pointeur_RAs *Li , Pointeur_RAs *Bi , bool *Tr)
    {
      /** Variables locales **/
      bool Existe;
      Pointeur_As R;

      /** Corps du module **/
     *Bi  =  *Li ;
     R  =  Valeur_RAs(*Bi ) ;
     *Tr  =  False ;
     Existe  =  True ;
     if( R == NULL)   {
       *Tr  =  True ;
       }
     else
       {
       if( Longchaine(*Val ) <= 15)   {
         while( ( ! *Tr ) && ( Longchaine(Info_As(R ) ) <= 15 ) && ( Suivant_RAs(*Bi ) != *Li ) && ( Existe ))  {
           if( ( Longchaine(Info_As(R ) ) <= Longchaine(*Val ) ))   {
             if( Longchaine(*Val ) == Longchaine(Info_As(R ) ))   {
               *Tr  =  True ;
               }
             else
               {
               *Bi  =  Suivant_RAs(*Bi ) ;
               R  =  Valeur_RAs(*Bi ) ;

             } }
           else
             {
             Existe  =  False ;

           }
         } ;
         if( ( Suivant_RAs(*Bi ) == *Li ) && ( Longchaine(Info_As(R ) ) == Longchaine(*Val ) ))   {
           *Tr  =  True ;

         } }
       else
         {
            if( Longchaine(*Val ) == Longchaine(Info_As(R ) ))   {*Tr  =  True ;}
            else
             {
              *Bi  =  Precedent_RAs(*Bi ) ;
               R  =  Valeur_RAs(*Bi ) ;
             }
         while( ( ! *Tr ) && ( Longchaine(Info_As(R ) ) > 15 ) && ( Precedent_RAs(*Bi ) != *Li ) && ( Existe ))  {
           if( ( Longchaine(Info_As(R ) ) >= Longchaine(*Val ) ))   {
             if( Longchaine(*Val ) == Longchaine(Info_As(R ) ))   {
               *Tr  =  True ;
               }
             else
               {
               *Bi  =  Precedent_RAs(*Bi ) ;
               R  =  Valeur_RAs(*Bi ) ;

             } }
           else
             {
             Existe  =  False ;

           }
         } ;
         if( ( Precedent_RAs(*Bi ) == *Li ) && ( Longchaine(Info_As(Valeur_RAs(*Li ) ) ) == Longchaine(*Val ) ))   {
           *Tr  =  True ;

         }
       }
     }
    }
  /*******************************************************/
  void Ins (string255 *V , Pointeur_As *Racine)
    {
      /** Variables locales **/
      Pointeur_As P;
      Pointeur_As A;
      Pointeur_As Q;
      bool Trouv;

      /** Corps du module **/
     P  =  NULL ;
     A  =  *Racine ;
     Rech_abr ( & *V , & A , & P , & Trouv ) ;
     if( ( ! Trouv ))   {
       Creernoeud_As(&Q ) ;
       Aff_info_As(Q , *V ) ;
       if(strcmp( *V, Info_As(P )) > 0 )   {
         Aff_fd_As(P , Q ) ;
         }
       else
         {
         Aff_fg_As(P , Q ) ;

       }
     }
    }

  /***************************************************************************************************************************************/

  void Rech_abr (string255 *V , Pointeur_As *A , Pointeur_As *P , bool *Bool)
    {

      /** Corps du module **/
     *Bool  =  False ;
     *P  =  NULL ;
     while( ( ! *Bool ) && ( *A != NULL ))  {
       if(strcmp( Info_As(*A ), *V) == 0 )   {
         *Bool  =  True ;
         }
       else
         {
         *P  =  *A ;
         if(strcmp( *V, Info_As(*A )) < 0 )   {
           *A  =  Fg_As(*A ) ;
           }
         else
           {
           *A  =  Fd_As(*A ) ;

         }
       }
     }
    }

    /***************************************************************************************************************************************/

    void regle_ch(string255 Ch,string255 mot)
    {

        /** Corps du module **/
        int K=0;
        J=0;
      for (J=0;J<=strlen(Ch);J++)
      {

        if (Ch[J]=='é' || Ch[J]=='è' || Ch[J]=='ê') Ch[J]='e';
        if (Ch[J]=='à') Ch[J]='a';
        if (Ch[J]=='ç') Ch[J]='c';
        if (Ch[J]=='î' || Ch[J]=='ï') Ch[J]='i';
        if (Ch[J]=='ô') Ch[J]='o';
        if (Ch[J]=='ù') Ch[J]='u';

        if ((Ch[J]>=65 && Ch[J]<=90) || (Ch[J]>=97 && Ch[J]<=122))
        {
            mot[K]=Ch[J];
            K++;
        }
            if (K==0)
            {
                fscanf(text,"%s",Ch);
                J=0;
            }
      }
      mot[K]='\0';
     }

    /***************************************************************************************************************************************/

void inordre( Pointeur_As A )
{
    /** Corps du module **/

    if (A != NULL)
    {
        inordre( Fg_As(A) );
        printf("\t\t\t\t\t->|%s|<-\n", Info_As(A) );
        inordre( Fd_As(A) );
    }

}

   /***************************************************************************************************************************************/

void welcome()
{
    system("color B");
    printf("\n\n\n\n\t\t\t\t    _______________________________________________________ \n");
    printf("\t\t\t\t   |        _______     _______     _                      |\n");
    printf("\t\t\t\t   |       |  _____|   |  _____|   | |  ecole nationale    |\n");
    printf("\t\t\t\t   |       | |_____    | |_____    | |                     |\n");
    printf("\t\t\t\t   |       |  _____|   |_____  |   | |  superieure         |\n");
    printf("\t\t\t\t   |       | |_____     _____| |   | |                     |\n");
    printf("\t\t\t\t   |       |_______|   |_______|   |_|  d'informatique     |\n");
    printf("\t\t\t\t   |_______________________________________________________|\n\n");
    printf("\t\t\t\t\tCPI - 1ere Annee - Annee Universitaire 2017/2018 \n\n\n");
    printf("\t\t\t\t ___________________________________________________________________\n");
    printf("\t\t\t\t|                                                            \t\t|\n");
    printf("\t\t\t\t| REALISE PAR : ZATOUT BADREDDINE et AITSAADI ABDELMADJID     \t\t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|        \t ANNEE SCOLAIRE : 2017/2018                        \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|         \tSECTION : B           GROUPE: 06                  \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|         \tTP2 :   Exploration de textes                  \t\t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t|         <liste lineaire chainee bidirectionnelle circulaire \t\t|\n");
    printf("\t\t\t\t|         d arbres de recherche binaire de chaines de caracteres> \t|\n");
    printf("\t\t\t\t|                                                             \t\t|\n");
    printf("\t\t\t\t| ENCADRE PAR :Dr M BOULAKRADECHE                            \t\t|\n ");
    printf("\t\t\t\t|___________________________________________________________________|\n\n\n");

}

    /***************************************************************************************************************************************/

  void Supp (string255 *V , Pointeur_RAs *L)
    {
      /** Variables locales **/
      Pointeur_As Racine;
      Pointeur_As P;
      Pointeur_As R;
      Pointeur_As Q;
      Pointeur_As T;
      bool Trouv1;
      bool Trouv2;
      Pointeur_RAs B;

      /** Corps du module **/
     Rech_bi ( & *V , & *L , & B , & Trouv1 ) ;
     if( Trouv1)   {
       P  =  NULL ;
       R  =  Valeur_RAs(B ) ;
       Racine  =  Valeur_RAs(B ) ;
       Rech_abr ( & *V , & R , & P , & Trouv2 ) ;
       if( Trouv2)   {
         if( Fd_As(R ) == NULL)   {
           if( Fg_As(R ) == NULL)   {
             if( R == Racine)   {
               if( B == *L)   {
                 *L  =  Suivant_RAs(*L ) ;

               } ;
               if( *L == Suivant_RAs(*L ))   {
                 *L  =  NULL; }
               else
                 {
                 Aff_adrd_RAs(Precedent_RAs(B ) , Suivant_RAs(B ) ) ;
                 Aff_adrg_RAs(Suivant_RAs(B ) , Precedent_RAs(B ) ) ;
                 Liberernoeud_As(R ) ;
                 Liberer_RAs(B ) ;

               } }
             else
               {
               if( R == Fd_As(P ))   {
                 Aff_fd_As(P , NULL ) ;
                 }
               else
                 {
                 Aff_fg_As(P , NULL ) ;

               } ;
               Liberernoeud_As(R ) ;

             } }
           else
             {
             if( R == Racine)   {
               Aff_val_RAs(B , Fg_As(R ) ) ;
               Liberernoeud_As(R ) ;
               }
             else
               {
               if( R == Fg_As(P ))   {
                 Aff_fg_As(P , Fg_As(R ) ) ;
                 Liberernoeud_As(R ) ;
                 }
               else
                 {
                 Aff_fd_As(P , Fg_As(R ) ) ;
                 Liberernoeud_As(R ) ;

               }
             }
           } }
         else
           {
           if( Fg_As(R ) == NULL)   {
             if( R == Racine)   {
               Aff_val_RAs(B , Fd_As(R ) ) ;
               Liberernoeud_As(R ) ;
               }
             else
               {
               if( R == Fg_As(P ))   {
                 Aff_fg_As(P , Fd_As(R ) ) ;
                 Liberernoeud_As(R ) ;
                 }
               else
                 {
                 Aff_fd_As(P , Fd_As(R ) ) ;
                 Liberernoeud_As(R ) ;

               }
             } }
           else
             {
             Q  =  R ;
             T  =  Fd_As(R ) ;
             while( Fg_As(T ) != NULL)  {
               Q  =  T ;
               T  =  Fg_As(T ) ;

             } ;
             Aff_info_As(R , Info_As(T ) ) ;
             if( T == Fd_As(R ))   {
               if( Fd_As(T ) == NULL)   {
                 Aff_fd_As(R , NULL ) ;
                 Liberernoeud_As(T ) ;
                 }
               else
                 {
                 Aff_fd_As(R , Fd_As(T ) ) ;
                 Liberernoeud_As(T ) ;

               } }
             else
               {
               if( Fd_As(T ) == NULL)   {
                 Aff_fg_As(Q , NULL ) ;
                 Liberernoeud_As(T ) ;
                 }
               else
                 {
                 Aff_fg_As(Q , Fd_As(T ) ) ;
                 Liberernoeud_As(T ) ;

               }
             }
           }
         }
       }
     }
    }

#endif // FONCTION_H_INCLUDED
