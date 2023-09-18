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
void Inicijalizacija(int niz1[], int niz2[], int niz3[]) {
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
			niz3[i] = niz1[i];
		else
			niz3[i] = niz2[i - 3];
	}
}
int sumiraj(int niz[], int vel) {
	int suma = 0;
	for (int i = 0; i < vel; i++)
	{
		suma += niz[i];
	}
	return suma;
}
void main() {
	const int vel1 = 3, vel2 = 4, vel3 = 7;
	int niz1[vel1];
	int niz2[vel2];
	int niz3[vel3];
	Unos(niz1, vel1);
	Unos(niz2, vel2);
	Inicijalizacija(niz1, niz2, niz3);
	Ispis(niz1, vel1);
	Ispis(niz2, vel2);
	Ispis(niz3, vel3);
	int IzborNiza;
	cout << "Cije elemente zelite sumirati? 1, 2 ili 3?" << endl;
	cin >> IzborNiza;
	if (IzborNiza == 1)
		cout << "Suma elemenata je: " << sumiraj(niz1, vel1) << endl;
	if (IzborNiza == 2)
		cout << "Suma elemenata je: " << sumiraj(niz2, vel2) << endl;
	if (IzborNiza == 3)
		cout << "Suma elemenata je: " << sumiraj(niz3, vel3) << endl;
}