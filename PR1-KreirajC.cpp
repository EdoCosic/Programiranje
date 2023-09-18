#include <iostream>
using namespace std;
bool Postoji(int B, int cifra) {
	do {
		int c = B % 10;
		if (c == cifra)
			return true;
		B /= 10;
	} while (B > 0);
	return false;
}
int KolikoCifri(int A, int B) {
	int brojac = 0;
	do {
		int c = A % 10;
		if (Postoji(B, c) == false)
			brojac++;
		A /= 10;
	} while (A > 0);
	return brojac;
}
int KreirajC(int A, int B) {
	int Tezinska = KolikoCifri(A, B) - 1;
	int C = 0;
	do {
		int cifra = A % 10;
		if (Postoji(B, cifra) == false)
		{
			C += cifra * pow(10, Tezinska);
			Tezinska--;
		}
		A /= 10;
	} while (A > 0);
	return C;

}
int main()
{
	int A, B;
	do {
		cout << "Unesite A" << endl;
		cin >> A;
	} while (A <= 100000);

	do {
		cout << "Unesite B" << endl;
		cin >> B;
	} while (B <= 50000);
	cout << "C je: " << KreirajC(A, B);
	system("pause>0");
	return 0;
}
