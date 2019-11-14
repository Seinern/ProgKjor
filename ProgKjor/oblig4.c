/**
 *  Oblig 4 i grunnleggende programmering.
 *
 *  Programmet utfører forskjellige kommandoer fra brukeren.
 *
 *  @file    oblig4.c
 *  @author  William Seiner
 */

#include <stdio.h>          // scanf, printf
#include <stdbool.h>        // bool
#include <ctype.h>          // toupper, isdigit, isalpha
#include "LesData.h"        //  Verktøykasse for lesing av diverse data.

#define MAXPERS 6
#define MAXOPPG 20
const int STRLEN = 90;

struct Oppgave {
    char* navn;
    int antallTotalt,
    antallNaa;
    int hvem[MAXPERS];
};

void fjernOppgave(void);
void nyOppgave(void);
void ledigeOppgaver(void);
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void oppgaveLesData(struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
void oppgaveSlettData(struct Oppgave* oppgave);
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void personerTilknyttesOppgave(void);
void skrivMeny(void);
void skrivOppgaver(void);


struct Oppgave* gOppgavene[MAXOPPG];
int gSisteOppgave = 0;

/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;
    
    skrivMeny();
    kommando = lesChar("Skriv kommando: ");
    
    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'N':  nyOppgave();  break;
            case 'S':  skrivOppgaver();    break;
            case 'L':  ledigeOppgaver();  break;
            case 'T':  personerTilknyttesOppgave();  break;
            case 'F':  fjernOppgave(); break;
            default:   skrivMeny(); break;
        }
        kommando = lesChar("Skriv kommando: ");
    }
    
    printf("\n\n");
    return 0;
}

//void fjernOppgave();
void nyOppgave() {
    if (gSisteOppgave<MAXOPPG) {
        printf("Ny oppgave nr:  %i\n", gSisteOppgave+1); // Lager nytt maleri:
        gOppgavene[gSisteOppgave] = (struct Oppgave*) malloc(sizeof(struct Oppgave));
        oppgaveLesData(gOppgavene[gSisteOppgave]);     //  Maleriets data leses.
        gSisteOppgave++;
    }
    else {
        printf("Fuck you");
    }
    
}
void ledigeOppgaver() {

}

bool oppgaveLedigPlass(const struct Oppgave* oppgave) {
    int antallArbeidereLedig
    for (int i=0; i<MAXOPPG; i++) {
        for (int j=0; j<MAXPERS; i++) {
            if(oppgave[i]->hvem[j]=0) antallArbeidereLedig++
        }
        if (antallarbeidere) {
            return true;
        }
        else {
            return false;
        }
    }
}

void oppgaveLesData(struct Oppgave* oppgave) {
    oppgave->navn = lagOgLesText("Navn: ");
    oppgave->antallTotalt = lesInt("Antall personer som trengs til oppgaven: ", 0, MAXPERS);
    oppgave->antallNaa = 0;
    
    for(int i=0; i<MAXPERS; i++)oppgave->hvem[i]=0;
}

void oppgaveSkrivData(const struct Oppgave* oppgave) {
    printf("Navn: %s, Antall totalt: %i , Antall nå: %i , Hvem: ", oppgave->navn, oppgave->antallTotalt, oppgave->antallNaa);
    for (int i=0; oppgave->hvem[i]!='\0'; i++) printf("%i, ", oppgave->hvem[i]);
    printf("\n\n");
}

void oppgaveSlettData(struct Oppgave* oppgave) {

}

void oppgaveTilknyttPersoner(struct Oppgave* oppgave) {

}

void personerTilknyttesOppgave() {

}

void skrivMeny() {
    printf("Kommandomeny:\n");
    printf("N for ny oppgave\n");
    printf("S for å skrive oppgave\n");
    printf("L for å vise ledige oppgaver\n");
    printf("T for å tilknytte person til oppgave\n");
    printf("F for å fjerne oppgave\n");
    printf("Q for å stoppe programmet\n");
}

void skrivOppgaver() {
    for (int i=0; i<gSisteOppgave; i++) oppgaveSkrivData(gOppgavene[i]);
}
