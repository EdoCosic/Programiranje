#include <iostream>
using namespace std;
int PrebrojiParne(int broj) {
	int brojCifri = 0;
	do
	{
		int cifra = broj % 10;
		if (cifra % 2 == 0)
			brojCifri++;
		broj /= 10;
	} while (broj > 0);
	return brojCifri;
}
void KreirajNovi(int& N) {
	int NoviBroj = 0;
	int Tezinska = PrebrojiParne(N) - 1;
	do {
		int cifra = N % 10;
		if (cifra % 2 == 0)
		{
			NoviBroj += cifra * pow(10, Tezinska);
			Tezinska--;
		}
		N /= 10;
	} while (N > 0);
	N = NoviBroj;
}
int main()
{
	int N;
	do {
		cout << "Unesite n" << endl;
		cin >> N;
	} while (N < 50 || N>5000000);
	KreirajNovi(N);
	cout << "Novi: " << N;
	system("pause>0");
	return 0;
}
