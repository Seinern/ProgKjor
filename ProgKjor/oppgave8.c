const int ANTALL=17;
int main () {

    int tall1, tall2, tall3, svar;

    tall1=6;
    tall2=8;
    tall3=10;

    svar=tall1+tall2+tall3;
    printf("Summen av tallene: %i+%i+%i=%i \n",tall1,tall2,tall3,svar);

    svar=svar/3.0;
    printf("Gjennomsnitt av heltallene: %i \n", svar);

    svar=tall3-tall1;
    printf("Summen: %i \n", svar);

    svar=tall3*ANTALL;
    printf("Summen: %i \n", svar);

    svar=ANTALL/tall2;
    printf("Summen: %i \n", svar);

    svar*=ANTALL;
    printf("Summen: %i \n", svar);

    svar+=tall2;
    printf("Summen: %i \n", svar);

    svar/=7;
    printf("Summen: %i \n", svar);

    printf("Tall 1: %i - øker med 1 \n", tall1);

    tall1++;
    printf("Tall 1: %i - øker med 1 \n", tall1);

    tall1++;
    printf("Tall 1: %i - øker med 1 \n", tall1);

    tall1++;
    printf("Tall 1: %i - ferdig økt - trekkes fra ANTALL(17) \n", tall1);

    tall1-=ANTALL;
    printf("Tall 1: %i - ferdig økt og trekt fra \n", tall1);

    printf("Tall 2: %i - minskes med 1 \n", tall2);

    tall2--;
    printf("Tall 2: %i - minskes med 1 \n", tall2);

    tall2--;
    printf("Tall 2: %i - minskes med 1 \n", tall2);

    tall2--;
    printf("Tall 2: %i - minskes med 1 \n", tall2);

    tall2--;
    printf("Tall 2: %i - ferdig minsket og trekkes fra ANTALL(17) \n", tall2);

    tall2-=ANTALL;
    printf("Tall 2: %i - ferdig minsket og trukket fra \n", tall2);

    return 0;
    }
