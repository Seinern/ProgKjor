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
#include "LesData.h"            //  Verktøykasse for lesing av diverse data.

#define MAXPERS 6
#define MAXOPPG 20

struct Oppgave {
    char* navn;
    int antallTotalt,
    antallNaa;
    int hvem[MAXPERS];
};

void fjernOppgave();
void nyOppgave();
void ledigeOppgaver();
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void oppgaveLesData(struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
void oppgaveSlettData(struct Oppgave* oppgave);
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void personerTilknyttesOppgave();
void skrivMeny();
void skrivOppgaver();


struct Oppgave* gOppgavene[MAXOPPG];
int gSisteOppgave = 0;

/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;
    
    skrivMeny();
    kommando = lesKommando();
    
    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'O':  oversikt();  break;    //  Oversikt over varelager.
            case 'N':  nyVare();    break;    //  Registrer ny vare.
            case 'M':  endreAntallet(Motta);  break;  //  Motta 'x' stk. av vare.
            case 'S':  endreAntallet(Selge);  break;  //  Selg 'x' stk. av vare.
            case 'F':  fjernVare(); break;    //  Fjern en vare fra lager.
            default:   skrivMeny(); break;    //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }
    
    printf("\n\n");
    return 0;
}

void fjernOppgave();
void nyOppgave() {
    if (gSisteOppgave>MAXOPPG) {
        printf("Fuck you");
    }
    else {
        persPeker = (struct Oppgave*) malloc(sizeof(struct Oppgave));
        
        personLesData(persPeker);            //  Leser personen sine data.
        
        persPeker->neste = personListe;      //  HEKTER INN FORREST !!!!! :
        
        personListe = persPeker;
    }
    
}
void ledigeOppgaver();
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void oppgaveLesData(struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
void oppgaveSlettData(struct Oppgave* oppgave);
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void personerTilknyttesOppgave();


void skrivMeny() {
    printf("Kommandomeny:\n");
    printf("F for å fylle array\n");
    printf("A skriver ut antall tall i arrayen mellom 0 og 2000\n");
    printf("L for å lese teksten (Postnummer og poststed)\n");
    printf("S for å sjekke om postnummer og poststed er gyldig\n");
    printf("Q for å stoppe programlmet\n");
}

void skrivOppgaver();
