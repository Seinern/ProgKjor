//
//  oppgave11.c
//  ProgKjor
//
//  Created by William Seiner on 06/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

int main () {
    
    int tall[5];
    int tall2[] = {6, 2, 10, 12, 19, 3, 7};
    
    char tekst[5];
    char navn[] = {'L','a','r','s',' ','H','a','n','s','e','n'};
    char adresse[] = {'R','i','n','g','g','a','t','a',' ','1','1','1'};
    
    
    tall[0]=13;
    tall[1]=67;
    tall[2]=tall[0]+tall[1];
    
    printf("Summen: %i \n", tall[2]);
    
    tall[2]/=2;
    printf("Halvering av forrige sum: %i \n", tall[2]);
    
    tall[3]=tall2[0]+tall2[1]+tall2[2]+tall2[3];
    tall[4]=tall2[4]+tall2[5]+tall2[6];
    
    printf("Summen av de fire første elementene i tall2: %i \nSummen av de tre siste elementene i tall2: %i \n", tall[3], tall[4]);
    
    tall[2]++;
    tall[2]++;
    tall[2]++;
    tall[2]++;
    
    printf("Tredje element i tall økt enkelt fire ganger: %i \n", tall[2]);
    
    tekst[1]='A';
    tekst[3]='E';
    tekst[0]=navn[5];
    tekst[2]=navn[0];
    
    printf("Kua har %c%c%c%c. \n", tekst[0], tekst[1], tekst[2], tekst[3]);
    
    printf("%c%c%c \n", adresse[9], adresse[10] ,adresse[11]);
    
    printf("Navn: %s \n", navn);
    
    printf("Adresse: %s \n", adresse);
    
    return 0;
}
