int main () {

    int tall1, tall2, tall3, sum, kvadratSum;
    float flyt1, flyt2, gjsnittSum, gjsnittKvadrat;

    tall1=6;
    tall2=8;
    tall3=10;
    flyt1=6.5;
    flyt2=10.5;

    sum=tall1+tall2+tall3;
    gjsnittSum=sum/3.0;
    kvadratSum=(tall1*tall1)+(tall2*tall2)+(tall3*tall3);
    gjsnittKvadrat=kvadratSum/3.0;

    printf("Summen av heltallenee: %i+%i+%i=%i \n",tall1,tall2,tall3,sum);

    printf("Gjennomsnitt av heltallene: %.3f \n", gjsnittSum);

    printf("Kvadratsummen blir: %i \n", kvadratSum);

    printf("Gjennomsnittet av kvadratsummen: %f \n", gjsnittKvadrat);

    printf("Gjennomsnittet av %.3f og %.3f er %.3f", flyt1, flyt2, ((flyt1+flyt2)/2.0) );

    return 0;
    }
