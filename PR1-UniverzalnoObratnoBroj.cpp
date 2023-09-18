#include <iostream>
using namespace std;
int BrojCifri(int broj)
{
	int brojac = 0;
	do {
		broj /= 10;
		brojac++;
	} while (broj > 0);
	return brojac;
}
int ObratnoBroj(int broj)
{
	int NoviBroj = 0;
	int Tezinska = BrojCifri(broj) - 1;
	do {
		int cifra = broj % 10;
		NoviBroj += cifra * pow(10, Tezinska);
		Tezinska--;
		broj /= 10;
	} while (broj > 0);
	return NoviBroj;
}


int main()
{

	cout << ObratnoBroj(123);
	return 0;
}
