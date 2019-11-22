//
//  oppgave31.c
//  ProgKjor
//
//  Created by William Seiner on 21/11/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include "LesData.h"

#define STRLEN 80
#define ARRLEN 10

struct Person {
    char navn[STRLEN];
    char skoleklasse;
    int skonummer;
};

int main() {
    struct Person* gPersoner;
    struct Person PersonerArr;
    
    gPersoner=&PersonerArr;
    
//    for (int i=0; i<ARRLEN; i++) {
    lesText("Navn", gPersoner->navn, STRLEN);
    gPersoner->skoleklasse = lesChar("Skoleklasse");
    gPersoner->skonummer = lesInt("Skonummer", 10, 60);
    printf("\nNavn: %s \t Skoleklasse: %c \t Skonummer: %i \n", gPersoner->navn, gPersoner->skoleklasse, gPersoner->skonummer);
    printf("\nNavn: %s \t Skoleklasse: %c \t Skonummer: %i \n", PersonerArr.navn, PersonerArr.skoleklasse, PersonerArr.skonummer);
    
//    }
    
    return 0;
}
