// Projekt 2 1I1 - Artur Wyrozębski

#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int tab[], int s, int e) {
	if (s >= e)
		return;
	int i, j, pivot, exists;
	j = i = s;
	pivot = tab[(s + e) / 2];

	printf("pivot = %i, s = %i, e=%i\n", pivot, s, e);
	for (int k = s; k <= e; k++)
		printf("%i ", tab[k]);
	printf("\n");

	swap(&tab[(s + e) / 2], &tab[e]);

	while (i < e) {
		if (tab[i] >= pivot)
			i++;
		else {
			swap(&tab[i], &tab[j]);
			j++;
			i++;
		}
		for (int k = s; k <= e; k++) 
			printf("%i ", tab[k]);
		printf(" j = %i, i = %i \n", j, i);
	}

	swap(&tab[j], &tab[e]);

	for (int k = s; k <= e; k++)
		printf("%i ", tab[k]);
	printf("\n");

	quickSort(tab, s, j-1);
	quickSort(tab, j+1, e);
}

int main()
{
	int tab[] = {
		7, 2, 4, 7, 3, 1, 4, 6, 5, 8, 3, 9, 2, 6, 7, 6, 3
//		7, 5, 4, 3, 6, 1, 9, 10, 8, 2, 22
	};
	int n = 17;

	quickSort(tab, 0, n-1);

	for (int k = 0; k < n; k++)
		printf("%i ", tab[k]);
	printf("\n");

	system("pause");
    return 0;
}

