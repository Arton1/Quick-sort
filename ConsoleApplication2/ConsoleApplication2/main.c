#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort1(int tab[], int start, int end) {
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

void quickSort(int tab[], int s, int e) {
	int i, j, pivot;
	j = i = s;
	pivot = tab[(s + e) / 2];
	swap(&tab[(s + e) / 2], &tab[e]);

	while (i <= e) {
		while (tab[i] >= pivot)
			i++;
		swap(&tab[i], &tab[j]);
		j++;
		i++;
	}

	swap(&tab[j], &tab[e]);

}

int main()
{
	int tab[] = {
		7, 2, 4, 7, 3, 1, 4, 6, 5, 8, 3, 9, 2, 6, 7, 6, 3
	};
	int n = 17;
	int k = 0;

	quickSort(tab, 0, n-1);

	for (k = 0; k < n; k++)
		printf("%i ", tab[k]);
	printf("\n");

	system("pause");
    return 0;
}

