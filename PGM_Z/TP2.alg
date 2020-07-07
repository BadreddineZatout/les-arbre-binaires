
   SOIENT
       L , B , Lb , S DES LISTEBI DE ARB DE CHAINE ;
       R , P , Q DES ARB DE CHAINE ;
       Tab UNE VECTEUR ( 1000 ) DE CHAINE ;
       N , I DES ENTIER ;
       Ch UNE CHAINE ;
       Existe , Trouve DES BOOLEEN ;
       Rech_bi , Ins , Rech_abr , Supp DES ACTION ;
       F UNE FILE DE ARB DE CHAINE ;
       A UN ARB DE CHAINE ;
       M UN POINTEUR VERS ARB DE CHAINE ;
      
   DEBUT
       ALLOUER ( L ) ;
       AFF_ADRD ( L , L ) ;
       AFF_ADRG ( L , L ) ;
       POUR I := 1 , 1000 :
           N := ALEANOMBRE ( 31 ) + 1 ;
           Ch := ALEACHAINE ( N ) ;
           AFF_ELEMENT ( Tab [ I ] , Ch ) ;
           APPEL Rech_bi ( Ch , L , B , Trouve ) ;
           SI ( Trouve ) :
               SI ( VALEUR ( L ) = NIL ) :
                   CREERNOEUD ( R ) ;
                   AFF_INFO ( R , Ch ) ;
                   AFF_VAL ( L , R ) ;
                  
               SINON
                   R := VALEUR ( B ) ;
                   APPEL Ins ( Ch , R ) ;
                  
               FSI
           SINON
               CREERNOEUD ( R ) ;
               ALLOUER ( Lb ) ;
               AFF_VAL ( Lb , R ) ;
               AFF_INFO ( R , Ch ) ;
               SI LONGCHAINE ( Ch ) > LONGCHAINE ( INFO ( VALEUR ( B ) ) ) :
                   AFF_ADRG ( SUIVANT ( B ) , Lb ) ;
                   AFF_ADRD ( Lb , SUIVANT ( B ) ) ;
                   AFF_ADRD ( B , Lb ) ;
                   AFF_ADRG ( Lb , B ) ;
                  
               SINON
                   AFF_ADRD ( PRECEDENT ( B ) , Lb ) ;
                   AFF_ADRG ( Lb , PRECEDENT ( B ) ) ;
                   AFF_ADRG ( B , Lb ) ;
                   AFF_ADRD ( Lb , B ) ;
                  
               FSI
           FSI ;
           SI ( LONGCHAINE ( Ch ) < LONGCHAINE ( INFO ( VALEUR ( L ) ) ) ) :
               L := Lb ;
              
           FSI
       FPOUR ;
       B := L ;
       TQ SUIVANT ( B ) # L :
           ECRIRE ( INFO ( VALEUR ( B ) ) ) ;
           B := SUIVANT ( B ) ;
          
       FTQ ;
       ECRIRE ( INFO ( VALEUR ( B ) ) ) ;
       POUR I := 1 , 1000 :
           Ch := ELEMENT ( Tab [ I ] ) ;
           APPEL Supp ( Ch , L ) ;
          
       FPOUR ;
       SI L = NIL :
           ECRIRE ( 'la liste est vide' ) ;
          
       FSI ;
      
   FIN
  /*******************************************************/
   ACTION Rech_bi ( Val , Li , Bi , Tr ) ;
   SOIENT
       Val UNE CHAINE ;
       Li , Bi DES LISTEBI DE ARB DE CHAINE ;
       Tr , Existe DES BOOLEEN ;
       R UN ARB DE CHAINE ;
       J UN ENTIER ;
      
   DEBUT
       Bi := Li ;
       R := VALEUR ( Bi ) ;
       Tr := FAUX ;
       Existe := VRAI ;
       SI R = NIL :
           Tr := VRAI ;
          
       SINON
           SI LONGCHAINE ( Val ) <= 15 :
               TQ ( NON Tr ) ET ( LONGCHAINE ( INFO ( R ) ) <= 15 ) ET ( SUIVANT ( Bi ) # Li ) ET ( Existe ) :
                   SI ( LONGCHAINE ( INFO ( R ) ) <= LONGCHAINE ( Val ) ) :
                       SI LONGCHAINE ( Val ) = LONGCHAINE ( INFO ( R ) ) :
                           Tr := VRAI ;
                          
                       SINON
                           Bi := SUIVANT ( Bi ) ;
                           R := VALEUR ( Bi ) ;
                          
                       FSI
                   SINON
                       Existe := FAUX ;
                      
                   FSI
               FTQ ;
               SI ( SUIVANT ( Bi ) = Li ) ET ( LONGCHAINE ( INFO ( R ) ) = LONGCHAINE ( Val ) ) :
                   Tr := VRAI ;
                  
               FSI
           SINON
               SI LONGCHAINE ( Val ) = LONGCHAINE ( INFO ( R ) ) :
                   Tr := VRAI ;
                  
               SINON
                   Bi := PRECEDENT ( Bi ) ;
                   R := VALEUR ( Bi ) ;
                  
               FSI ;
               TQ ( NON Tr ) ET ( LONGCHAINE ( INFO ( R ) ) > 15 ) ET ( PRECEDENT ( Bi ) # Li ) ET ( Existe ) :
                   SI ( LONGCHAINE ( INFO ( R ) ) >= LONGCHAINE ( Val ) ) :
                       SI LONGCHAINE ( Val ) = LONGCHAINE ( INFO ( R ) ) :
                           Tr := VRAI ;
                          
                       SINON
                           Bi := PRECEDENT ( Bi ) ;
                           R := VALEUR ( Bi ) ;
                          
                       FSI
                   SINON
                       Existe := FAUX ;
                      
                   FSI
               FTQ ;
               SI ( PRECEDENT ( Bi ) = Li ) ET ( LONGCHAINE ( INFO ( R ) ) = LONGCHAINE ( Val ) ) :
                   Tr := VRAI ;
                  
               FSI
           FSI
       FSI
   FIN
  /*******************************************************/
   ACTION Ins ( V , Racine ) ;
   SOIENT
       V UNE CHAINE ;
       Racine , P , A , Q DES ARB DE CHAINE ;
       Trouv UN BOOLEEN ;
      
   DEBUT
       P := NIL ;
       A := Racine ;
       APPEL Rech_abr ( V , A , P , Trouv ) ;
       SI ( NON Trouv ) :
           CREERNOEUD ( Q ) ;
           AFF_INFO ( Q , V ) ;
           SI V > INFO ( P ) :
               AFF_FD ( P , Q ) ;
              
           SINON
               AFF_FG ( P , Q ) ;
              
           FSI
       FSI
   FIN
  /*******************************************************/
   ACTION Rech_abr ( V , A , P , Bool ) ;
   SOIENT
       V UNE CHAINE ;
       A , P DES ARB DE CHAINE ;
       Bool UN BOOLEEN ;
      
   DEBUT
       Bool := FAUX ;
       P := NIL ;
       TQ ( NON Bool ) ET ( A # NIL ) :
           SI INFO ( A ) = V :
               Bool := VRAI ;
              
           SINON
               P := A ;
               SI V < INFO ( A ) :
                   A := FG ( A ) ;
                  
               SINON
                   A := FD ( A ) ;
                  
               FSI
           FSI
       FTQ
   FIN
  /****************************************************************/
   ACTION Supp ( V , L ) ;
   SOIENT
       V UNE CHAINE ;
       Racine , P , R , Q , T DES ARB DE CHAINE ;
       Trouv1 , Trouv2 UN BOOLEEN ;
       L , B UNE LISTEBI DE ARB DE CHAINE ;
      
   DEBUT
       APPEL Rech_bi ( V , L , B , Trouv1 ) ;
       SI Trouv1 :
           P := NIL ;
           R := VALEUR ( B ) ;
           Racine := VALEUR ( B ) ;
           APPEL Rech_abr ( V , R , P , Trouv2 ) ;
           SI Trouv2 :
               SI FD ( R ) = NIL :
                   SI FG ( R ) = NIL :
                       SI R = Racine :
                           SI B = L :
                               L := SUIVANT ( L ) ;
                              
                           FSI ;
                           SI L = SUIVANT ( L ) :
                               L := NIL
                           SINON
                               AFF_ADRD ( PRECEDENT ( B ) , SUIVANT ( B ) ) ;
                               AFF_ADRG ( SUIVANT ( B ) , PRECEDENT ( B ) ) ;
                               LIBERERNOEUD ( R ) ;
                               LIBERER ( B ) ;
                              
                           FSI
                       SINON
                           SI R = FD ( P ) :
                               AFF_FD ( P , NIL ) ;
                              
                           SINON
                               AFF_FG ( P , NIL ) ;
                              
                           FSI ;
                           LIBERERNOEUD ( R ) ;
                          
                       FSI
                   SINON
                       SI R = Racine :
                           AFF_VAL ( B , FG ( R ) ) ;
                           LIBERERNOEUD ( R ) ;
                          
                       SINON
                           SI R = FG ( P ) :
                               AFF_FG ( P , FG ( R ) ) ;
                               LIBERERNOEUD ( R ) ;
                              
                           SINON
                               AFF_FD ( P , FG ( R ) ) ;
                               LIBERERNOEUD ( R ) ;
                              
                           FSI
                       FSI
                   FSI
               SINON
                   SI FG ( R ) = NIL :
                       SI R = Racine :
                           AFF_VAL ( B , FD ( R ) ) ;
                           LIBERERNOEUD ( R ) ;
                          
                       SINON
                           SI R = FG ( P ) :
                               AFF_FG ( P , FD ( R ) ) ;
                               LIBERERNOEUD ( R ) ;
                              
                           SINON
                               AFF_FD ( P , FD ( R ) ) ;
                               LIBERERNOEUD ( R ) ;
                              
                           FSI
                       FSI
                   SINON
                       Q := R ;
                       T := FD ( R ) ;
                       TQ FG ( T ) # NIL :
                           Q := T ;
                           T := FG ( T ) ;
                          
                       FTQ ;
                       AFF_INFO ( R , INFO ( T ) ) ;
                       SI T = FD ( R ) :
                           SI FD ( T ) = NIL :
                               AFF_FD ( R , NIL ) ;
                               LIBERERNOEUD ( T ) ;
                              
                           SINON
                               AFF_FD ( R , FD ( T ) ) ;
                               LIBERERNOEUD ( T ) ;
                              
                           FSI
                       SINON
                           SI FD ( T ) = NIL :
                               AFF_FG ( Q , NIL ) ;
                               LIBERERNOEUD ( T ) ;
                              
                           SINON
                               AFF_FG ( Q , FD ( T ) ) ;
                               LIBERERNOEUD ( T ) ;
                              
                           FSI
                       FSI
                   FSI
               FSI
           FSI
       FSI
   FIN
