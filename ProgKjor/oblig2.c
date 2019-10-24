/**
 *  Oblig 2 i Grunnleggende programmering.
 *
 *  Program:
 *  -Kalkulator med en akkumulator
 *  -Leser regneoperasjoner og tall fra brukeren
 *
 *  @file    oblig2.c
 *  @author  William Seiner
 */

#include <stdio.h>      // scanf, printf
#include <ctype.h>      // tolower
#include <stdbool.h>    // bool

const int MAXREGNEOPERASJONER = 50;     ///< Max antall regneoperasjoner

/**
 *  Hovedprogrammet:
 */

int main () {           // Starter programmet
    
    int antallOperasjoner = 0;                          // Lager int-variabel for antall operasjoner
    
    float tallene [MAXREGNEOPERASJONER],
    akkumulator=0, tall=0.0;                         // Lager float variabler og array
    
    char regneOperasjoner[MAXREGNEOPERASJONER],
    regneOperasjon;                                 // Lager char variabler og array
    
    bool lagreOperasjon;                            // Lager en bool for om operasjon skal lagres
    
    printf("Enkel kalkulator:\n\n");
    
    printf("= %f\n", akkumulator);                    // Skriver ut akkumulatoren
    
    do {
        printf("\n: "); scanf (" %c", &regneOperasjon);     // Leser regneoperasjonen
        
        regneOperasjon = tolower(regneOperasjon);         // Gjør om til liten bokstav hvis nødvendig
        
        lagreOperasjon=true;                             // Setter at om operasjonen skal lagres til true
        
        switch (regneOperasjon)  {                          // Switch for de forskjellige regneoperasjonene
                
            case '+':                                       // Hvis regneoperasjon er +
                scanf(" %f", &tall);                          // Leser inn tall
                printf("\n%.3f + %.3f", akkumulator, tall);     // Skriver ut regnestykke
                akkumulator+=tall;                           // Adderer akkumulator med innlest tall
                printf(" = %.3f\n", akkumulator);              // Skriver ut oppdatert akkumulator
                break;
                
            case '-':                                       // Hvis regneoperasjon er -
                scanf(" %f", &tall);                         // Leser inn tall
                printf("\n%.3f - %.3f", akkumulator, tall);    // Skriver ut regnestykke
                akkumulator-=tall;                          // Subtraherer akkumulator med innlest tall
                printf(" = %.3f\n", akkumulator);             // Skriver ut oppdatert akkumulator
                break;
                
            case '*':                                       // Hvis regneoperasjon er *
                scanf(" %f", &tall);                         // Leser inn tall
                printf("\n%.3f * %.3f", akkumulator, tall);    // Skriver ut regnestykke
                akkumulator*=tall;                          // Multipliserer akkumulator med innlest tall
                printf(" = %.3f\n", akkumulator);             // Skriver ut oppdatert akkumulator
                break;
                
            case '/':                                       // Hvis regneoperasjon er /
                scanf(" %f", &tall);                         // Leser inn tall
                // Hvis man deler på 0:
                if (tall==0) {
                    printf ("\nFeil! Dele på null er tull!\n");   // Skriver ut at man ikke kan dele på 0
                    printf("\n= %.3f\n", akkumulator);         // Skriver ut akkumulator
                    lagreOperasjon=false;                    // Setter lagreOperasjon til false
                }
                // Hvis man ikke deler på 0:
                else {
                    printf("\n%.3f / %.3f", akkumulator, tall);     // Skriver ut regnestykke
                    akkumulator/=tall;                           // Dividerer akkumulator med innlest tall
                    printf(" = %.3f\n", akkumulator);              // Skriver ut oppdatert akkumulator
                }
                break;
                
            case 't':                                       // Hvis regneoperasjon er t
                scanf(" %f", &tall);                                    // Leser inn tall
                akkumulator=tall;                                         // Sette akkumulatoren til å bli det innleste tallet
                printf("\nAkkumulatoren er nå satt til: %.3f\n", akkumulator);     // Skriver ut oppdatert akkumulator
                break;
                
            case 'c':                                       // Hvis regneoperasjon er c
                akkumulator=0;                             // Akkumulator setter til 0
                printf("\nAkkumulatoren settes til 0\n");       // Skriver ut at akkumulator settes til 0
                printf("\n= %.3f\n", akkumulator);           // Skriver ut akkumulator som nullstillt
                break;
                
            case 's':                                       // Hvis regneoperasjon er s
                printf("\nEnkel kalkulator stopper\n");         // Skriverr ut at kalkulatoren stopper
                lagreOperasjon=false;                       // Setter lagreOperasjon til false
                break;
                
            default:                                        // Hvis regneoperasjon er noe annet
                printf("\n Feil! Ukjent kommando gitt\n");      // Skriver ut at ukjent kommando er gitt
                printf("\n= %.3f\n", akkumulator);           // Skriver ut akkumulatoren
                lagreOperasjon=false;                      // Setter lagreOperasjon til false
                break;
        }
        
        // Hvis lagreOperasjon er true lagres operasjonen og tallet brukt i hver sin array og antallOperasjoner økes med 1:
        if(lagreOperasjon) {
            regneOperasjoner[antallOperasjoner]+=regneOperasjon;
            tallene[antallOperasjoner]+=tall;
            antallOperasjoner++;
        }
        
    } while(regneOperasjon!='s' && antallOperasjoner<MAXREGNEOPERASJONER);  // Kalkulatoren stopper hvis regneoperasjonen blir
                                                                            // s eller hvis antall operasjoner blir 50
    
    // Skriver ut alle operasjonene og de tallene som ble brukt:
    printf("\nOperasjonen og tallene brukt:  \n");
    for (int i = 0;  i < antallOperasjoner;  i++)
        printf("\n%c og tallet: %.3f", regneOperasjoner[i], tallene[i]);
    
    printf("\n\n");
    
    return 0;           //Avslutter programmet
}
