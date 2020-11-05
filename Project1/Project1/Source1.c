#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool verEr(float x, float y, float epsilon) // Verificare daca cele 2 numere reale sunt egale alaturi de eroarea acceptata
{
    return fabs(x - y) <= epsilon;
}


int cautare_bin(float rand[], int n, float numar_cautat, float epsilon)
{
    int l = 0;
    int r = n - 1;
    int m = 0;
    int pas = 1;

    while (l < r)
    {
        m = (l + r) / 2;

        if (numar_cautat == rand[m])
            return pas;

        else if (numar_cautat < rand[m])
            r = m - 1;

        else
            l = m + 1;
        pas++;
    }

    if (l >= r)
        return -1;

    return pas;
}

int cautare_lin(float rand[], int n, float numar_cautat, float epsilon)
{
    int i;
    int pas = 1; // "pas" va numara nr. de pasi pana la gasirea numarului

    for (i = 0; i < n; i++)
    {
        if (verEr(rand[i], numar_cautat, epsilon))
            return pas;

        else
            pas++;
    }

    return -1; // daca nu se gaseste nr. se returneaza rezultat negativ
}


int main()
{
    float rand[100];
    float epsilon;
    float numar_cautat;
    int n = 0;
    int pas = 0;
    int i = 0;
    bool sortat = 1; // se va folosi pt a verifica daca datele sunt sortate sau nu


    FILE* f;
    FILE* g;
    if ((f = fopen("INPUT.DAT", "r")) == NULL)  // se va afisa un mesaj de eroare daca fisierele nu au putut fii deschise
    {
        printf("Fisierul INPUT.DAT nu exista sau a aparut o eroare la deschiderea fisierului!");
        return -1;
    }
    if ((g = fopen("OUTPUT.DAT", "w")) == NULL)
    {
        printf("Fisierul OUTPUT.DAT nu a putut fii deschis sau creat!");
        return -1;
    }

    fscanf(f, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(f, "%f", &rand[i]); // citirea datelor din fisier
    }

    fscanf(f, "%f %f", &numar_cautat, &epsilon);

    for (i = 1; i < n; i++)  // Verificare daca numerele citite sunt ordonate
    {
        if (rand[i] - epsilon <= rand[i - 1] || rand[i] <= rand[i - 1] - epsilon)
        {
            sortat = 0;
        }
    }

    if (sortat)
        pas = cautare_bin(rand, n, numar_cautat, epsilon); // daca elementele sunt sortate se epeleaza functia pentru cautarea binara

    else
        pas = cautare_lin(rand, n, numar_cautat, epsilon); // daca elementele nu sunt sortate se epeleaza functia pentru cautarea liniara

    for (i = 0; i < n; i++)
        printf("%f ", rand[i]);
    printf("%d %f", sortat, numar_cautat);

    if (pas == -1)
    {
        fprintf(g, "Numarul nu a fost gasit in sirul de numere!"); // daca nr nu a fost gasit se scrie in fisierul output un mesaj cu eroare
        return 0;
    }

    else
    {
        fprintf(g, "Numarul a fost gasit dupa %d pasi! %f", pas, numar_cautat); // daca a fost gasit se scrie mesajul insotitie de nr de pasi si de numarul cautat
        return 0;
    }

    return 0;
}


