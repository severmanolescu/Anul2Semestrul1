#include<iostream>
#include<conio.h>
#include <string.h>

using namespace std;

class Student
{
	string nume;
	string pren;
	int grupa, cod_postal;

public:
	Student();
	~Student();
	void citire_date();
	void afisare_date();
};

Student::Student()
{
	cout << "Informatiile despre student: " << endl;
}

void Student::citire_date()
{
	cout << "Nume:"; cin >> nume;
	cout << "Prenume:"; cin >> pren;
	cout << "Grupa:"; cin >> grupa;
	cout << "Cod postal: "; cin >> cod_postal;
}

void Student::afisare_date()
{
	cout << "Nume :" << nume << endl;
	cout << "Prenume:" << pren << endl;
	cout << "Grupa:" << grupa << endl;
	cout << "Cod postal :" << cod_postal;
}

Student :: ~Student()
{
	cout << "Eliberare memorie! ";
}

int main()
{
	Student s;

	s.citire_date();
	s.afisare_date();

	_getch();
	return 0;
}