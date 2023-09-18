#include <iostream>
using namespace std;
int main()
{
	int brojacUzastopnih = 0;
	int brojacUkupnih = 0;
	do {
		int kocka1 = rand() % 6 + 1;
		int kocka2 = rand() % 6 + 1;
		int kocka3 = rand() % 6 + 1;
		brojacUkupnih++;
		if (kocka1 == kocka2 && kocka1 == kocka3)
			brojacUzastopnih++;
		else
			brojacUzastopnih = 0;
	} while (brojacUzastopnih < 2);
	cout << "Ukupno je bilo bacanja: " << brojacUkupnih << endl;
	return 0;
}