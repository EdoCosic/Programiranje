#include <iostream>
using namespace std;
float Suma(int n) {
	float S = 0;
	for (int i = 3; i <= n; i += 2)
	{
		S += (1.0 / pow(i, 2));
	}
	return S;
}
int main()
{
	int n;
	do {
		cout << "Unesite n";
		cin >> n;
	} while (n < 1);
	cout << "Suma je: " << Suma(n);
	system("pause>0");
	return 0;
}
