#pragma once
#ifndef HEADER_H
#define HEADER_H
#define MAX_IME 50
#define MAX_PREZIME 50
typedef struct {
	int serijskiBroj;
	char ime[MAX_IME];
	char prezime[MAX_PREZIME];
	int brojGolova;
} Igrac; //3. 10.

typedef struct {
	char protivnik[30];
	int goloviNasaEkipa;
	int goloviProtivnik;
} Utakmica;

void unosIgraca(Igrac** klub, int* brojIgraca); //4. 9. 10.
void ispisIgraca(Igrac* klub, int brojIgraca);
void unosUtakmice(Utakmica** utakmice, int* brojUtakmica);
void ispisUtakmica(Utakmica* utakmice, int brojUtakmica);
void spremanjeIgracaUDatoteku(Igrac* klub, int brojIgraca);
void spremanjeUtakmicaUDatoteku(Utakmica* utakmice, int brojUtakmica);
void pretraziRezultate(Utakmica* utakmice, int brojUtakmica);
int usporediUtakmice(const void* a, const void* b);
void sortirajUtakmice(Utakmica* utakmice, int brojUtakmica);
void obrisiPodatke(const char* nazivDatoteke);
void randomBroj(int* serijskiBroj);
void obrisiDatoteke();
#endif  // HEADER_H 
//6.#pragma once
