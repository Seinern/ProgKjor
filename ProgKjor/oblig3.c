/**
*  oblig3.c
*  ProgKjor
*
*  Created by William Seiner on 16/10/2019.
*  Copyright © 2019 William Seiner. All rights reserved.
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

const int STRLEN = 80; ///< Max.tekstlengde.
const int ANTINT = 20; ///< Lengden på int-array.

int antallIArray(int tall[], const int n, const int min, const int max);
void fyllArray(int tall[], const int n);
char lesKommando(void);
int lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
bool sjekkTekst(const char tekst[]);
void skrivMeny(void);

int main()  {
    char kommando;
    int  tallene[ANTINT];
    char teksten[STRLEN];
    
    skrivMeny();
    kommando = lesKommando();
    
    while (kommando != 'Q') {
        switch (kommando) {
            case 'F': fyllArray(tallene, ANTINT);
                break;
            case 'A':
                printf("\n\tAntall i arrayen i intervallet 0-2000: %i\n",
                antallIArray(tallene, ANTINT, 0, 2000));
                break;
            case 'L': lesTekst("Postnummer og -sted", teksten);
                break;
            case 'S':
                printf("\n\tTeksten er%s et gyldig postnr og -sted.\n",
                ((!sjekkTekst(teksten)) ? " IKKE" : ""));
                break;
            default: skrivMeny();
                break;
        }
    }
    kommando = lesKommando();
    return 0;
}

/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren nÂr ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min - 'max'
 */
int lesTall(const char tekst[], const int min, const int max)  {
    int tall;
    do  {
        printf("\t%s (%i-%i):  ", tekst, min, max);
        scanf("%i", &tall);     getchar();
    } while (tall < min  ||  tall > max);
    return tall;
}

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
char lesKommando()  {
    char tegn;
    printf("Skriv kommando:  ");
    scanf(" %c", &tegn);   getchar();
    return (toupper(tegn));
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])  {
    printf("\t%s:  ", ledetekst);
    gets(tekst);                    //  Oppdaterer ORIGINALEN/aktuell parameter.
}

/**
 *  Skriver ut en meny med kommandoer som kan brukes i programmet.
 */
void skrivMeny() {
    printf("Kommandomeny:\n");
    printf("F for å fylle array\n");
    printf("A skriver ut antall tall i arrayen mellom 0 og 2000\n");
    printf("L for å lese teksten (Postnummer og poststed)\n");
    printf("S for å sjekke om postnummer og poststed er gyldig\n");
    printf("Q for å stoppe programmet");
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   tall  -  int-array som fylles med innleste tall
 *  @param   n     -  Maks antall ganger for-løkken skal gå
 *
 *  @see lesTall()
 */
void fyllArray(int tall[], const int n) {
    for(int i=0; i<n; i++) tall[i]+=lesTall("Skriv inn heltall ", 0, 10000);
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   tall   - Int-array for tall
 *  @param   n      - Maks antall ganger for-løkken skal gå
 *  @param   min    - Minimum for tallverdi fra array
 *  @param   max    - Maksimum for tallverdi fra array
 *
 *  @return  Antall tall fra int-array mellom min og max
 */
int antallIArray(int tall[], const int n, const int min, const int max) {
    int antall=0;
    for(int i=0; i<n; i++){
        if (tall[i] > min && tall[i] < max) antall++;
    }
    return antall;
}

bool sjekkTekst(const char tekst[]) {
    if (<#condition#>) {
        <#statements#>
    } else {
        <#statements#>
    }
    return printf("gay");
}
