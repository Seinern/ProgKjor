//
//  oppgave34.c
//  ProgKjor
//
//  Created by William Seiner on 21/11/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "LesData.h"

const int STRLEN=20;

void finnTegn(const char* t, char* f, char* m, char* s);

int main() {
    char fin, mongo, stygg;
    char tekst[STRLEN];
    
    
    lesText("Skriv tekst", tekst, STRLEN);
    
    finnTegn(tekst, fin, mongo, stygg);
}
            
void finnTegn(const char* t, char* f, char* m, char* s) {
    int verdi=strlen(t);
    f=t[0];
    s=t[verdi-1];
    m=t[verdi/2];
    printf("\nFørste char: %c",f);
    printf("\nMiderste char: %c", m);
    printf("\nSiste char: %c", s);
    
    printf("\n\n");
    }
