#include <iostream>
using namespace std;

/*
Prepravite program tako da:
U struckturu ucenik dodate obiljezja:
rodjendan koje je tipa datum struct datum{int dan, int mjesec, int godina};
Prosjecna koje je tiipa float
U strukturi datum dodati funkcije clanice - void unos(), void ispis(),
bool validacija_datuma(int, int, int);
U strukturi ucenik dodati funkcije clanice - void unos(), void ispis(), float prosjek();
kreirati glovalnu funkciju void pretragaPoDatumu(ucenik [], int; ciji je zadatak
pronaci i ispisati sve ucenike s istim datumom rodenja
*/

int G = 1;
struct datum
{
	int dan;
	int mjesec;
	int godina;
	void unosD(int, int, int);
	void ispisD()
	{
		cout << dan << "." << mjesec << "." << godina << "." << endl;
	}
	bool validacija_datuma(int, int, int);
};
void datum::unosD(int d, int m, int g)
{
	if (validacija_datuma(d, m, g))
	{
		dan = d;
		mjesec = m;
		godina = g;
	}
}

bool datum::validacija_datuma(int d, int m, int g)
{
	int min = 1, max = 31;
	if (g < 2000 || g > 2015)
		return false;
	if (m < 1 || m>12)
		return false;

	if ((m == 2) && (g % 4 == 0 || g % 400 == 0) && (g % 100 != 0))
		max = 29;
	else
		max = 28;

	if (max == 4 || m == 6 || m == 9 || m == 11)
		max = 30;

	if (d >= min && d <= max)
		return true;

	return false;
}


struct ucenik
{
	int RB;
	char ime[10];
	char prezime[15];
	datum rodjendan;
	int ocjene[5];
	float Prosjecna;
	void unosU();
	void ispisU();
	float prosjek();
};

void ucenik::unosU()
{
	int d, m, g;
	RB = G++;
	cout << "Unesite ime" << endl;
	cin.getline(ime, 10);
	cout << "Unesite prezime" << endl;
	cin.getline(prezime, 15);
	cout << "Unesite datum rodjenja" << endl;

	cin >> d >> m >> g;
	rodjendan.unosD(d, m, g);
	cout << "Unesite ocjene" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> ocjene[i];
		if (ocjene[i] < 1 || ocjene[i]>5)
			i--;
	}
	cin.ignore();
	Prosjecna = prosjek();
}

void ucenik::ispisU()
{
	cout << "RB: " << RB << endl;
	cout << "ime: " << ime << endl;
	cout << "prezime: " << prezime << endl;
	cout << "datum rodjenja: ";
	rodjendan.ispisD();
	cout << "ocjene: ";
	for (int i = 0; i < 5; i++)
		cout << ocjene[i] << " ";
	cout << endl << "prosjek: " << Prosjecna << endl << endl;
}

float ucenik::prosjek()
{
	int S = 0;
	for (int i = 0; i < 5; i++)
		S += ocjene[i];
	return S / 5.0;
}

int main()
{
	ucenik U1, U2;
	U1.unosU();
	U2.unosU();

	U1.ispisU();
	U2.ispisU();

	system("pause>0");
	return 0;
}
