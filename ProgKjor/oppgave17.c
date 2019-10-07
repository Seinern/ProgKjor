//
//  oppgave17.c
//  ProgKjor
//
//  Created by William Seiner on 30/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

const int MAXLOPERE=10;

int main () {           // Starter programmet
    
    int i, distanse, antall500, antallDeltakere, minutter, sekunder, hundredels;
    
    float poengsum;
    
    char brukerSvar;
    
    do{
        do {
            printf("\n\nSkriv inn lovlig distanse: ");
            scanf("%i", &distanse);
        }  while(distanse != 500   &&  distanse != 1500 && distanse != 3000  &&  distanse != 5000);
    
        antall500=distanse/500;
    
        do {
            printf("Skriv inn antall deltakere(1-%i): ", MAXLOPERE);
            scanf("%i", &antallDeltakere);
        }  while(antallDeltakere<1 || antallDeltakere>MAXLOPERE);
    
        for (i=0; i<antallDeltakere; i++){
            do{
                printf("Skriv inn resultat: (MM SS hh): ");
                scanf("%i%i%i", &minutter, &sekunder, &hundredels);
            } while (minutter<=0 && sekunder<=0 && hundredels<=0);
            
            poengsum=((minutter*60)+sekunder+(hundredels/100.0))/antall500;
            
            printf("\n%i. deltagers poengsum: %.2f\n\n\n", i+1, poengsum);
        }
    
        printf("\n\nLese tider om en ny distanse (j/N):  ");
        scanf(" %c", &brukerSvar);
        brukerSvar = toupper(brukerSvar);
    } while (brukerSvar == 'J');

        printf("\n\n");

        return 0;
}
