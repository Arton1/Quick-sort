// Projekt 2 1I1 - Artur Wyrozębski

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(double *a, double *b);
int generate(double tab[]);
void sortQuick(double tab[], int s, int e);

void sortQuick(double tab[], int first, int last) {
	if (first >= last)
		return;
	int i, j;
	double pivot;
	j = i = first;
	pivot = tab[(first + last) / 2]; //tworzenie kopii liczby środkowej

	swap(&tab[(first + last) / 2], &tab[last]); //przenoszenie liczby środkowej na koniec

	while (i < last) { //przenoszenie liczb mniejszych od środkowej na lewo od środkowej, a większych na prawo
		if (tab[i] >= pivot)
			i++;
		else {
			swap(&tab[i], &tab[j]);
			j++;
			i++;
		}
	}

	swap(&tab[j], &tab[last]); //przenoszenie liczby środkowej na granicę między liczbami mniejszymi, a większymi od niej

	sortQuick(tab, first, j-1); //l/ mniejsze
	sortQuick(tab, j+1, last); //l. większe
}

void swap(double *a, double *b) { //zamiana miejscami dwóch liczb zmiennoprzecinkowych
	double temp = *a;
	*a = *b;
	*b = temp;
}

int generate(double tab[]) { //generowanie liczby w notacji naukowej
	int n, w, negative, i, j;
	double x;
	srand(time(NULL)); // start maszyny losującej
	n = rand(); //losowanie wielkości tablicy
	n = (n*n) % 999;
	for (j = 0; j < n; j++) {
		negative = rand() % 2; // losowanie, czy liczba ma być dodatnia czy ujemna

		do {
			x = rand() % 100; //losowanie mantysy
		} while (x == 0.0);
		x = x*x*x;
		x = (int)x % 1000000;
		while (!(x > 0 && x < 10))
			x = x / 10;

		w = rand() % 15; //losowanie wykładnika
		for (i = 0; i < w; i++) {
			x = x * 10;
		}

		if (negative == 1)
			x = -x;
		tab[j] = x;
	}
	tab[n] = x; // wstawianie ostatniej wylosowanej liczby 2 razy do celów testowych
	tab[n + 1] = 0;
	return n + 2; //zwracanie wielkości tablicy
}

int main()
{
	double tab[1000];
	int n = generate(tab);

	for (int i = 0; i < n; i++) {
	printf("%.3e ", tab[i]);
	if ((i + 1) % 10 == 0)
		printf("\n");
}
	printf("\n\n");

	sortQuick(tab, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%.3e ", tab[i]);
		if ((i+1) % 10 == 0)
			printf("\n");
	}

//	printf("\n%i", n);
	printf("\n");
	system("pause");
    return 0;
}

