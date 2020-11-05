#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Student
{
	string nume;
	string rol;
	string adresa;
	string cod_postal;

public:
	Student(string nume_student, string rol_student, string adresa_student, string cod_postal_student);
	~Student();
};

Student::Student(string nume_student, string rol_student, string adresa_student, string cod_postal_student)
{
	cout << " Constructor apelat!\n";
	nume = nume;
	rol = rol_student;
	adresa = adresa_student;
	cod_postal = cod_postal_student;
}

Student::~Student()
{
	cout << "Destructor apelat!";
}

int main()
{
	string nume;
	string adresa;
	string rol;
	string cod_postal;

	cout << " Numele studentului este: "; cin >> nume;
	cout << " Adresa studentului este: "; cin >> adresa;
	cout << " Rolul studentului este: "; cin >> rol;
	cout << " Codul postal al studentului este: "; cin >> cod_postal;

	Student stud(nume, rol, adresa, cod_postal);

	_getch();
	return 0;
}