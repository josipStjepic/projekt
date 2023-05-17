#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Funkcija za unos novog igraèa
void unosIgraca(Igrac klub[], int* brojIgraca) {
    if (*brojIgraca >= MAX_IGRACA) {
        printf("Klub je veæ popunjen!\n");
        return;
    }

    Igrac noviIgrac;

    printf("Unesite ime igraca: ");
    scanf("%s", noviIgrac.ime);

    printf("Unesite prezime igraca: ");
    scanf("%s", noviIgrac.prezime);

    printf("Unesite broj golova: ");
    scanf("%d", &noviIgrac.brojGolova);

    klub[*brojIgraca] = noviIgrac;
    (*brojIgraca)++;

    printf("Igrac je uspjesno dodan.\n");
    spremanjeIgracaUDatoteku(klub, *brojIgraca);
}

// Funkcija za unos rezultata utakmice
void unosUtakmice(Utakmica utakmice[], int* brojUtakmica) {
    if (*brojUtakmica >= MAX_UTAKMICA) {
        printf("Dostignut maksimalan broj utakmica!\n");
        return;
    }

    Utakmica novaUtakmica;

    printf("Unesite ime protivnika: ");
    scanf("%s", novaUtakmica.protivnik);

    printf("Unesite rezultat utakmice: ");
    scanf("%d", &novaUtakmica.rezultat);



    utakmice[*brojUtakmica] = novaUtakmica;
    (*brojUtakmica)++;

    printf("Utakmica je uspjesno dodana.\n");
    spremanjeUtakmicaUDatoteku(utakmice, *brojUtakmica);
}

// Funkcija za ispis svih igraèa
void ispisIgraca(Igrac klub[], int brojIgraca) {
    printf("----- Popis igraca -----\n");

    if (brojIgraca == 0) {
        printf("Klub nema igraca.\n");
        return;
    }

    for (int i = 0; i < brojIgraca; i++) {
        printf("Igrac %d:\n", i + 1);
        printf("Ime: %s\n", klub[i].ime);
        printf("Ime: %s\n", klub[i].prezime);
        printf("Broj golova: %d\n", klub[i].brojGolova);
        printf("-----------------------\n");
    }
}

// Funkcija za ispis svih utakmica
void ispisUtakmica(Utakmica utakmice[], int brojUtakmica) {
    printf("----- Popis utakmica -----\n");

    if (brojUtakmica == 0) {
        printf("Klub nema odigranih utakmica.\n");
        return;
    }

    for (int i = 0; i < brojUtakmica; i++) {
        printf("Utakmica %d:\n", i + 1);
        printf("Protivnik: %s\n", utakmice[i].protivnik);
        printf("Rezultat: %d\n", utakmice[i].rezultat);
        printf("-------------------------\n");
    }
}

// Funkcija za spremanje igraèa u datoteku "igraci.txt"
void spremanjeIgracaUDatoteku(Igrac klub[], int brojIgraca) {
    FILE* datoteka = fopen("igraci.txt", "a");

    if (datoteka == NULL) {
        printf("Nemoguce otvoriti datoteku za pisanje.\n");
        return;
    }

    fprintf(datoteka, "----- Popis igraca -----\n");

    for (int i = 0; i < brojIgraca; i++) {
        fprintf(datoteka, "Igrac %d:\n", i + 1);
        fprintf(datoteka, "Ime: %s\n", klub[i].ime);
        fprintf(datoteka, "Prezime: %s\n", klub[i].prezime);
        fprintf(datoteka, "Broj golova: %d\n", klub[i].brojGolova);
        fprintf(datoteka, "-----------------------\n");
    }

    fclose(datoteka);

    printf("Podaci o igraèima su uspješno spremljeni u datoteku.\n");
}

// Funkcija za spremanje rezultata utakmica u datoteku "rezultati.txt"
void spremanjeUtakmicaUDatoteku(Utakmica utakmice[], int brojUtakmica) {
    FILE* datoteka = fopen("rezultati.txt", "a");

    if (datoteka == NULL) {
        printf("Nemoguce otvoriti datoteku za pisanje.\n");
        return;
    }

    fprintf(datoteka, "----- Popis utakmica -----\n");

    for (int i = 0; i < brojUtakmica; i++) {
        fprintf(datoteka, "Utakmica %d:\n", i + 1);
        fprintf(datoteka, "Protivnik: %s\n", utakmice[i].protivnik);
        fprintf(datoteka, "Rezultat: %d\n", utakmice[i].rezultat);
        fprintf(datoteka, "-------------------------\n");
    }

    fclose(datoteka);

    printf("Podaci o rezultatima utakmica su uspjesno spremljeni u datoteku.\n");
}



