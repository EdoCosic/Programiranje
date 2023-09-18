#include <iostream>
using namespace std;
int BrojCifri(int broj)
{
	int brojac = 0;
	do {
		int cifra = broj % 10;
		if (cifra % 2 != 0)
			brojac++;
		broj /= 10;
	} while (broj > 0);
	return brojac;
}
int KreirajBroj(int A)
{
	int B = 0;
	int Tezinska = BrojCifri(A) - 1;
	do {
		int cifra = A % 10;
		if (cifra % 2 != 0) {
			B += cifra * pow(10, Tezinska);
			Tezinska--;
		}
		A /= 10;
	} while (A > 0);
	return B;
}
int main()
{
	int A;
	do {
		cout << "Unesite A" << endl;
		cin >> A;
	} while (A <= 100000);
	cout << "B je: " << KreirajBroj(A) << endl;
	return 0;
}
