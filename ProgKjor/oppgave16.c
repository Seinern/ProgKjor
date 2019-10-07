//
//  oppgave16.c
//  ProgKjor
//
//  Created by William Seiner on 30/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

const int MINVERDI=1;
const int MAXVERDI=10000;
const int INTLEN=5;
const int CHARLEN=10;

int main () {           // Starter programmet
    
    int tallene[INTLEN];
    int i, tall;
    
    char tegnene[CHARLEN];
    char tegn;
    
    for(i=0; i<INTLEN; i++){
        do {
            printf("%i. tall (%i-%i): ", i+1, MINVERDI, MAXVERDI);
            scanf("%i", &tall);
        } while(tall<MINVERDI || tall>MAXVERDI);
        tallene[i]=tall;
    }
    
    printf("\n\n");
    
    for(i=0; i<5; i++)
        printf("%i. tallet er %i\n", i+1, tallene[i]);
    
    //*****************************************************************************************************************//
    
    printf("\n\n\n\n");
    
    for(i=0; i<CHARLEN; i++){
        do {
            printf("%i. bokstav (A-Z): ", i+1);
            scanf(" %c", &tegn);
            tegn=toupper(tegn);
        } while(tegn<'A' || tegn>'Z');
        tegnene[i]=tegn;
    }
    
    printf("\n\n");
    
    for(i=0; i<CHARLEN; i++)
        printf("%i. tallet er %c\n", i+1, tegnene[i]);
    
    printf("\n\n");
    
    return 0;           //Avslutter programmet
}



