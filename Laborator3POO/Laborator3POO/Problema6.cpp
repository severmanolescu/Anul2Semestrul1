#include <iostream>
#include <conio.h>
#include <string>
#include <stdbool.h>

using namespace std;

class Persoana
{
	string nume;
	string prenume;
	unsigned int varsta;

public:
	Persoana(){}
	Persoana(string nume, string prenume, unsigned int varsta)
	{
		Persoana::nume = nume;
		Persoana::prenume = prenume;
		Persoana::varsta = varsta;
	}

	void afisare()
	{
		cout << "Nume: " << nume << endl;
		cout << "Preume: " << prenume << endl;
		cout << "Varsta: " << varsta << endl;
	}

	string returnareNume()
	{
		return Persoana::nume;
	}

	string returnarePrenume()
	{
		return Persoana::prenume;
	}
};

class Angajat :public Persoana
{
	string departament;
	unsigned int salar;

public:
	Angajat(){}
	Angajat(string nume, string prenume, unsigned int varsta, string departament, unsigned int salat) :Persoana(nume, prenume, varsta)
	{
		Angajat::departament = departament;
		Angajat::salar = salar;
	}

	void afisare()
	{
		Persoana::afisare();
		cout << "Departament: " << departament << endl;
		cout << "Salar: " << salar << endl << endl << endl;
	}
};

int main()
{
	string nume;
	string prenume;
	string departament;
	string prenume_cautat;
	string nume_cautat;

	unsigned int varsta = 0;
	unsigned int salar = 0;
	unsigned int nr;
	unsigned short opt = 0;

	bool ok = 0;
    bool ok2 = 0;

	Angajat angajati[20];

	do
	{
		cout << "1. Introducere angajati" << endl;
		cout << "2. Afisare angajti" << endl;
		cout << "3. Cautare angajati" << endl;
		cout << "4. Stergere angajat" << endl;
		cout << "0. Iesire" << endl;
		cout << "Dati opriunea: ";
		cin >> opt;

		switch (opt)
		{
		case 1: 
			cout << " Dati numarul de angajati: "; cin >> nr;

			for (unsigned short i = 0; i < nr; i++)
			{
				cin.get();
				cout << "Dati numele: "; getline(cin, nume);
				cout << "Dati prenumele: "; getline(cin, prenume);
				cout << "Dati varsta: "; cin >> varsta;

				cin.get();
				cout << "Dati departamentul: "; getline(cin, departament);
				cout << "Dati salariul: "; cin >> salar;

				angajati[i] = Angajat(nume, prenume, varsta, departament, salar);
			}
			break;

		case 2:
			cout << "Afisare: \n";
			for (unsigned short i = 0; i < nr; i++)
			{
				angajati[i].afisare();
			}
			break;

		case 3:
			cin.get();
			cout << "Dati numele cautat: "; getline(cin, nume_cautat);

			for(unsigned short i = 0; i < nr; i++)
				if (nume_cautat.compare(angajati[i].returnareNume()) == 0)
				{
					cout << "Am gasit angajatul!" << endl;
					ok = 1;
				}

			if (!ok)
				cout << "Angajatul nu a fost gasit!" << endl;
			break;
			
		case 4:
			cin.get();
			cout << "Dati prenumele care vreti sa il stergeti: "; getline(cin, prenume_cautat);

			for(unsigned short i = 0; i < nr; i++)
				if (prenume_cautat.compare(angajati[i].returnarePrenume()) == 0)
				{
					for (unsigned short j = i; j < nr - 1; j++)
					{
						angajati[j] = angajati[j + 1];
					}
					nr--;
					ok2 = 1;
					cout << "S-a stees angajatul!" << endl;
				}

			if (!ok2)
				cout << "Angajatul nu a fost gasit!" << endl;
			break;

		case 0: break;
		}
	} while (opt != 0);

	return 0;
}