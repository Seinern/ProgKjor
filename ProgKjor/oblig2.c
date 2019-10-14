/**
 *  Oblig 2 i Grunnleggende programmering.
 *
 *  Program:
 *
 *
 *  @file    oblig2.c
 *  @author  William Seiner
 */

#include <stdio.h>      // scanf, printf
#include <ctype.h>
#include <string.h>


const int MAXREGNEOPERASJONER = 50;

int main () {           // Starter programmet
    
    int i, antallOperasjoner = 0;
    float tallene [MAXREGNEOPERASJONER], akkumulator=0, tall=0.0;
    char regneOperasjoner[MAXREGNEOPERASJONER], regneOperasjon;
    
    
    
    printf("Enkel kalkulator:\n\n");
    
    printf("= %f\n\n", akkumulator);
    
    do {
        printf("\n\n: "); scanf (" %c", &regneOperasjon);
        
        regneOperasjon = tolower(regneOperasjon);
        
        switch (regneOperasjon)  {
            case '+':
                scanf(" %f", &tall);
                printf("\n%f + %f", akkumulator, tall);
                akkumulator+=tall;
                printf(" = %f", akkumulator);                     break;
            case '-':
                scanf(" %f", &tall);
                printf("\n%f - %f", akkumulator, tall);
                akkumulator-=tall;
                printf(" = %f", akkumulator);                     break;
            case '*':
                scanf(" %f", &tall);
                printf("\n%f * %f", akkumulator, tall);
                akkumulator*=tall;
                printf(" = %f", akkumulator);                     break;
            case '/':
                scanf(" %f", &tall);
                if (tall==0)
                    printf ("\nDele på null er tull!\n\n");
                else
                    printf("\n%f / %f", akkumulator, tall);
                    akkumulator/=tall;
                    printf(" %f", akkumulator);                  break;
            case 't':
                scanf(" %f", &tall);
                akkumulator=tall;                              break;
            case 'c':   akkumulator=0;                          break;
            case 's':   printf("\nEnkel kalkulator stopper\n");      break;
            default:    printf("\n Feil! Ukjent kommando gitt\n");   break;
        }
        
        regneOperasjoner[antallOperasjoner]+=regneOperasjon;
        
        tallene[antallOperasjoner]+=tall;
        
        antallOperasjoner++;
        
    } while(regneOperasjon!='s');
    
    printf("\nOperasjonen og tallene brukt:  \n");
    for (i = 0;  i < antallOperasjoner;  i++)
        printf("\n%c og tallet: %f", regneOperasjoner[i], tallene[i]);
    printf("\n\n");
    
    return 0;           //Avslutter programmet
}
