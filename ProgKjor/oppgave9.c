int main () {

    int totaltSekunder, timer, minutter, sekunder;

    totaltSekunder=312304;
    timer=totaltSekunder/60/60;
    minutter=totaltSekunder/60%60;
    sekunder=totaltSekunder%60;

    printf("%i sekunder tilsvarer: %i timer, %i minutter og %i sekunder", totaltSekunder, timer, minutter, sekunder);

    return 0;
    }

