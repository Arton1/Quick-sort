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
	pivot = tab[(first + last) / 2];

	swap(&tab[(first + last) / 2], &tab[last]);

	while (i < last) {
		if (tab[i] >= pivot)
			i++;
		else {
			swap(&tab[i], &tab[j]);
			j++;
			i++;
		}
	}

	swap(&tab[j], &tab[last]);

	sortQuick(tab, first, j-1);
	sortQuick(tab, j+1, last);
}

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int generate(double tab[]) {
	int n, w, negative, i, j;
	double x;
	srand(time(NULL));
	n = rand();
	n = (n*n) % 999;
	for (j = 0; j < n; j++) {
		negative = rand() % 2;
		do {
			x = rand() % 100;
		} while (x == 0.0);

		w = rand() % 15;
		x = x*x*x;
		x = (int)x % 1000000;
		while (!(x > 0 && x < 10))
			x = x / 10;
		for (i = 0; i < w; i++) {
			x = x * 10;
		}
		if (negative == 1)
			x = -x;
		tab[j] = x;
	}
	tab[n] = x;
	tab[n + 1] = x;
	return n + 2;
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

