#include <iostream>
using namespace std;

/*
Napisati program koji ce:
omoguciti unos niza 7 realnih brojeva pomocu funkcije:
void unos(float[], int); te uraditi sljedece:
izracunati sumu kubova svih elemenata sa neparnim indeksima uz pomoc funkcije:
float sumakubova(float[], int);
pronaci najmanji pozitivan broj u nizu uz pomoc funckije:
float najmanjipoz(float[], int);
pronaci najveci negativan broj u nizu uz pomoc funkcije:
float najvecineg(float[], int);

Ispis sume kubova, najmanji pozitivnog i najveci negativnog broja vrsiti u funkcije main
*/

void unos(float[], int);
float sumakubova(float[], int);
float najmanjipoz(float[], int);
float najvecineg(float[], int);

int main()
{
	const int vel = 7;
	float niz[vel];

	cout << "Unesite elemente niza" << endl;
	unos(niz, vel);

	cout << "Suma kubova elemenata sa neparnim indeksom iznosi " << sumakubova(niz, vel) << endl;

	cout << "Najmanji pozitivni element u nizu je " << najmanjipoz(niz, vel) << endl;
	return 0;
}

void unos(float niz[], int v)
{
	for (int i = 0; i < v; i++)
		cin >> niz[i];
}

float sumakubova(float niz[], int v)
{
	float suma = 0;
	for (int i = 1; i < v; i += 2)
		suma += pow(niz[i], 3.0);

	return suma;
}

float najmanjipoz(float niz[], int v)
{
	float pomocna = FLT_MAX;
	for (int i = 0; i < v; i++)
	{
		if (niz[i] > 0.0f && niz[i] < pomocna)
			pomocna = niz[i];
	}
	return pomocna;
}
