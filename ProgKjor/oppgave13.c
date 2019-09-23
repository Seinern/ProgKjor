//
//  oppgave13.c
//  ProgKjor
//
//  Created by William Seiner on 16/09/2019.
//  Copyright © 2019 William Seiner. All rights reserved.
//

#include <stdio.h>

const int HOYDE = 4;
const float PI = 3.14;

int main() {
    
    int hoyesteRadie;
    
    printf("Skriv inn et tall mellom 5 og 20: ");
    scanf("%i", &hoyesteRadie);
    for (int i = 1;  i <= hoyesteRadie;  i++)
        printf("Sylinder med radie %2i og høyde %i har volumet: %12f \n", i, HOYDE, HOYDE * i * i * PI);
    
    
    return 0;
}
