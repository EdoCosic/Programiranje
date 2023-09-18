#include <iostream>
using namespace std;


int Sifriraj(int n) {
	int NoviBroj = 0;
	int Tezinska = 0;
	do {
		int cifra = n % 10;
		if (cifra % 2 == 0)
			cifra = 5;
		NoviBroj += cifra * pow(10, Tezinska);
		Tezinska++;
		n /= 10;
	} while (n > 0);
	return NoviBroj;
}
int main()
{
	int n;
	do {
		cout << "Unesite n" << endl;
		cin >> n;
	} while (n < 0);
	cout << "Novi broj je: " << Sifriraj(n) << endl;
	cout << "Razlika je: " << n - Sifriraj(n) << endl;

	system("pause>0");
	return 0;
}
