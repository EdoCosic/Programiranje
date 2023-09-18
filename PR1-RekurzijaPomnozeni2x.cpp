#include <iostream>
using namespace std;
/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog
dinamičkog niza integer vrijednosti. Napisati rekurzivnu funkciju koja će taj niz
popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., tako da je svaki
sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. Rekurzija se prekida
kada se popuni cijeli niz ili kada se desi overflow na integer varijabli. U ovom zadatku
je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.*/

void Rekuzija(int* niz, int brojNiza, int i = 0, int e = 1)
{
	if (i < 0 || i >= brojNiza)
		return;
	int temp = pow(2, e);
	*(niz + i) = temp;
	Rekuzija(niz, brojNiza, i + 1, e + 1);
}

int main()
{
	int brojNiza;
	cout << "Unesite broj niza " << endl;
	cin >> brojNiza;

	int* niz = new int[brojNiza] {};
	Rekuzija(niz, brojNiza);
	for (size_t i = 0; i < brojNiza; i++)
	{
		cout << "\n" << niz[i];
	}

	return 0;
}
