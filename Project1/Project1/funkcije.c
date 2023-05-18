#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void unosIgraca(Igrac** klub, int* brojIgraca) {
	(*brojIgraca)++;
	*klub = realloc(*klub, (*brojIgraca) * sizeof(Igrac));

	printf("Unesite ime igraca: ");
	scanf("%s", (*klub)[*brojIgraca - 1].ime);

	printf("Unesite broj golova igraca: ");
	scanf("%d", &(*klub)[*brojIgraca - 1].brojGolova);
}

void ispisIgraca(Igrac* klub, int brojIgraca) {
	if (brojIgraca == 0) {
		printf("Nema upisanih igraca.\n");
		return;
	}

	printf("----- Popis igraca -----\n");

	for (int i = 0; i < brojIgraca; i++) {
		printf("Igrac %d:\n", i + 1);
		printf("Ime: %s\n", klub[i].ime);
		printf("Broj golova: %d\n", klub[i].brojGolova);
		printf("-----------------------\n");
	}
}

void unosUtakmice(Utakmica** utakmice, int* brojUtakmica) {
	(*brojUtakmica)++;
	*utakmice = realloc(*utakmice, (*brojUtakmica) * sizeof(Utakmica));

	printf("Unesite ime protivnika: ");
	scanf("%s", (*utakmice)[*brojUtakmica - 1].protivnik);

	printf("Unesite broj golova naseg kluba: ");
	scanf("%d", &(*utakmice)[*brojUtakmica - 1].goloviNasaEkipa);

	printf("Unesite broj golova protivnicke ekipe: ");
	scanf("%d", &(*utakmice)[*brojUtakmica - 1].goloviProtivnik);
}

void ispisUtakmica(Utakmica* utakmice, int brojUtakmica) {
	if (brojUtakmica == 0) {
		printf("Nema upisanih utakmica.\n");
		return;
	}

	printf("----- Popis utakmica -----\n");

	for (int i = 0; i < brojUtakmica; i++) {
		printf("Utakmica %d:\n", i + 1);
		printf("Protivnik: %s\n", utakmice[i].protivnik);
		/*printf("Broj golova naseg kluba: %d\n", utakmice[i].goloviNasaEkipa);
		printf("Broj golova protivnicke ekipe: %d\n", utakmice[i].goloviProtivnik);*/

		printf("NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
		printf("-------------------------\n");
	}
}

void spremanjeIgracaUDatoteku(Igrac* klub, int brojIgraca) {
	FILE* datoteka = fopen("igraci.txt", "w");

	if (datoteka == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return;
	}

	for (int i = 0; i < brojIgraca; i++) {
		fprintf(datoteka, "%s %d\n", klub[i].ime, klub[i].brojGolova);
	}

	fclose(datoteka);

	printf("Podaci o igracima su spremljeni u datoteku.\n");
}

void spremanjeUtakmicaUDatoteku(Utakmica* utakmice, int brojUtakmica) {
	FILE* datoteka = fopen("utakmice.txt", "w");

	if (datoteka == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return;
	}

	for (int i = 0; i < brojUtakmica; i++) {
		fprintf(datoteka, "NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
	}

	fclose(datoteka);

	printf("Podaci o utakmicama su spremljeni u datoteku.\n");
}

void pretraziRezultate(Utakmica* utakmice, int brojUtakmica) {
	char protivnik[30];
	printf("Unesite ime protivnika: ");
	scanf("%s", protivnik);

	int pronaden = 0;

	for (int i = 0; i < brojUtakmica; i++) {
		if (utakmice[i].protivnik==protivnik) {
			printf("Utakmica %d:\n", i + 1);
			printf("Protivnik: %s\n", utakmice[i].protivnik);
			/*printf("Broj golova naseg kluba: %d\n", utakmice[i].goloviNasaEkipa);
			printf("Broj golova protivnicke ekipe: %d\n", utakmice[i].goloviProtivnik);*/
			printf("NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
			printf("-------------------------\n");

			pronaden = 1;
		}
	}

	if (!pronaden) {
		printf("Nema rezultata za trazenog protivnika.\n");
	}
}

