#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Functie folosita pentru verificare daca citirea a putut fii efectuata
// Deoarece functia fscanf returneaza numarul de citiri care au avut loc cu succes
// Vom verifica daca valoarea returnata corespunde numarului numerelor care trebuiau citite
void reading (unsigned short i, unsigned short read)
{
	if (i != read)
	{
		printf("Eroare la citire!");
		exit(0);
	}
}

// Verificare daca cele 2 numere reale sunt egale alaturi de eroarea acceptata
bool equal_float(float x, float y, float epsilon)
{
	return fabs(x - y) <= epsilon;
}

int linear_search(float row[], unsigned n, float number_searched, float epsilon)
{
	unsigned i;
	//Step va numara nuamrul de pasi pana la gasirea numarului
	unsigned step = 1; 

	for (i = 0; i < n; i++)
	{
		if (equal_float(row[i], number_searched, epsilon))
			return step;

		else
			step++;
	}

	// Daca programul a ajuns pana in acest punct inseamna c nuamrul nu a fost gasit
	// Deci acesta va trimite un raspuns 'negativ'
	return -1;
}

int binary_search(float row[], int n, float number_searched, float epsilon)
{
	int l = 0;
	int r = n - 1;
	int m = 0;
	int step = 1;

	while (l < r)
	{
		m = (l + r) / 2;

		if (number_searched == row[m])
			return step;

		else if (number_searched < row[m])
			r = m - 1;

		else
			l = m + 1;
		step++;
	}

	if (l >= r)
		return -1;

	return step;
}

int main()
{
	//Initializare date
	float epsilon;
	float number_searched;
	float row[100];

	unsigned n = 0;
	unsigned i = 0;
	int step = 0;

	//Parametrul sortat va fi folosit pentru a verifica daca datele citite sunt sortate sau nu
	bool sorted = 1;


	FILE* input_file;
	FILE* output_file;
	// Programul va afisa un mesaj de eroare daca fisierele INPUT.DAT sau OUTPUT.DAT nu au putut fii deschise
	if ((input_file = fopen("INPUT.DAT", "r")) == NULL)
	{
		printf("Fisierul INPUT.DAT nu exista sau a aparut o eroare la deschidere!");
		return -1;
	}
	if ((output_file = fopen("OUTPUT.DAT", "w")) == NULL)
	{
		printf("Fisierul OUTPUT.DAT nu a putut fii deschis sau creat!");
		return -1;
	}

	reading(fscanf(input_file, "%u", &n), 1);

	// Efectuare citirea datelor din fisier
	for (i = 0; i < n; i++)
	{
		reading(fscanf(input_file, "%f", &row[i]), 1);
	}

	reading(fscanf(input_file, "%f %f", &number_searched, &epsilon), 2);

	// Verificare daca numerele citite sunt ordonate
	for (i = 1; i < n; i++)
	{
		if (row[i] - epsilon <= row[i - 1] || row[i] <= row[i - 1] - epsilon)
		{
			sorted = 0;
		}
	}

	if (sorted)
		step = binary_search(row, n, number_searched, epsilon); // Daca elementele sunt sortate se epeleaza functia pentru cautarea binara

	else
		step = linear_search(row, n, number_searched, epsilon); // Daca elementele sunt sortate se epeleaza functia pentru cautarea liniara

	// Scriere un mesaj de eroare in OUTPUT.DAT daca nuamrul nu a fost gasit
	if (step == -1)
	{
		fprintf(output_file, "Numarul nu a fost gasit in sirul de numere!");
		return 0;
	}

	else
	{
		fprintf(output_file, "Numarul a fost gasit dupa %d pasi! %f", step, number_searched);
		return 0;
	}

	return 0;
}