#pragma once
#ifndef HEADER_H
#define HEADER_H

typedef struct {
	char ime[30];
	int brojGolova;
} Igrac;

typedef struct {
	char protivnik[30];
	int goloviNasaEkipa;
	int goloviProtivnik;
} Utakmica;

void unosIgraca(Igrac** klub, int* brojIgraca);
void ispisIgraca(Igrac* klub, int brojIgraca);
void unosUtakmice(Utakmica** utakmice, int* brojUtakmica);
void ispisUtakmica(Utakmica* utakmice, int brojUtakmica);
void spremanjeIgracaUDatoteku(Igrac* klub, int brojIgraca);
void spremanjeUtakmicaUDatoteku(Utakmica* utakmice, int brojUtakmica);
void pretraziRezultate(Utakmica* utakmice, int brojUtakmica);

#endif  // HEADER_H
