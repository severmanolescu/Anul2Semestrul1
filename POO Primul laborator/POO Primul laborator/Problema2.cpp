#include <iostream>
#include <conio.h>

using namespace std;

typedef struct
{
	char marca[20];
	char model[10];
	float consum;
	float pret;
}masina;

int main()
{
	masina* ma;
	ma = new masina;

	cout << "Dati marca masinii: ";           cin >> ma->marca;
	cout << "Dati modelul masinii: ";         cin >> ma->model;
	cout << "Dati consumul de combustibil: "; cin >> ma->consum;
	cout << "Dati pretul masinii: ";          cin >> ma->pret;

	cout << "Marca: "  << ma->marca << endl
	     << "Model: "  << ma->model << endl
		 << "Consum: " << ma->consum << endl
		 << "Pret: "   << ma->pret;
	delete ma;

	_getch();
	return 0;
}