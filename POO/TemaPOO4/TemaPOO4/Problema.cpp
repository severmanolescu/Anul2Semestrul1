#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Monitoare
{
protected:
	string producator;
	float diagonala;
	float pret;
	
public:
	Monitoare() { };
	Monitoare(string producator, float diagonala, float pret)
	{
		this->diagonala = diagonala;
		this->pret = pret;
		this->producator = producator;
	}

	virtual void afisare()
	{
		cout << endl << "Producator: " << producator;
		cout << endl << "Diagonala: " << diagonala;
		cout << endl << "Pret: " << pret;
	}
};

class LCD: public Monitoare
{
	unsigned short timp_raspuns;
	unsigned short conectori;
	string tip_ecran;
	LCD* next;
	LCD* head;

public:
	LCD() {}
	LCD(string producator, float diagonala, float pret, unsigned short timp_raspuns, unsigned short conectori, string tip_ecran)
		:Monitoare(producator, diagonala, pret)
	{
		this->timp_raspuns = timp_raspuns;
		this->conectori = conectori;
		this->tip_ecran = tip_ecran;
	}

	void afisare();
	void adaugare();
	void stergere(string);
	void cautare(string);
};

class LED : public Monitoare
{
	unsigned short boxe;
	string format_ecran;
	string iluminare;
	LED* next;
	LED* head;

public:
	LED() {}
	LED(string producator, float diagonala, float pret, string format_ecran, string iluminare, unsigned short boxe)
		:Monitoare(producator, diagonala, pret)
	{
		this->format_ecran = format_ecran;
		this->iluminare = iluminare;
		this->boxe = boxe;
	}

	void afisare();
	void adaugare();
	void stergere(string);
	void cautare(string);
};

void LCD::adaugare()
{
	unsigned short timp_raspuns;
	unsigned short conectori;

	float pret;
	float diagonala;

	string producator;
	string tip_ecran;

	cout << endl;
	cout << "Producatorul: "; cin >> producator;
	cout << "Pret: "; cin >> pret;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Timp raspuns: "; cin >> timp_raspuns;
	cout << "Tip ecran: "; cin >> tip_ecran;
	cout << "Conectori: "; cin >> conectori;

	LCD* aux = new LCD(producator, diagonala, pret, timp_raspuns, conectori, tip_ecran);
	LCD* p = new LCD();
	LCD* q = new LCD();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(aux->producator) > 0)
		{
			break;
		}
	}

	if (p == q)
	{
		aux->next = head;
		head = aux;
	}

	else
	{
		q->next = aux;
		aux->next = p;
	}
	
}

void LCD::afisare()
{
	LCD* p = head;

	while (p != NULL)
	{
		cout << endl;
		cout << "Producator: " << p->producator << endl;
		cout << "Diagonala: " << p->diagonala << endl;
		cout << "Pret: " << p->pret << endl;
		cout << "Timp raspuns: " << p->timp_raspuns << endl;
		cout << "Tip ecran: " << p->tip_ecran << endl;
		cout << "Conectori: " << p->conectori << endl << endl;
		p = p->next;
	}
}

void LCD::stergere(string producator)
{
	LCD* p = new LCD();
	LCD* q = new LCD();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(producator) == 0)
		{
			q->next = p->next;
			delete(p);
			head = q;
			break;
		}
	}
}

void LCD::cautare(string producator)
{
	LCD* p = new LCD();
	LCD* q = new LCD();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(producator) == 0)
		{
			cout << endl;
			cout << "Producator: " << p->producator << endl;
			cout << "Diagonala: " << p->diagonala << endl;
			cout << "Pret: " << p->pret << endl;
			cout << "Timp raspuns: " << p->timp_raspuns << endl;
			cout << "Tip ecran: " << p->tip_ecran << endl;
			cout << "Conectori: " << p->conectori << endl << endl;
			break;
		}
	}
}

void LED::adaugare()
{
	unsigned short boxe;

	float pret;
	float diagonala;

	string producator;
	string format_ecran;
	string iluminare;

	cout << endl;
	cout << "Producatorul: "; cin >> producator;
	cout << "Pret: "; cin >> pret;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Format ecran: "; cin >> format_ecran;
	cout << "Iluminare: "; cin >> iluminare;
	cout << "Boxe integrate: "; cin >> boxe;

	LED* aux = new LED(producator, diagonala, pret, format_ecran, iluminare, boxe);
	LED* p = new LED();
	LED* q = new LED();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(aux->producator) > 0)
		{
			break;
		}
	}

	if (p == q)
	{
		aux->next = head;
		head = aux;
	}

	else
	{
		q->next = aux;
		aux->next = p;
	}
}

void LED::afisare()
{
	LED* p = head;

	while (p != NULL)
	{
		cout << endl;
		cout << "Producator: " << p->producator << endl;
		cout << "Diagonala: " << p->diagonala << endl;
		cout << "Pret: " << p->pret << endl;
		cout << "Format ecran: " << p->format_ecran << endl;
		cout << "Iluminare: " << p->iluminare << endl;
		cout << "Boxe: " << p->boxe << endl << endl;
		p = p->next;
	}
}

void LED::stergere(string producator)
{
	LED* p = new LED();
	LED* q = new LED();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(producator) == 0)
		{
			q->next = p->next;
			delete(p);
			head = q;
			break;
		}
	}
}

void LED::cautare(string producator)
{
	LED* p = new LED();
	LED* q = new LED();

	for (p = q = head; p != NULL; q = p, p = p->next)
	{
		if (p->producator.compare(producator) == 0)
		{
			cout << endl;
			cout << "Producator: " << p->producator << endl;
			cout << "Diagonala: " << p->diagonala << endl;
			cout << "Pret: " << p->pret << endl;
			cout << "Format ecran: " << p->format_ecran << endl;
			cout << "Iluminare: " << p->iluminare << endl;
			cout << "Boxe: " << p->boxe << endl << endl;
			break;
		}
	}
}

int main()
{
	unsigned short optiune = 0;
	unsigned short optiune1 = 0;

	string cautare;

	LED* led = new LED("", 0, 0, "", "", 0);
	LCD* lcd = new LCD("", 0, 0, 0, 0, "");

	do
	{
		cout << endl;
		cout << "1. Adaugarea unui monitor LED/LCD.\n";
		cout << "2. Afisare monitoare LED/LCD.\n";
		cout << "3. Stergere monitor LED/LCD.\n";
		cout << "4. Cautare monitor LED/LCD.\n";
		cout << "5. Ordonare monitoare.\n";
		cout << "0. Iesire.\n";

		cout << "Optiunea dumneavoastra este: ";
		cin >> optiune;

		switch (optiune)
		{
		case 1: cout << endl;
				cout << "1. Adaugare monitor LED.\n";
			    cout << "2. Adaugare monitor LCD.\n";

				cout << "Optiunea dumneavoastra este: ";
				cin >> optiune1;

				switch (optiune1)
				{
				case 1: led->adaugare(); break;

				case 2: lcd->adaugare(); break;

				default: cout << "Optiune gresita!\n"; break;
				}
				break;

		case 2: cout << endl;
				cout << "1. Afisare monitor LED.\n";
				cout << "2. Afisare monitor LCD.\n";

				cout << "Optiunea dumneavoastra este: ";
				cin >> optiune1;

				switch (optiune1)
				{
				case 1: led->afisare(); break;
	
				case 2: lcd->afisare(); break;

				default: cout << "Optiune gresita!\n"; break;
				}
				break;

		case 3: cout << endl;
				cout << "1. Stergere monitor LED.\n";
				cout << "2. Stergere monitor LCD.\n";
	
				cout << "Optiunea dumneavoastra este: ";
				cin >> optiune1;

				cout << "Dati numele producatorului care doriti sa fie sters: ";
				cin >> cautare;

				switch (optiune1)
				{
				case 1: led->stergere(cautare); break;

				case 2: lcd->stergere(cautare); break;

				default: cout << "Optiune gresita!\n"; break;
				}
				break;

		case 4: cout << endl;
				cout << "1. Cautare monitor LED.\n";
				cout << "2. Cautare monitor LCD.\n";

				cout << "Optiunea dumneavoastra este: ";
				cin >> optiune1;

				cout << "Dati numele producatorului care doriti sa fie cautat: ";
				cin >> cautare;

				switch (optiune1)
				{
				case 1: led->cautare(cautare); break;

				case 2: lcd->cautare(cautare); break;

				default: cout << "Optiune gresita!\n"; break;
				}
				break;

		case 5: cout << "Monitoarele au fost ordonate la citire!\n";
			    break;

		case 0: cout << "Iesire...";
				delete(led);
				delete(lcd);
			    exit(0); break;

		default: cout << "Opriune gresita!" << endl; break;

		}

	} while (optiune);

	return 0;
}