#include <iostream>
using namespace std;
bool Prost(int broj) {
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int brojacProstih = 0;
	int n;
	do {
		cout << "Unesite n" << endl;
		cin >> n;
	} while (n < 10 || n>1000);
	for (int i = 0; i < n; i++)
	{
		int broj = rand() % 1000 + 1;
		if (Prost(broj) == true)
			brojacProstih++;
	}
	cout << "Prosti brojevi: " << brojacProstih * 100.0 / n << "%" << endl;


	system("pause>0");
	return 0;
}
