#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    Igrac klub[MAX_IGRACA];
    Utakmica utakmice[MAX_UTAKMICA];
    int brojIgraca = 0;
    int brojUtakmica = 0;
    int izbor;

    do {
        printf("------- IZBORNIK -------\n");
        printf("1. Unos igraca\n");
        printf("2. Unos rezultata utakmice\n");
        printf("3. Ispis igraca\n");
        printf("4. Ispis utakmica\n");
        printf("0. Izlaz iz programa\n");
        printf("-------------------------\n");
        printf("Unesite svoj izbor: ");
        scanf("%d", &izbor);

        switch (izbor) {
        case 1:
            unosIgraca(klub, &brojIgraca);
            break;
        case 2:
            unosUtakmice(utakmice, &brojUtakmica);
            break;
        case 3:
            ispisIgraca(klub, brojIgraca);
            break;
        case 4:
            ispisUtakmica(utakmice, brojUtakmica);
            break;
       
           
        case 0:
            printf("Izlazi iz programa!\n");
            break;
        default:
            printf("Nepoznat izbor. Molim pokusajte ponovno.\n");
            break;
        }

        printf("\n");
    } while (izbor != 0);

    return 0;
}




