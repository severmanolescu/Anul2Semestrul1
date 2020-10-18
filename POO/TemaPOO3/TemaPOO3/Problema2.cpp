#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Mamifer
{
	string nume;
	unsigned short varsta;

public:
	Mamifer() {}

	Mamifer(string nume, unsigned short varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}

	void afisare()
	{
		cout << endl << endl;
		cout << "Nume: " << nume << endl;
		cout << "Varsta: " << varsta << endl;
	}
};

class Urs :public Mamifer
{
	string specie;
	float greutate;

public:
	Urs() {}

	Urs(string nume, unsigned short varsta, string specie, float greutate) : Mamifer(nume, varsta)
	{
		this->greutate = greutate;
		this->specie = specie;
	}

	void afisare()
	{
		Mamifer::afisare();
		cout << "Specie: " << specie << endl;
		cout << "Greutatea: " << greutate << endl;
	}
};

class Cangur :public Mamifer
{
	float inaltime;
    float greutate;

public:
	Cangur() {}

	Cangur(string nume, unsigned short varsta, float inaltime, float greutate) : Mamifer(nume, varsta)
	{
		this->greutate = greutate;
		this->inaltime = inaltime;
	}

	void afisare()
	{
		Mamifer::afisare();
		cout << "Inaltimea: " << inaltime << endl;
		cout << "Greutatea: " << greutate << endl;
	}
};

int main()
{
	Urs ursi[20];
	Cangur canguri[20];

	string nume;
	string specie;

	unsigned short varsta = 0;

	float greutate = 0;
	float inaltime = 0;

	unsigned short optiune = 0;
	unsigned short optiune1 = 0;

	unsigned short nu = 0;
	unsigned short nc = 0;

	while(true)
	{
		system("CLS");
		cout << "1. Adaugare." << endl;
		cout << "2. Afisare." << endl;
		cout << "3. Iesire." << endl;
		cout << "0. Iesire." << endl;
		cout << "Alegerea dumneavoastra: "; cin >> optiune;

		switch (optiune)
		{
		case 1: cout << "1. Canguri." << endl;
				cout << "2. Ursi. " << endl;
				cout << "Alegerea dumneavoastra este: "; cin >> optiune1;

				cout << "Numarul de animale pe care doriti sa le introduceti este: ";

				switch (optiune1)
				{
				case 1: cin >> nc;
						for (unsigned short i = 0; i < nc; i++)
						{
							cout << "Numele animalului este: "; cin >> nume;
							cout << "Varsta animalului este: "; cin >> varsta;
							cout << "Inaltime: "; cin >> inaltime;
							cout << "Greutatea: "; cin >> greutate;

							canguri[i] = Cangur(nume, varsta, inaltime, greutate);
						}
						break;

				case 2: cin >> nu;
						for (unsigned short i = 0; i < nu; i++)
						{
							cout << "Numele animalului este: "; cin >> nume;
							cout << "Varsta animalului este: "; cin >> varsta;
							cout << "Specie: "; cin >> specie;
							cout << "Greutatea: "; cin >> greutate;
	
							ursi[i] = Urs(nume, varsta, specie, greutate);
						}
						break;
				}
				break;

		case 2: cout << "1. Canguri." << endl;
				cout << "2. Ursi. " << endl;
				cout << "Alegerea dumneavoastra este: "; cin >> optiune1;

				switch (optiune1)
				{
				case 1: if (!nc)
						{
							cout << "Nu au fost citite animale din aceasta categorie!";
						}
						else
						{
							for (unsigned short i = 0; i < nc; i++)
								canguri[i].afisare();
						}
					  break;

				case 2: if (!nu)
						{
							cout << "Nu au fost citite animale din aceasta categorie!";
						}
					   else
						{
							for (unsigned short i = 0; i < nu; i++)
								ursi[i].afisare();
						}
					  break;
				}
				break;

		case 0: exit(1); break;
		}
		_getch();
	}

	return 0;
}