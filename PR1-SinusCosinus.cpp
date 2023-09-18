#include <iostream>
using namespace std;
float Sinus(float x) {

	float  S = 1;
	for (int i = 1; i <= x; i++)
	{
		S += (i / (sin(x / i) + x));
	}
	return S;
}
float Cosinus(float x) {

	float  S = 1;
	for (int i = 1; i <= x; i++)
	{
		S += (i / (cos(x / i) + x));
	}
	return S;
}
int main()
{
	float x;
	char odabir;
	cout << "Unesite realan broj";
	cin >> x;

	do {
		cout << "Odaberi funkciju" << endl;
		cin >> odabir;
		if (odabir != 's' && odabir != 'c')
			cout << "Morate ponovo unijeti" << endl;
	} while (odabir != 's' && odabir != 'c');

	switch (odabir)
	{
	case 's':
		cout << "Sinus: " << Sinus(x) << endl;
		break;
	case 'c':
		cout << "Cosinus: " << Cosinus(x) << endl;
		break;
	default:
		break;
	}
	return 0;
}
