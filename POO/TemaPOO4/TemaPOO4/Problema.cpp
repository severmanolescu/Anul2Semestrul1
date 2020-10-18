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
	LCD(string producator, float diagonala, float pret, unsigned short timp_raspuns, unsigned short conectori, string tip_ecran)
		:Monitoare(producator, diagonala, pret)
	{
		this->timp_raspuns = timp_raspuns;
		this->conectori = conectori;
		this->tip_ecran = tip_ecran;
	}

	void afisare();
	void adaugare();
};

class LED : public Monitoare
{
	unsigned short boxe;
	string format_ecran;
	string iluminare;
	LED* next;
	LED* head;

public:
	LED(string producator, float diagonala, float pret, string format_ecran, string iluminare, unsigned short boxe)
		:Monitoare(producator, diagonala, pret)
	{
		this->format_ecran = format_ecran;
		this->iluminare = iluminare;
		this->boxe = boxe;
	}

	void afisare();
	void adaugare();
};

void LCD::adaugare()
{
	unsigned short timp_raspuns;
	unsigned short conectori;

	float pret;
	float diagonala;

	string producator;
	string tip_ecran;

	cout << "Prodcuatorul: "; cin >> producator;
	cout << "Pret: "; cin >> pret;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Timp raspuns: "; cin >> timp_raspuns;
	cout << "Tip ecran: "; cin >> tip_ecran;
	cout << "Conectori: "; cin >> conectori;

	LCD* p = new LCD(producator, diagonala, pret, timp_raspuns, conectori, tip_ecran);

	p->next = head;
	head = p;
}

void LCD::afisare()
{
	LCD* p = head;

	while (p != NULL)
	{
		cout << endl;
		cout << "Producator: " << p->producator;
		cout << "Diagonala: " << p->diagonala;
		cout << "Pret: " << p->pret;
		cout << "Timp raspuns: " << p->timp_raspuns;
		cout << "Tip ecran: " << p->tip_ecran;
		cout << "Conectori: " << p->conectori;
		p = p->next;
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

	cout << "Prodcuatorul: "; cin >> producator;
	cout << "Pret: "; cin >> pret;
	cout << "Diagonala: "; cin >> diagonala;
	cout << "Format ecran: "; cin >> format_ecran;
	cout << "Iluminare: "; cin >> iluminare;
	cout << "Boxe integrate: "; cin >> boxe;

	LED* p = new LED(producator, diagonala, pret, format_ecran, iluminare, boxe);

	p->next = head;
	head = p;
}

void LED::afisare()
{
	LED* p = head;

	while (p != NULL)
	{
		cout << endl;
		cout << "Producator: " << p->producator;
		cout << "Diagonala: " << p->diagonala;
		cout << "Pret: " << p->pret;
		cout << "Format ecran: " << p->format_ecran;
		cout << "Iluminare: " << p->iluminare;
		cout << "Boxe: " << p->boxe;
		p = p->next;
	}
}

int main()
{
	unsigned short optiune = 0;

	LED* led = new LED("", 0, 0, "", "", 0);
	LCD* lcd = new LCD("", 0, 0, 0, 0, "");

	do
	{
		cout << "1. Adaugarea unui monitor LED/LCD.\n";
		cout << "2. Afisare monitoare LED/LCD.\n";
		cout << "3. Stergere monitor LED/LCD.\n";
		cout << "4. Cautare monitor LED/LCD.\n";
		cout << "5. Ordonare monitoare.\n";

	} while (optiune);

	return 0;
}