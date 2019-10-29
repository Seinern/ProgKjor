/**
*  Oblig 3 i grunnleggende programmering.
*
*  Programmet utfører forskjellige kommandoer fra brukeren.
*
*  @file    oblig2.c
*  @author  William Seiner
*/

#include <stdio.h>          // scanf, printf
#include <stdbool.h>        // bool
#include <ctype.h>          // toupper, isdigit, isalpha

const int STRLEN = 80;    ///< Max.tekstlengde.
const int ANTINT = 20;    ///< Lengden på int-array.

int antallIArray(int tall[], const int n, const int min, const int max);  // Funksjon som teller tall som er mellom min og max
void fyllArray(int tall[], const int n);                                // Fyller array med tall lest av lesTall()
char lesKommando(void);                                                // Leser kommando fra bruker
int lesTall(const char tekst[], const int min, const int max);            // Leser tall mellom min og max fra bruker
void lesTekst(const char ledetekst[], char tekst[]);                    // Leser tekst fra brukeren
bool sjekkTekst(const char tekst[]);                                   // Sjekker om tekst er gyldig post -nr og sted
void skrivMeny(void);                                                 // Skriver ut en meny om kommandoer som kan brukes

/**
 * Hovedprogrammet:
 */

int main()  {
    char kommando;               // Lager variabel for kommando
    int  tallene[ANTINT];         // Lager array for tallene
    char teksten[STRLEN];         // Lager array for postnr og poststed
    
    skrivMeny();                  // Skriver ut kommandomeny
    kommando = lesKommando();     // Leser inn kommando fra lesKommando() funksjonen
    
    while (kommando != 'Q') {     //Programmet stoppe når kommando er Q
        switch (kommando) {
            // F for å fylle array tallene med 20 tall ved hjelp av fyllAray:
            case 'F': fyllArray(tallene, ANTINT);
                break;
            // A for å skrive ut hvor mange av tallene som er mellom 0 og 2000 ved hjelp av antallIArray:
            case 'A':
                printf("\n\tAntall i arrayen i intervallet 0-2000: %i\n",
                antallIArray(tallene, ANTINT, 0, 2000));
                break;
            // L for å lese inn Postnummer og poststed ved hjelp av lesTekst():
            case 'L': lesTekst("Postnummer og -sted", teksten);
                break;
            // S fo å sjekke om postnummer og poststed er gyldig ved hjelp av sjekkTekst():
            case 'S':
                printf("\n\tTeksten er%s et gyldig postnr og -sted.\n",
                ((!sjekkTekst(teksten)) ? " IKKE" : ""));
                break;
            // Alle andre tegn vil skrive ut kommandomenyen:
            default: skrivMeny();
                break;
        }
        kommando = lesKommando();    // Leser inn ny kommando
    }
    return 0;   // Avslutter hovedprogrammet
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
    
    // Sjekker om tegnene etter tallene og et mellomrom er tegn som ikke er tall:
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
    printf("Q for å stoppe programmet\n");
}
