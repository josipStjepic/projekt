#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
#define MAX_BROJEVA 100000


void randomBroj(int* serijskiBroj) {
	static int zauzetiBrojevi[100000] = { 0 };
	int broj, generiran = 0;

	while (!generiran) {
		broj = rand() % 100000 + 1;

		if (!zauzetiBrojevi[broj - 1]) {
			zauzetiBrojevi[broj - 1] = 1;
			*serijskiBroj = broj;
			generiran++;
		}
	}
	for (int i = 0; i < generiran; i++) {
		if (zauzetiBrojevi[i] == serijskiBroj) { // 11. 12.
			return 0;  // Broj nije jedinstven
		}
	}
	return 1;  // Broj je jedinstven
}




void unosIgraca(Igrac** klub, int* brojIgraca) {
	(*brojIgraca)++;
	*klub = realloc(*klub, (*brojIgraca) * sizeof(Igrac));

	


	printf("Unesite ime igraca: ");
	scanf("%s", (*klub)[*brojIgraca - 1].ime); // 2.

	printf("Unesite prezime igraca: ");
	scanf("%s", (*klub)[*brojIgraca - 1].prezime);

	printf("Unesite broj golova igraca: ");
	scanf("%d", &(*klub)[*brojIgraca - 1].brojGolova);

	randomBroj(&(*klub)[*brojIgraca - 1].serijskiBroj);
	
}

void ispisIgraca(Igrac* klub, int brojIgraca) {
	if (brojIgraca == 0) {
		printf("Nema upisanih igraca.\n");
		return;
	}

	printf("Popis igraca:\n");

	for (int i = 0; i < brojIgraca; i++) {
		printf("Igrac %d:\n", i + 1);
		printf("Ime: %s\n", klub[i].ime);
		printf("Ime: %s\n", klub[i].prezime);
		printf("Broj golova: %d\n", klub[i].brojGolova);
		printf("Serijski broj: %d\n", klub[i].serijskiBroj);
		printf("\n");
	}
}

void unosUtakmice(Utakmica** utakmice, int* brojUtakmica) {
	(*brojUtakmica)++;
	*utakmice = realloc(*utakmice, (*brojUtakmica) * sizeof(Utakmica)); //13. 14.


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
	qsort(utakmice, brojUtakmica, sizeof(Utakmica), usporediUtakmice); //20. 7.

	printf("Popis utakmica:\n");

	for (int i = 0; i < brojUtakmica; i++) {
		printf("Utakmica %d:\n", i + 1);
		printf("Protivnik: %s\n", utakmice[i].protivnik);
		/*printf("Broj golova naseg kluba: %d\n", utakmice[i].goloviNasaEkipa);
		printf("Broj golova protivnicke ekipe: %d\n", utakmice[i].goloviProtivnik);*/

		printf("NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
		printf("\n");
	}
}

void spremanjeIgracaUDatoteku(Igrac* klub, int brojIgraca) {
	FILE* datoteka = fopen("igraci.txt", "w");

	if (datoteka == NULL) {
		perror("Greska pri otvaranju datoteke.\n"); // 19.
		printf("Errno: %d\n", errno);
		return 1;
	}
	rewind(datoteka);
	for (int i = 0; i < brojIgraca; i++) {
		fprintf(datoteka, "%s %s %d %d\n", klub[i].ime, klub[i].prezime, klub[i].brojGolova, klub[i].serijskiBroj);
	}

	fclose(datoteka);

	printf("Podaci o igracima su spremljeni u datoteku.\n");
}

void spremanjeUtakmicaUDatoteku(Utakmica* utakmice, int brojUtakmica) {
	FILE* datoteka = fopen("rezultati.txt", "w"); // 16. 

	if (datoteka == NULL) {
		perror("Greska pri otvaranju datoteke.\n"); // 11. 19.
		printf("Errno: %d\n", errno);
		return 1;
	}
	rewind(datoteka);//17.
	for (int i = 0; i < brojUtakmica; i++) {
		fprintf(datoteka, "NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
	}

	fclose(datoteka);

	printf("Podaci o utakmicama su spremljeni u datoteku.\n");
}





int usporediUtakmice(const void* a, const void* b) {
	const Utakmica* utakmica1 = (const Utakmica*)a; // 11. 
	const Utakmica* utakmica2 = (const Utakmica*)b;

	// Sortiraj utakmice prema broju golova naše ekipe (silazno)
	if (utakmica1->goloviNasaEkipa > utakmica2->goloviNasaEkipa) {
		return -1;
	}
	else if (utakmica1->goloviNasaEkipa < utakmica2->goloviNasaEkipa) {
		return 1;
	}

	// Ako je broj golova naše ekipe jednak, sortiraj prema broju golova protivničke ekipe (silazno)
	if (utakmica1->goloviProtivnik > utakmica2->goloviProtivnik) {
		return -1;
	}
	else if (utakmica1->goloviProtivnik < utakmica2->goloviProtivnik) {
		return 1;
	}

	return 0;  // Utakmice su jednake
}

void sortirajUtakmice(Utakmica* utakmice, int brojUtakmica) {
	qsort(utakmice, brojUtakmica, sizeof(Utakmica), usporediUtakmice);// 20.
}

void pretraziRezultate(Utakmica* utakmice, int brojUtakmica) {
	char protivnik[30];
	printf("Unesite ime protivnika: ");
	scanf("%s", protivnik);

	int pronaden = 0;

	for (int i = 0; i < brojUtakmica; i++) {
		if (strcmp(utakmice[i].protivnik, protivnik) == 0) { // 21.
			printf("Utakmica %d:\n", i + 1);
			printf("Protivnik: %s\n", utakmice[i].protivnik);
			/*printf("Broj golova naseg kluba: %d\n", utakmice[i].goloviNasaEkipa);
			printf("Broj golova protivnicke ekipe: %d\n", utakmice[i].goloviProtivnik);*/
			printf("NasKlub  %d - %d  %s\n", utakmice[i].goloviNasaEkipa, utakmice[i].goloviProtivnik, utakmice[i].protivnik);
			printf("\n");

			pronaden = 1;
		}
	}

	if (!pronaden) {
		printf("Nema rezultata za trazenog protivnika.\n");
	}
}

void obrisiPodatke(const char* nazivDatoteke) {
	FILE* datoteka = fopen(nazivDatoteke, "w");
	if (datoteka == NULL) {
		printf("Greska pri otvaranju datoteke %s\n", nazivDatoteke);
		printf("Errno: %d\n", errno);
		return;
	}

	// Obriši sadržaj datoteke
	fclose(datoteka);
	//printf("Podaci iz datoteke %s su obrisani.\n", nazivDatoteke);
}

void obrisiDatoteke() {
	char rezultatiDatoteka[] = "rezultati.txt";
	char igraciDatoteka[] = "igraci.txt";

	if (remove(rezultatiDatoteka) == 0) {
		printf("Datoteka %s uspješno izbrisana.\n", rezultatiDatoteka);
	}
	else {
		printf("Greška prilikom brisanja datoteke %s. Greska: %s\n", rezultatiDatoteka, strerror(errno));
	}

	if (remove(igraciDatoteka) == 0) { //18.
		printf("Datoteka %s uspješno izbrisana.\n", igraciDatoteka);
	}
	else {
		printf("Greška prilikom brisanja datoteke %s. Greska: %s\n", igraciDatoteka, strerror(errno));
	}
}
//6.
