//
//  oppgave15.c
//  ProgKjor
//
//  Created by William Seiner on 23/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>

int main () {           // Starter programmet
    int tall1, tall2;
    char svar;
    
    do {
        printf("Skriv inn tall nr1: "); scanf("%i", &tall1);
        
        printf("Skriv inn tall nr2: "); scanf("%i", &tall2);
        
        printf("%8i + %i = %i\n", tall1, tall2, tall1+tall2);
        printf("%8i - %i = %i\n", tall1, tall2, tall1-tall2);
        printf("%8i * %i = %i\n", tall1, tall2, tall1*tall2);
        
        printf("\nVil du fortsette? (J/N)"); scanf(" %c", &svar);
    } while(svar=='j'||svar=='J');
    
    
    
    return 0;           //Avslutter programmet
}
