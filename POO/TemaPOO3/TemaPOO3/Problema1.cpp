#include <iostream>
#include <conio.h>
#include <string>
#include <stdbool.h>

using namespace std;

class Persoana
{
	string nume;
	string prenume;
	unsigned short varsta;

public:
	Persoana() {}

	Persoana(string nume, string prenume, unsigned short varsta)
	{
		Persoana::nume = nume;
		Persoana::prenume = prenume;
		Persoana::varsta = varsta;
	}

	void afisare(void)
	{
		cout << endl;
		cout << "Nume: " << nume << endl;
		cout << "Prenume: " << prenume << endl;
		cout << "Varsta: " << varsta << endl;
	}

	string ReturnNume(void)
	{
		return Persoana::nume;
	}

	string ReturnPrenume(void)
	{
		return Persoana::prenume;
	}
};

class Student :public Persoana
{
	string facultate;

public:
	Student() {}

	Student(string nume, string prenume, unsigned short varsta, string facultate) : Persoana(nume, prenume, varsta)
	{
		Student::facultate = facultate;
	}

	void afisare(void)
	{
		Persoana::afisare();
		cout << "Facultate: " << Student::facultate << endl;
	}
};

class Licenta : public Student
{
	string specializare;
	unsigned short an;

public:
	Licenta() {}
	Licenta(string nume, string prenume, unsigned short varsta,
		string facultate,
		string specializare, unsigned short an): Student(nume, prenume, varsta, facultate)
	{
		Licenta::specializare = specializare;
		Licenta::an = an;
	}

	void afisare(void)
	{
		Student::afisare();
		cout << "Specializare licenta: " << specializare << endl;
		cout << "An: " << an << endl;
	}
};

class Master :public Student
{
	string specializare;
	unsigned short an;

public:
	Master() {}

	Master(string nume, string prenume, unsigned short varsta,
		string facultate,
		string specializare, unsigned short an) : Student(nume, prenume, varsta, facultate)
	{
	   Master::specializare = specializare;
	   Master::an = an;
	}

	void afisare(void)
	{
		Student::afisare();
		cout << "Specializare Master: " << specializare << endl;
		cout << "An: " << an << endl;
	}
};

class Doctorat :public Student
{
	string specializare;
	unsigned short an;

public:
	Doctorat() {}

	Doctorat(string nume, string prenume, unsigned short varsta,
		string facultate,
		string specializare, unsigned short an) : Student(nume, prenume, varsta, facultate)
	{
	Doctorat::specializare = specializare;
	Doctorat::an = an;
	}

	void afisare(void)
	{
		Student::afisare();
		cout << "Secializare doctorat: " << specializare << endl;
		cout << "An: " << an << endl;
	}
};

class Angajat :public Persoana
{
	string firma;
	string profesie;

public:
	Angajat() {};

	Angajat(string nume, string prenume, unsigned short varsta,
		string firma, string profesie) :Persoana(nume, prenume, varsta)
	{
	  Angajat::firma = firma;
	  Angajat::profesie = profesie;
	}

	void afisare(void)
	{
		Persoana::afisare();
		cout << "Firma: " << firma << endl;
		cout << "Profesie: " << profesie << endl;
	}
};

class Profesor :public Angajat
{
	unsigned short vechime;

public:
	Profesor() {};

	Profesor(string nume, string prenume, unsigned short varsta,
		string firma, string profesie, 
		unsigned short vechime) :Angajat(nume, prenume, varsta, firma, profesie)
	{
	  Profesor:vechime = vechime;
	}

	void afisare(void)
	{
		Angajat::afisare();
		cout << "Vechime: " << vechime << endl;
	}
};

class Inginer :public Angajat
{
	unsigned short vechime;

public:
    Inginer() {};

	Inginer(string nume, string prenume, unsigned short varsta,
		string firma, string profesie,
		unsigned short vechime) :Angajat(nume, prenume, varsta, firma, profesie)
	{
	 Inginer:vechime = vechime;
	}

	void afisare(void)
	{
		Angajat::afisare();
		cout << "Vechime: " << vechime << endl;
	}
};

int main(void)
{
	bool cLic = 0;
	bool cMas = 0;
	bool cDoc = 0;
	bool cPro = 0;
	bool cIng = 0;

	unsigned short nLic = 0;
	unsigned short nMas = 0;
	unsigned short nDoc = 0;
	unsigned short nPro = 0;
	unsigned short nIng = 0;

	unsigned short optiune = 0;
	unsigned short optiune1 = 0;

	string nume;
	string prenume;
	string specializare;
	string facultate;
	string firma;
	string profesie;

	string nume_cautat;

	unsigned short varsta = 0;
	unsigned short an = 0;
	unsigned short vechime = 0;

	Licenta lic[10];
	Master mas[10];
	Doctorat doc[10];
	Profesor pro[10];
	Inginer ing[10];

	while (1)
	{
		system("CLS");
		cout << "1. Introducere persoane." << endl;
		cout << "2. Afisare persoane." << endl;
		cout << "3. Cautare persoane." << endl;
		cout << "4. Stergere persoane." << endl;
		cout << "0. Iesire." << endl;
		cout << "Introduceti alegerea dumneavoastra:" << endl;
		cin >> optiune;

		switch(optiune)
		{
		case 1: cout << endl << endl;
			    cout << "1. Studenti Licenta." << endl;
			    cout << "2. Studenti Master." << endl;
				cout << "3. Studenti Doctorat." << endl;
				cout << "4. Profesori." << endl;
				cout << "5. Ingineri." << endl;
				cout << "Introduceti alegerea: ";
				cin >> optiune1;

				cout << endl << "Dati numarul de persoane care doriti sa le introduceti: ";

				switch (optiune1)
				{
				case 1: cin >> nLic;

					cLic = 1;

					for (unsigned short i = 0; i < nLic; i++)
					{
						cin.get();
						cout << endl;
						cout << "Student licenta " << i + 1 << ": " << endl;
						cout << "Nume: "; cin >> nume;
						cout << "Prenume: "; cin >> prenume;
						cout << "Varsta: "; cin >> varsta;
						cout << "Facultate: "; cin >> facultate;
						cout << "Specializare: "; cin >> specializare;
						cout << "An: "; cin >> an;

						lic[i] = Licenta(nume, prenume, varsta, facultate, specializare, an);
					}

					break;

				case 2: cin >> nMas;

					cMas = 1;

					for (unsigned short i = 0; i < nMas; i++)
					{
						cin.get();

						cout << endl;
						cout << "Student master " << i + 1 << ": " << endl;
						cout << "Nume: "; cin >> nume;
						cout << "Prenume: "; cin >> prenume;
						cout << "Varsta: "; cin >> varsta;
						cout << "Facultate: "; cin >> facultate;
						cout << "Specializare: "; cin >> specializare;
						cout << "An: "; cin >> an;

						mas[i] = Master(nume, prenume, varsta, facultate, specializare, an);
					}

					break;

				case 3: cin >> nDoc;

					cDoc = 1;

					for (unsigned short i = 0; i < nDoc; i++)
					{
						cin.get();

						cout << endl;
						cout << "Student doctorat " << i + 1 << ": " << endl;
						cout << "Nume: "; cin >> nume;
						cout << "Prenume: "; cin >> prenume;
						cout << "Varsta: "; cin >> varsta;
						cout << "Facultate: "; cin >> facultate;
						cout << "Specializare: "; cin >> specializare;
						cout << "An: "; cin >> an;

						doc[i] = Doctorat(nume, prenume, varsta, facultate, specializare, an);
					}

					break;

				case 4: cin >> nPro;

					cPro = 1;

					for (unsigned short i = 0; i < nPro; i++)
					{
						cin.get();

						cout << endl;
						cout << "Profesor " << i + 1 << ": " << endl;
						cout << "Nume: "; cin >> nume;
						cout << "Prenume: "; cin >> prenume;
						cout << "Varsta: "; cin >> varsta;
						cout << "Firma: "; cin >> firma;
						cout << "Profesie: "; cin >> profesie;
						cout << "Vechime: "; cin >> vechime;

						pro[i] = Profesor(nume, prenume, varsta, firma, profesie, vechime);
					}

					break;

				case 5: cin >> nIng;

					cIng = 1;

					for (unsigned short i = 0; i < nIng; i++)
					{
						cin.get();

						cout << endl;
						cout << "Profesor " << i + 1 << ": " << endl;
						cout << "Nume: "; cin >> nume;
						cout << "Prenume: "; cin >> prenume;
						cout << "Varsta: "; cin >> varsta;
						cout << "Firma: "; cin >> firma;
						cout << "Profesie: "; cin >> profesie;
						cout << "Vechime: "; cin >> vechime;


						ing[i] = Inginer(nume, prenume, varsta, facultate, specializare, an);
					}
					break;

				default:
					break;
				}
				break;

		case 2: cout << endl << endl;
			    cout << "1. Studenti Licenta." << endl;
		     	cout << "2. Studenti Master." << endl;
		    	cout << "3. Studenti Doctorat." << endl;
		    	cout << "4. Profesori." << endl;
		    	cout << "5. Ingineri." << endl;
		    	cout << "Introduceti alegerea: ";
		    	cin >> optiune1;

				switch (optiune1)
				{
				case 1: if (!cLic)
				         	cout << "Nimeni nu a fost citit!";
					    else
				        { 
							for (unsigned short i = 0; i < nLic; i++)
								lic[i].afisare();
						}
					  break;

				case 2: if (!cMas)
							cout << "Nimeni nu a fost citit!";
					  else
						{
							for (unsigned short i = 0; i < nMas; i++)
								mas[i].afisare();
						}
						  break;

				case 3: if (!cDoc)
							cout << "Nimeni nu a fost citit!";
					   else
						{
							for (unsigned short i = 0; i < nDoc; i++)
								doc[i].afisare();
						}
						  break;

				case 4: if (!cPro)
							cout << "Nimeni nu a fost citit!";
					    else
						{
							for (unsigned short i = 0; i < nPro; i++)
								pro[i].afisare();
						}
						  break;

				case 5: if (!cIng)
							cout << "Nimeni nu a fost citit!";
					   else
						{
							for (unsigned short i = 0; i < nIng; i++)
								ing[i].afisare();
						}
						  break;
				}
				break;

		case 3: cout << endl << endl;
				cout << "Categoria unde doriti sa cautati: " << endl;
				cout << "1. Studenti Licenta." << endl;
				cout << "2. Studenti Master." << endl;
				cout << "3. Studenti Doctorat." << endl;
				cout << "4. Profesori." << endl;
				cout << "5. Ingineri." << endl;
				cout << "Introduceti alegerea: ";
				cin >> optiune1;
				cin.get();
				cout << endl << "Numele persoanei pe care o cautati: "; cin >> nume_cautat;

				switch (optiune1)
				{
				case 1:
					for (unsigned short i = 0; i < nLic; i++)
					{
						if (nume_cautat.compare(lic[i].ReturnNume()) == 0)
						{
							lic[i].afisare();
							break;
						}
					}
						cout << "Persoana cautata nu a fost gasita!" << endl;
						break;

				case 2:
					for (unsigned short i = 0; i < nMas; i++)
						if (nume_cautat.compare(mas[i].ReturnNume()) == 0)
						{
							mas[i].afisare();
							break;
						}
					cout << "Persoana cautata nu a fost gasita!" << endl;
					break;

				case 3:
					for (unsigned short i = 0; i < nDoc; i++)
						if (nume_cautat.compare(doc[i].ReturnNume()) == 0)
						{
							doc[i].afisare();
							break;
						}
					cout << "Persoana cautata nu a fost gasita!" << endl;
					break;

				case 4:
					for (unsigned short i = 0; i < nPro; i++)
						if (nume_cautat.compare(pro[i].ReturnNume()) == 0)
						{
							pro[i].afisare();
							break;
						}
					cout << "Persoana cautata nu a fost gasita!" << endl;
					break;

				case 5:
					for (unsigned short i = 0; i < nIng; i++)
						if (nume_cautat.compare(ing[i].ReturnNume()) == 0)
						{
							ing[i].afisare();
							break;
						}
					cout << "Persoana cautata nu a fost gasita!" << endl;
					break;
				}
				break;

		case 4: cout << endl << endl;
				cout << "Categoria unde doriti sa stergeti: " << endl;
				cout << "1. Studenti Licenta." << endl;
				cout << "2. Studenti Master." << endl;
				cout << "3. Studenti Doctorat." << endl;
				cout << "4. Profesori." << endl;
				cout << "5. Ingineri." << endl;
				cout << "Introduceti alegerea: ";
				cin >> optiune1;

				cout << endl << "Numele persoanei pe care doriti sa o stergeti: ";
				cin >> nume_cautat;

				switch (optiune1)
				{
				case 1: 
					for (unsigned short i = 0; i < nLic; i++)
					{
						if (nume_cautat.compare(lic[i].ReturnNume()) == 0)
						{
							for (unsigned j = i; j < nLic; j++)
							{
								lic[i] = lic[i + 1];
							}
							nLic--;
							cout << nume << " a fosr sters!" << endl;
							break;
						}
					}
					break;

				case 2:
					for (unsigned short i = 0; i < nMas; i++)
					{
						if (nume_cautat.compare(mas[i].ReturnNume()) == 0)
						{
							for (unsigned j = i; j < nLic; j++)
							{
								mas[i] = mas[i + 1];
							}
							nMas--;
							cout << nume << " a fosr sters!" << endl;
							break;
						}
					}
					break;

				case 3:
					for (unsigned short i = 0; i < nDoc; i++)
					{
						if (nume_cautat.compare(doc[i].ReturnNume()) == 0)
						{
							for (unsigned j = i; j < nDoc; j++)
							{
								doc[i] = doc[i + 1];
							}
							nDoc--;
							cout << nume << " a fosr sters!" << endl;
							break;
						}
					}
					break;

				case 4:
					for (unsigned short i = 0; i < nPro; i++)
					{
						if (nume_cautat.compare(pro[i].ReturnNume()) == 0)
						{
							for (unsigned j = i; j < nPro; j++)
							{
								pro[i] = pro[i + 1];
							}
							nPro--;
							cout << nume << " a fosr sters!" << endl;
							break;
						}
					}
					break;

				case 5:
					for (unsigned short i = 0; i < nIng; i++)
					{
						if (nume_cautat.compare(ing[i].ReturnNume()) == 0)
						{
							for (unsigned j = i; j < nIng; j++)
							{
								ing[i] = ing[i + 1];
							}
							nIng--;
							cout << nume << " a fosr sters!" << endl;
							break;
						}
					}
					break;
				}
				break;

		case 0: return 0;
				break;

		default:
			break;
		}
		_getch();
	}

	return 0;
}