// Projekt 2 1I1 - Artur Wyrozębski

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int generate(double tab[]) {
	int n, w, negative, i;
	double x;
	srand(time(NULL));
	n = rand();
	n = (n*n) % 999;
	for (int k = 0; k < n; k++) {
		negative = rand() % 2;
		do {
			x = rand() % 100;
		} while (x == 0.0);

		w = rand() % 35;
		x = x*x*x;
		x = (int)x % 1000000;
		while (!(x > 0 && x < 10))
			x = x / 10;
		for (i = 0; i < w; i++) {
			x = x * 10;
		}
		if (negative == 1)
			x = -x;
		tab[k] = x;
	}
	tab[n] = x;
	tab[n + 1] = x;
	return n+2;
}

void quickSort(double tab[], int s, int e) {
	if (s >= e)
		return;
	int i, j;
	double pivot;
	j = i = s;
	pivot = tab[(s + e) / 2];

	swap(&tab[(s + e) / 2], &tab[e]);

	while (i < e) {
		if (tab[i] >= pivot)
			i++;
		else {
			swap(&tab[i], &tab[j]);
			j++;
			i++;
		}
	}

	swap(&tab[j], &tab[e]);

	quickSort(tab, s, j-1);
	quickSort(tab, j+1, e);
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

	quickSort(tab, 0, n-1);

	for (int i = 0; i < n; i++) {
		printf("%.3e ", tab[i]);
		if ((i+1) % 10 == 0)
			printf("\n");
	}

//	printf("\n%i\n", n);
	printf("\n");
	system("pause");
    return 0;
}

