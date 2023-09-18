#include <iostream>
using namespace std;
int faktorijel(int broj) {
	int f = 1;
	for (int i = 1; i <= broj; i++)
	{
		f *= i;
	}
	return f;
}
int Suma(int N) {
	int S = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 != 0 && i % 7 != 0)
			S += faktorijel(i);
	}
	return S;
}
int main()
{
	int N;
	cin >> N;
	cout << "Suma je: " << Suma(N) << endl;

	system("pause>0");
	return 0;
}
