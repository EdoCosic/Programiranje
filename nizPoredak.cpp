#include<iostream>
using namespace std;

void Unos(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cin >> niz[i];
	}
}

void Ispis(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

int manji(int broj1, int broj2)
{
	if (broj1 < broj2)
		return broj1;
	return broj2;
}

void Inicijalizacija(int niz1[], int niz2[], int niz3[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		niz3[i] = manji(niz1[i], niz2[i]);
	}
}

bool Opadajući(int niz[], int vel) {
	for (int i = 0; i < vel - 1; i++)
	{
		if (niz[i] <= niz[i + 1])
			return false;
	}
	return true;
}

void main() {
	const int vel = 5;
	int niz1[vel];
	int niz2[vel];
	int niz3[vel];
	Unos(niz1, vel);
	Unos(niz2, vel);
	Inicijalizacija(niz1, niz2, niz3, vel);
	Ispis(niz1, vel);
	Ispis(niz2, vel);
	Ispis(niz3, vel);
	int IzborNiza;
	cout << "Za koji niz provjeravate poredak(1, 2 ili 3)" << endl;
	cin >> IzborNiza;
	if (IzborNiza == 1)
	{
		if (Opadajući(niz1, vel) == true)
			cout << "Niz je u opadajucem poretku" << endl;
		else
			cout << "Niz nije u opadajucem poretku" << endl;
	}
	if (IzborNiza == 2)
	{
		if (Opadajući(niz2, vel) == true)
			cout << "Niz je u opadajucem poretku" << endl;
		else
			cout << "Niz nije u opadajucem poretku" << endl;
	}
	if (IzborNiza == 3)
	{
		if (Opadajući(niz3, vel) == true)
			cout << "Niz je u opadajucem poretku" << endl;
		else
			cout << "Niz nije u opadajucem poretku" << endl;
	}
}
