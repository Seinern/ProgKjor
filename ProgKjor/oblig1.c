/**
*  Oblig 1 i Grunnleggende programmering.
*
*  Program:
*  -Leser to lags navn, og skriver deres to linjer fra en tabell
*  -Leser lagenes målscore og poeng, oppdaterer tabellen, og skriver dette så ut igjen
*
*  @file    oblig1.c
*  @author  William Seiner
*/

#include <stdio.h>      //  printf, scanf

const int STRLEN=20;   

int main () {           // Starter programmet
    
    int maalA, maalB, poengA, poengB;   // Lager variablene for poeng og mål
    int tallA[] = {10, 20, 10, 23};      // Lager array for hjemmelaget
    int tallB[] = {10, 12, 32, 34};      // Lager array for bortelaget
    char navnA[STRLEN], navnB[STRLEN];    // Lager variablene for lagnavnene
    
    // Bruker gets() på de to neste linjene pga. mulighet for mellomrom i lagnavnene:
    
    printf("Skriv inn hjemmelagets navn: "); gets(navnA);   // Leser navnet til hjemmelaget
    
    printf("Skriv inn bortelagets navn: "); gets(navnB);    // Leser navnet til bortelaget
    
    printf("%s: %i %i-%i %i\n", navnA, tallA[0], tallA[1], tallA[2], tallA[3]);   // Skriver ut statistikk for hjemmelaget
    
    printf("%s: %i %i-%i %i\n", navnB, tallB[0], tallB[1], tallB[2], tallB[3]);   // Skriver ut statistikk for bortelaget
    
    printf("Skriv inn hjemmelagets mål: "); scanf("%i", &maalA);       // Leser antall hjemmemål
    
    printf("Skriv inn bortelagets mål: "); scanf("%i", &maalB);        // Leser antall bortemål
    
    tallA[1]+=maalA;        // Legger til scorede mål for hjemmelaget
    tallA[2]+=maalB;        // Legger til mål mot seg for hjemmelaget
    
    tallB[1]+=maalB;        // Legger til scorede mål for bortelaget
    tallB[2]+=maalA;        // Legger til mål mot seg for bortelaget
    
    printf("Skriv inn hjemmelagets poeng: "); scanf("%i", &poengA);     // Leser antall hjemmepoeng
    
    printf("Skriv inn bortelagets poeng: "); scanf("%i", &poengB);      // Leser antall bortepoeng
    
    tallA[3]+=poengA;       // Legger til poeng for hjemmelaget
    tallB[3]+=poengB;       // Legger til poeng for bortelaget
    
    tallA[0]++;             // Registrer en kamp for hjemmelaget
    tallB[0]++;             // Registrer en kamp for bortelaget
    
    printf("%s: %i %i-%i %i\n", navnA, tallA[0], tallA[1], tallA[2], tallA[3]);     // Viser ny statistikk for hjemmelaget
    
    printf("%s: %i %i-%i %i\n", navnB, tallB[0], tallB[1], tallB[2], tallB[3]);     // Viser ny statistikk for bortelaget

    return 0;           //Avslutter programmet
}

