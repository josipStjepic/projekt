#pragma once
#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#define MAX_IGRACA 20
#define MAX_UTAKMICA 10

typedef struct {
    char ime[20];
    char prezime[20];
    int brojGolova;
} Igrac;

typedef struct {
    char protivnik[50];
    int goloviNasaEkipa;
    int goloviProtivnik;
} Utakmica;

void unosIgraca(Igrac klub[], int* brojIgraca);
void unosUtakmice(Utakmica utakmice[], int* brojUtakmica);
void ispisIgraca(Igrac klub[], int brojIgraca);
void ispisUtakmica(Utakmica utakmice[], int brojUtakmica);
void spremanjeIgracaUDatoteku(Igrac klub[], int brojIgraca);
void spremanjeUtakmicaUDatoteku(Utakmica utakmice[], int brojUtakmica);
void pretratiRezultate(Utakmica utakmice[],int brojUtakmica);
#endif

