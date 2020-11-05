#include <iostream>
#include <conio.h>

using namespace std;

int suma(int a, int b)
{
	return a + b;
}

float suma(float a, float b)
{
	return a + b;
}

int main()
{
	int a, b;
	float x, y;

	cout << "Valoare primului numar intreg este: "; cin >> a;
	cout << "Valoare celui de-al doilea numar intreg este: "; cin >> b;
	cout << "Suma celor doua numere intregi este: " << suma(a, b) << endl;
	

	cout << "Valoare primului numar intreg este: "; cin >> x;
	cout << "Valoare celui de-al doilea numar intreg este: "; cin >> y;
	cout << "Suma celor doua numere reale este: " << suma(x, y);

	_getch();
	return 0;
}