#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int tab[], int start, int end) {
	printf("? %i %i\n", start, end);

	if (start == end)
		return;

	int pivot = tab[start];
	int i = start;
	int j = end - 1;
	int k;

	while (i < j) {
		while (tab[i] <= pivot)
			i++;
		while (tab[j] >= pivot)
			j--;
		swap(&tab[i], &tab[j]);

		
	} 

	for (k = start; k < end; k++)
		printf("%i ", tab[k]);
	printf("\n");

	quickSort(tab, start, i);
//	quickSort(tab, j, end);
}

int main()
{
	int tab[] = {
		5,	2,	1,	1,	4,	0,	4,	2,	8,	6,	8,	5,	7,	6,	9
	};
	int n = 15;
	int k = 0;

	quickSort(tab, 0, n);

	for (k = 0; k < n; k++)
		printf("%i ", tab[k]);
	printf("\n");

	system("pause");
    return 0;
}

