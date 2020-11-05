#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Sofer {
	char nume[40];
	char cnp[13];
	unsigned short varsta;
	char adresa[40];

public:
	void setare(char[], char[], unsigned short, char[]);
	void afisare(void);
};

class Masina {
	char producator[20];
	char model[10];
	unsigned short an_fabricatie;
	char sofer[40];

public:
	void setare(char[], char[], unsigned short, char[]);
	void afisare(void);
};

void Sofer::setare(char nume_sofer[], char cnp_sofer[], unsigned short varsta_sofer, char adresa_sofer[])
{
	strcpy(nume, nume_sofer);
	strcpy(cnp, cnp_sofer);
	strcpy(adresa, adresa_sofer);
	varsta = varsta_sofer;
}

void Sofer::afisare()
{
	cout << "\nDatele soferului sunt: \n";
	cout << " Nume: "   << nume << endl;
	cout << " Cnp: "    << cnp << endl;
	cout << " Varsta: " << varsta << endl;
	cout << " Adresa: " << adresa << endl;
}

void Masina::setare(char producator_masina[], char model_masina[], unsigned short an_fabricatie_masina, char sofer_masina[])
{
	strcpy(producator, producator_masina);
	strcpy(model, model_masina);
	strcpy(sofer, sofer_masina);
	an_fabricatie = an_fabricatie_masina;
}

void Masina::afisare()
{
	cout << "\nDatele masinii sunt: \n";
	cout << " Producator: "    << producator << endl;
	cout << " Model: "         << model << endl;
	cout << " An fabricatie: " << an_fabricatie << endl;
	cout << " Sofer: "         << sofer << endl;
	_getch();
}

int main()
{
	Sofer sof;
	Masina mas;
	char nume[40];
	char cnp[13];
	char adresa[40];
	char producator[20];
	char model[10];
	char sofer[40];
	unsigned short varsta;
	unsigned short an_fabricatie;

	cout << "Dati datele soferului: \n";
	cout << " Nume: ";   cin >> nume;
	cout << " CNP: ";    cin >> cnp;
	cout << " Varsta: "; cin >> varsta;
	cout << " Adresa: "; cin >> adresa;

	cout << "\nDati datele masinii: \n";
	cout << " Producator: ";    cin >> producator;
	cout << " Model: ";         cin >> model;
	cout << " An fabricatie: "; cin >> an_fabricatie;
	cout << " Sofer: ";         cin >> sofer;

	sof.setare(nume, cnp, varsta, adresa);
	sof.afisare();

	mas.setare(producator, model, an_fabricatie, sofer);
	mas.afisare();

	return 0;
}