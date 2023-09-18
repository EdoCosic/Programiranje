#include<iostream>
using namespace std;
const int vel = 5;
void Inicijaliziraj(int matrica[][vel]) {
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if (i == j)
				matrica[i][j] = 0;
			else
				matrica[i][j] = 1;
		}
	}
}
void Ispis(int matrica[][vel]) {
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << matrica[i][j] << " ";
		}
		cout << endl;
	}
}
int Suma(int matrica[][vel])
{
	int s = 0;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if ((i + j) == (vel - 1))
				s += matrica[i][j];
		}
	}
	return s;
}
void Inicijaliziraj2(int matrica[][vel]) {
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if (i == j)
				matrica[i][j] = 1;
			else
				matrica[i][j] = 0;
		}
	}
}
void main() {
	int matrica[vel][vel];
	Inicijaliziraj(matrica);
	Ispis(matrica);
	cout << "Suma elemenata na sporednoj dijagonali: " << Suma(matrica) << endl;
	Inicijaliziraj2(matrica);
	cout << "Matrica nakon promjene" << endl;
	Ispis(matrica);
}

