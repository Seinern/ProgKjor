/**
 *  Oblig 2 i Grunnleggende programmering.
 *
 *  Program:
 *
 *
 *  @file    oblig2.c
 *  @author  William Seiner
 */

#include <stdio.h>
#include <ctype.h>

const int MAXREGNEOPERASJONER = 50;

int main () {           // Starter programmet
    
    int i;
    int antallOperasjoner = 0;
    float tallene [MAXREGNEOPERASJONER];
    float akkumulator=0, tall;
    
    char regneOperasjon;
    char regneOperasjoner[MAXREGNEOPERASJONER];
    
    
    
    printf("Enkel kalkulator:\n\n");
    
    do {
        printf("= %f\n\n", akkumulator);
        
        printf(": "); scanf(" %c %f", &regneOperasjon, &tall);
        
        regneOperasjon = tolower(regneOperasjon);
        
        switch (regneOperasjon)  {
            case '+':   akkumulator+=tall;                      break;
            case '-':   akkumulator-=tall;                      break;
            case '*':   akkumulator*=tall;                      break;
            case '/':   akkumulator/=tall;                      break;
            case 't':   akkumulator=tall;                       break;
            case 'c':   akkumulator=0;                          break;
            default:    printf("\nFeil! Ukjent kommando gitt\n");    break;
        }
        antallOperasjoner++;
    } while(regneOperasjon!='s');
    
    printf("\nOperasjonen og tallene involvert:  \n");
    for (i = 0;  i < antallOperasjoner;  i++)
        printf("%c og tallet: %f", regneOperasjoner[i], tallene[i]);
        
    
    return 0;           //Avslutter programmet
}
