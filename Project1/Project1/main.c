#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	Igrac* klub = NULL;
	int brojIgraca = 0;

	Utakmica* utakmice = NULL;
	int brojUtakmica = 0;

	int izbor;
	do {
		printf("----- Izbornik -----\n");
		printf("1. Unos igraca\n");
		printf("2. Ispis igraca\n");
		printf("3. Unos utakmice\n");
		printf("4. Ispis utakmica\n");
		printf("5. Pretrazi rezultate utakmica\n");
		printf("6. Izlaz\n");
		printf("Odabir: ");
		scanf("%d", &izbor);

		switch (izbor) {
		case 1:
			unosIgraca(&klub, &brojIgraca);
			spremanjeIgracaUDatoteku(klub, brojIgraca);
			break;
		case 2:
			ispisIgraca(klub, brojIgraca);
			break;
		case 3:
			unosUtakmice(&utakmice, &brojUtakmica);
			spremanjeUtakmicaUDatoteku(utakmice, brojUtakmica);
			break;
		case 4:
			ispisUtakmica(utakmice, brojUtakmica);
			break;
		case 5:
			pretraziRezultate(utakmice, brojUtakmica);
			break;
		case 6:
			printf("Izlazi iz programa.\n");
			break;
		
		default:
			printf("Krivi odabir. Molim pokusajte ponovno.\n");
		}

		printf("\n");
	} while (izbor != 8);

	free(klub);
	free(utakmice);

	return 0;
}




