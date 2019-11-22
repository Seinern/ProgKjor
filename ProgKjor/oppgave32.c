//
//  oppgave32.c
//  ProgKjor
//
//  Created by William Seiner on 21/11/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>
#include "LesData.h"

const int STRLEN=20;

int main() {
    int tall[STRLEN];
    int* tallene;
    
    tallene=&tall[STRLEN];
    
    for (int i=0; i<STRLEN; i++) {
        tall[i]=i;
        printf("\n %i", tall[i-1]);
        printf("\nSkuff %i. inneholder nå %i", i, *(tall+i)*2);
    }
    
    printf("\n\n\n\n\n");
    
    char cArray[STRLEN]={'A','B','C','D','E','A','B','C','D','E','A','B','C','D','E','A','B','C','D','E'};
    
    for (int j=0; j<STRLEN; j++) {
        printf("%c ", cArray[j]);
    }
    
    printf("\n\n\n");
    
    char* cPeker;
    
    cPeker=&cArray[0];
    
    for (int j=0; j<STRLEN; j++) {
        if (*(cPeker+j)=='C') *(cPeker+j)='X';
        if (*(cPeker+j)=='E') *(cPeker+j)='8';
        printf("%c ", *(cPeker+j));
    }
    
    printf("\n\n\n");
    
    return 0;
}
