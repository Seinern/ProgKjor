/**
 *   Programeksempel nr 19 - Switch.
 *
 *   @file     EKS_19.C
 *   @author   Frode Haug, NTNU
 */

#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  toupper
#include <math.h>               //  sqrt

/**
 *  Hovedprogrammet:
 */
int main ()  {

//  BETINGELSESOPERATOR:

    int  fartsGrense;           //  Fartsgrensen i aktuelt område/sted.
    char valg;                  //  Brukersvaret - 'B' eller 'L'.

    do  {                       //  Leser og sikrer at kun 'B'/'L' godtas:
      printf("\nBy eller landevei (B/L):  ");
      scanf(" %c", &valg);  valg = toupper(valg);
    } while (valg != 'B'  &&  valg != 'L');

    if (valg == 'B')            //  Tilordner ut fra brukerens valg:
        fartsGrense = 50;
    else
        fartsGrense = 80;

    printf("\tFartsgrensen er satt til:  %i\n", fartsGrense);

// NB NB NB:  Når det KUN er EN if og EN else, SAMT at det er
//            SAMME VARIABEL SOM OPPDATERES I BEGGE GRENER,
//            KAN selve tilordningen også skrives som:

    fartsGrense = (valg == 'B') ? 50 : 80;    //  Tilordner ut fra valget:

    printf("\tFartsgrensen er satt til:  %i\n\n", fartsGrense);


//*************************************************************************

    char steder[][14] = { "Ikke definert", "Tettbebodd", "By", "Landevei",
                          "Motorvei", "Autobahn" };
    int  indeks;
                                             //  Leser en fartsgrense:
    printf("\nFartsgrense (30, 50, 80, 100, 140):  ");
    scanf("%i", &fartsGrense);

    switch (fartsGrense)  {                  //  Ut fra innlest verdi, settes
       case  30:  indeks = 1;   break;       //     indeks for aktuell tekst:
       case  50:  indeks = 2;   break;
       case  80:  indeks = 3;   break;
       case 100:  indeks = 4;   break;
       case 140:  indeks = 5;   break;
       default:   indeks = 0;   break;
    }
                                             //  Skriver satt tekst:
    printf("\nDenne fartsgrensen gjelder i/på:   %s\n\n", steder[indeks]);


//************************************************************************

    int  posX = 3, posY = 4;                 //  X- og Y-koordinat i et spill.
    char retning;                            //  Valgt retning å gå i.

    printf("Nåværende posisjon:  %i,%i\n\n", posX, posY);
    printf("Retning for bevegelse (N, S, O, V, Q):  ");
    scanf(" %c", &retning);   retning = toupper(retning);

    while (retning != 'Q')  {
        switch (retning)  {                   //  Ut fra valgt retning,
          case 'N':   posY++;    break;       //    endres til ny posisjon:
          case 'S':   posY--;    break;
          case 'V':   posX++;    break;
          case 'O':   posX--;    break;
          default:    printf("\tUlovlig retning!\n");  break;
        }
        printf("\tNy posisjon:  %i,%i\n\n", posX, posY);
        printf("Retning for bevegelse (N, S, O, V, Q):  ");
        scanf(" %c", &retning);   retning = toupper(retning);
    }


//*******************************************************************

//  NB NB NB:   IKKE ALLTID vi gjør noe av det samme i hvert 'case'-tilfelle!

    printf("\n\nKommando (H, G, ......, Q):  ");
    scanf(" %c", &valg);   valg = toupper(valg);

    while (valg != 'Q')  {
        switch (valg)  {
          case 'H':  printf("\tEn trekant med katetere lik '7' og '12' har ");
                     printf("hypotenus lik:  %.2f\n", sqrt(7*7 + 12*12));
                                                                break;
          case 'G':   for (int i = 1;  i < 10;  i++)
                          printf("\t%2i * 146 = %4i\n", i, i*146);
                                                                break;
//        case 'X':   /*  Kode ..........  */                   break;
//        case 'Y':   /*  Kode ..........  */                   break;
          default:    printf("\tUlovlig valg!\n");              break;
        }
        printf("\nKommando (H, G, ......, Q):  ");
        scanf(" %c", &valg);   valg = toupper(valg);
    }


//*******************************************************************

//  MEGET VANLIG 'MAIN' SENERE I HØST
//        (NB: Alt det bortkommenterte lærer vi om ifm. funksjoner.):

    //  lesFraFil(();
    //  skrivMeny();
    printf("\n\nKommando (N, S, A, E, F, K, Q):  ");
    scanf(" %c", &valg);   valg = toupper(valg);

    while (valg != 'Q')  {
        switch (valg)  {
          case 'N':   /*  nyPerson();       */    break;
          case 'S':   /*  skrivPerson();    */    break;
          case 'A':   /*  skrivPersoner();  */    break;
          case 'E':   /*  endrePerson();    */    break;
          case 'F':   /*  fjernPerson();    */    break;
          case 'K':   /*  kopierPerson();   */    break;
          default:    /*  skrivMeny();      */    break;
        }
        printf("Kommando (N, S, A, E, F, K, Q):  ");
        scanf(" %c", &valg);   valg = toupper(valg);
    }
    //  skrivTilFil();

    return 0;
}
