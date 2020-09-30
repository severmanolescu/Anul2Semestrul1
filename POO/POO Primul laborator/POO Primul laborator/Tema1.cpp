#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Persoana {
	char nume[20];
	char prenume[20];
	char cnp[13];
	char telefon[10];
	unsigned short varsta;

public:
	void setare(char[], char[], char[], char[], unsigned short);
	void afisare(void);
};

void Persoana::setare(char nume_pers[], char prenume_pers[], char cnp_pers[], char telefon_pers[], unsigned short varsta_pers)
{
	strcpy(nume, nume_pers);
	strcpy(prenume, prenume_pers);
	strcpy(cnp, cnp_pers);
	strcpy(telefon, telefon_pers);
	varsta = varsta_pers;
}

void Persoana::afisare(void)
{
	cout << "Datele persoanei: \n";
	cout << " Nume prenume: " << nume << " " << prenume << endl;
	cout << " CNP: " << cnp << endl;
	cout << " Telefon: " << telefon << endl;
	cout << " Varsta: " << varsta;

	_getch();
}

int main()
{
	Persoana pers;
	char nume[20];
	char prenume[20];
	char cnp[13];
	char telefon[10];
	unsigned short varsta = 0;

	cout << "Dati datele persoanei: \n";
	cout << " Numele: ";    cin >> nume;
	cout << " Prenumele: "; cin >> prenume;
	cout << " CNP: ";       cin >> cnp;
	cout << " Telefon: ";   cin >> telefon;
	cout << " Varsta: ";    cin >> varsta;

	pers.setare(nume, prenume, cnp, telefon, varsta);
	pers.afisare();

	return 0;
}