#include <iostream>
using namespace std;
void Unos(int* niz, int velicina, int i = 0) {
	if (i == velicina)
		return;
	if (i == 0)
		*(niz + i) = 2;//niz[i]=*(niz+i)
	else {
		if ((*(niz + i - 1) * 2) < 0)
			return;
		*(niz + i) = *(niz + i - 1) * 2;
	}
	Unos(niz, velicina, i + 1);
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
