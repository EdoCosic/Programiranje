#include <iostream>
using namespace std;
int KreirajBroj(int brojCifri) {
	brojCifri--;
	int broj = 0;
	do {
		int cifra;
		do {
			cout << "Unesite cifru" << endl;
			cin >> cifra;
			if (cifra < 0)
			{
				broj /= pow(10, brojCifri + 1);
				return broj;
			}
			if (cifra > 9)
				cout << "MORATE UNIJETI PONOVO CIFRU" << endl;
		} while (cifra > 9);
		broj += cifra * pow(10, brojCifri);
		brojCifri--;
	} while (brojCifri >= 0);
	return broj;
}
int main()
{
	int brojCifri;
	cout << "Od koliko cifri zelite broj kreirati?" << endl;
	cin >> brojCifri;
	cout << "Novi broj " << KreirajBroj(brojCifri) << endl;
	return 0;
}
