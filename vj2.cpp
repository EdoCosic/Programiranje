#include <iostream>
using namespace std;

/*
Zadatal 2: Napisati program u kojem cete upotrijebiti rekurzivnn funkciju
ciji je zadatak racunanje sume kvadrata od n do m
(n i m su prirodni brojevi i n<m)
*/

int sumaKvadrata(int, int);
int main()
{
	int n, m;
	do
	{
		cout << "Unesite dva prirodna broja" << endl;
		cin >> n >> m;
	} while (n < 1 || m < 1 || n>m);

	cout << sumaKvadrata(n, m) << endl;

	system("pause>0");
	return 0;
}

//silazna rekurzija
int sumaKvadrata(int N, int M)
{
	if (N == M)
		return N * N; //M*M, N*M, mozemo napisati bilo sta od ovog
	return M * M + sumaKvadrata(N, M - 1);
}


//uzlazna rekurzija
//int sumaKvadrata(int N, int M)
//{
//	if (N == M)
//		return N * N;
//	return N * N + sumaKvadrata(N  + 1, M);
//}
