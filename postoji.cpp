#include <iostream>
using namespace std;
void Unos(int* niz, int velicina, int i = 0) {
	if (i == velicina)
		return;
	if (i == 0 || i == 1)
		*(niz + i) = 1;
	else {
		if (((*(niz + i - 1)) + (*(niz + i - 2))) < 0)
			return;
		*(niz + i) = (*(niz + i - 1)) + (*(niz + i - 2));
	}
	Unos(niz, velicina, i + 1);
}
void Ispis(int* niz, int velicina, int i = 0) {
	if (i == velicina)
		return;
	cout << *(niz + i) << " ";
	Ispis(niz, velicina, i + 1);
}
bool PostojiBroj(int* niz, int velicina, int broj, int  i = 0) {
	if (i == velicina)
		return false;
	if (broj == *(niz + i))
		return true;
	PostojiBroj(niz, velicina, broj, i + 1);
}
int main()
{
	int velicina;
	cout << "Unesite velicinu niza" << endl;
	cin >> velicina;
	int* niz = new int[velicina];
	Unos(niz, velicina);
	Ispis(niz, velicina);
	int broj;
	cout << "koji broj trazite" << endl;
	cin >> broj;
	if (PostojiBroj(niz, velicina, broj) == true)
		cout << "Broj ima";
	else
		cout << "Broj nema";

	delete[]niz;
	niz = nullptr;


	system("pause>0");
	return 0;
}
