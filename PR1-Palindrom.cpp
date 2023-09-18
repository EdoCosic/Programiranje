
#include <iostream>
using namespace std;
bool Prost(int broj)
{
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
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
bool Palindrom(int broj) {
	if (broj == ObratnoBroj(broj))
		return true;
	return false;
}
int main()
{
	int broj;
	do {
		cout << "Unesite broj veci od 100";
		cin >> broj;
	} while (broj <= 100);
	if (Prost(broj) == true && Palindrom(broj) == true)
		cout << "Broj je prost i palindrom";
	else
		cout << "Broj ne zadovoljava kriterij";

	return 0;
}
