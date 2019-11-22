//
//  oppgave33.c
//  ProgKjor
//
//  Created by William Seiner on 21/11/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "LesData.h"

const int STRLEN=20;

int finnLengde(const char* tp);
char* finnLengsteTekst(const char* tp, const char* tp2);

int main() {
    char tekst[STRLEN], tekst2[STRLEN];
    
    lesText("Skriv tekst", tekst, STRLEN);
    
    printf("\n\nLengde på tekst: %i", finnLengde(tekst));
    
    lesText("\n\nSkriv tekst 2:", tekst2, STRLEN);
    
    printf("\n\nLengde på tekst: %i", finnLengde(tekst2));
    
    printf("\n\nTeksten som er lengst: %s", finnLengsteTekst(tekst, tekst2));
    
    printf("\n\n\n");
    
    return 0;
}

int finnLengde(const char* tp) {
    int lengde=0;
    do {
        lengde++;
    } while (*(tp+lengde)!='\0');
    return lengde;
}

char* finnLengsteTekst(const char* tp, const char* tp2) {
    int lengde1, lengde2;
    
    lengde1=finnLengde(tp);
    lengde2=finnLengde(tp2);
    
    char cArray[STRLEN];
    char* cPeker;
    
    cPeker=&cArray[0];
    
    if (lengde1>lengde2) cPeker="tekst 1";
    else if (lengde2==lengde1) cPeker="like lange";
    else cPeker="tekst 2";
    
    return cPeker;
}
