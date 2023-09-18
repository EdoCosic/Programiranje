#include <iostream>
using namespace std;
void Unos(int* niz, int velicina, int i = 0, int faktorijel = 1) {
	if (i == velicina)
		return;
	if (faktorijel < 0)
		return;
	*(niz + i) = faktorijel;
	faktorijel *= (i + 1 + 1);
	Unos(niz, velicina, i + 1, faktorijel);
}
void Ispis(int* niz, int velicina, int i = 0) {
	if (i == velicina)
		return;
	cout << *(niz + i) << " ";
	Ispis(niz, velicina, i + 1);
}
int main()
{
	int velicina;
	cout << "Unesite velicinu niza" << endl;
	cin >> velicina;
	int* niz = new int[velicina];
	Unos(niz, velicina);
	Ispis(niz, velicina);
	delete[]niz;
	niz = nullptr;
	system("pause>0");
	return 0;
}
