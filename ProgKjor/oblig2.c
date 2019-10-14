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
#include <ctype.h>      // tolower
#include <stdbool.h>    //

const int MAXREGNEOPERASJONER = 50;

int main () {           // Starter programmet
    
    int i, antallOperasjoner = 0;
    float tallene [MAXREGNEOPERASJONER], akkumulator=0, tall=0.0;
    char regneOperasjoner[MAXREGNEOPERASJONER], regneOperasjon;
    bool lagreOperasjon;
    
    
    
    printf("Enkel kalkulator:\n\n");
    
    printf("= %f\n", akkumulator);
    
    do {
        printf("\n: "); scanf (" %c", &regneOperasjon);
        
        regneOperasjon = tolower(regneOperasjon);
        
        lagreOperasjon=true;
        
        switch (regneOperasjon)  {
            case '+':
                scanf(" %f", &tall);
                printf("\n%.3f + %.3f", akkumulator, tall);
                akkumulator+=tall;
                printf(" = %.3f\n", akkumulator);
                break;
            case '-':
                scanf(" %f", &tall);
                printf("\n%.3f - %.3f", akkumulator, tall);
                akkumulator-=tall;
                printf(" = %.3f\n", akkumulator);
                break;
            case '*':
                scanf(" %f", &tall);
                printf("\n%.3f * %.3f", akkumulator, tall);
                akkumulator*=tall;
                printf(" = %.3f\n", akkumulator);
                break;
            case '/':
                scanf(" %f", &tall);
                if (tall==0) {
                    printf ("\nFeil! Dele på null er tull!\n");
                    printf("\n= %.3f\n", akkumulator);
                    lagreOperasjon=false;
                }
                else {
                    printf("\n%.3f / %.3f", akkumulator, tall);
                    akkumulator/=tall;
                    printf(" = %.3f\n", akkumulator);
                }
                break;
            case 't':
                scanf(" %f", &tall);
                akkumulator=tall;
                printf("\nAkkumulatoren er nå satt til: %.3f\n", akkumulator);
                break;
            case 'c':
                akkumulator=0;
                printf("\nAkkumulatoren settes til 0\n");
                printf("\n= %.3f\n", akkumulator);
                break;
            case 's':
                printf("\nEnkel kalkulator stopper\n");
                lagreOperasjon=false;
                break;
            default:
                printf("\n Feil! Ukjent kommando gitt\n");
                printf("\n= %.3f\n", akkumulator);
                lagreOperasjon=false;
                break;
        }
        
        if(lagreOperasjon==true) {
            regneOperasjoner[antallOperasjoner]+=regneOperasjon;
            tallene[antallOperasjoner]+=tall;
            antallOperasjoner++;
        }
    } while(regneOperasjon!='s');
    
    printf("\nOperasjonen og tallene brukt:  \n");
    for (i = 0;  i < antallOperasjoner;  i++)
        printf("\n%c og tallet: %f", regneOperasjoner[i], tallene[i]);
    printf("\n\n");
    
    return 0;           //Avslutter programmet
}
