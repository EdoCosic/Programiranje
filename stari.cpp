#include <iostream>
using namespace std;
float Cosinus(int n, float x) {
	float S = 0;
	for (int i = 1; i <= n; i++)
	{
		S += cos(pow(x, i));
	}
	return S;
}


int main()
{
	int n;
	float x;
	do {
		cout << "Unesite prirodni broj" << endl;
		cin >> n;
	} while (n < 1);
	cout << "Unesite realni broj" << endl;
	cin >> x;
	cout << "Cosinus: " << Cosinus(n, x) << endl;

	system("pause>0");
	return 0;
}