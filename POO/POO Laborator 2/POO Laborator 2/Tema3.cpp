#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class Profesor
{
	string nume;
	string departament;
	string grad_didactic;
	unsigned short vechime;

public:
	void setare(string, string, string, unsigned short);
	void afisare(void);
	~Profesor();
};

void Profesor::setare(string nume_pr, string departament_pr, string grad_didactic_pr, unsigned short vechime_pr)
{
	nume = nume_pr;
	departament = departament_pr;
	grad_didactic = grad_didactic_pr;
	vechime = vechime_pr;
}

void Profesor::afisare(void)
{
	cout << "Nume: " << nume << endl;
	cout << "Departament: " << departament << endl;
	cout << "Grad didactic: " << grad_didactic << endl;
	cout << "Vechime: " << vechime;
}

Profesor::~Profesor()
{

}

int main()
{
	Profesor* prof;
	unsigned short n = 0;
	unsigned short i = 0;

	string nume;
	string departament;
	string grad_didactic;
	unsigned short vechime = 0;

	cout << " Numarul de profesori este: "; cin >> n;

	prof = new Profesor[n];

	for (i = 0; i < n; i++)
	{
		cout << " Profesorul " << i + 1 << ": \n";
		cout << " Nume : "; cin >> nume;
		cout << " Departament : "; cin >> departament;
		cout << " Grad didactic : "; cin >> grad_didactic;
		cout << " Varsta : "; cin >> vechime;
		cout << "\n\n";

		prof[i].setare(nume, departament, grad_didactic, vechime);
	}

	cout << " Afisarea profesorilor: \n";
	for (i = 0; i < n; i++)
		prof[i].afisare(), cout << "\n\n";

	prof->~Profesor();

	_getch();
	return 0;
}