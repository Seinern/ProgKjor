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

#define MAXPERS 6;
#define MAXOPPG 20;

struct Oppgave {
    char* navn;
    int antallTotalt,
    antallNaa;
    hvem[MAXPERS];
};

void nyOppgave();
void oppgaveLesData(struct Oppgave* oppgave);
void skrivOppgaver();
void oppgaveSkrivData(const struct Oppgave* oppgave);
void ledigeOppgaver();
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void personerTilknyttesOppgave();
void oppgaveTilknyttPersoner(struct Oppgave* oppgave)
void fjernOppgave();
void oppgaveSlettData(struct Oppgave* oppgave);


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
        if ((tall[i] >= min) && (tall[i] <= max)) antall++; // Hvis tallet er mellom min og max så øker antall med 1
    }
    return antall;     // Returnerer antall tall som er mellom min og max
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
    for(int i=0; i<n; i++) tall[i]=lesTall("Skriv inn heltall ", 0, 10000);  // Bruker lesTall og legger inn i array
}

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
char lesKommando()  {
    char tegn;
    printf("\nSkriv kommando:  ");
    scanf(" %c", &tegn);   getchar();   // Leser inn kommando fra brukeren
    return (toupper(tegn));            // Returnerer kommando gjort om til stor bokstav
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
    // Leser inn tall mellom min og max:
    do  {
        printf("\t%s (%i-%i):  ", tekst, min, max);
        scanf("%i", &tall);     getchar();
    } while (tall < min  ||  tall > max);
    return tall;    // Returnerer gyldig innlest tall
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])  {
    // Nullstiller arrayen tekst[]:
    for (int i=0; i<STRLEN; i++) {
        tekst[i]='\0';
    }
    printf("\t%s:  ", ledetekst);
    fgets(tekst, STRLEN, stdin);             //  Leser inn tekst fra brukeren
}

/**
 *  Sjekker om innlest postnr og poststed er gyldig.
 *
 *  @param      tekst  - Tekst som brukeren har skrevet inn.
 *
 *  @return     Om innlest tekst er gyldig postnr og poststed eller ikke
 */
bool sjekkTekst(const char tekst[]) {
    
    int antallTall=0, antallBokstaver=0, i;
    
    //Sjekker om de fire første tallene i arrayen er tall:
    for (i=0; i<4; i++) {
        if (isdigit(tekst[i])) {
            antallTall++;
        }
    }
    
    // Sjekker om tegnene etter tallene og et mellomrom er bokstaver, mellomrom, bindestrek og punktum:
    for (i=antallTall+1; i<tekst['\0']; i++) {
        if (isalpha(tekst[i]) || tekst[i]=='.' || tekst[i]=='-' || tekst[i]==' ') {
            antallBokstaver++;
        }
    }
    
    // Returnerer true hvis antall tall er 3 eller 4 tall, og antall bokstaver er mer enn 0, og at det er et mellomrom etter tallene:
    if (((antallTall==3) || (antallTall==4)) && (antallBokstaver>0) && (tekst[antallTall]==' ')) {
        return true;
    }
    // Returnerer false hvis ikke betingelsene er oppfylt:
    else {
        return false;
    }
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
    printf("Q for å stoppe programlmet\n");
}
