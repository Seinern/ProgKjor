//
//  oppgave14.c
//  ProgKjor
//
//  Created by William Seiner on 23/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include "stdio.h"

int main () {           // Starter programmet
    int tall, antallLest=0, totalSum=0;
    
    printf("Skriv inn et tall: ");
    scanf("%i", &tall);
    
    while (tall>0) {
        ++antallLest;
        totalSum+=tall;
        printf("Skriv et tall (negativt eller null for å avslutte): ");
        scanf("%i", &tall);
    }
    
    printf("\nAntall tall lest: %i\n", antallLest);
    printf("Totalsum: %i\n", totalSum);
    printf("Gjennomsnitt: %.2f\n\n", (float)(totalSum)/(antallLest));
    
    
    return 0;           //Avslutter programmet
}
