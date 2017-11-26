#include <stdio.h>

void quickSort(int tab[], int n);
void swap(int *a, int *b);



void quickSort(int tab[], int n) {
	int pivot = tab[n-1];
	int i = 0;
	int j = n - 1;

	while (i < j) {
		while (tab[i] < pivot)
			i++;
		while (tab[j] > pivot)
			j--;
		swap(&tab[i], &tab[j]);

		for (i = 0; i < n; i++)
			printf("%i ", tab[i]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("%i ", tab[i]);
	printf("\n");

//	quickSort(tab, n / 2);

}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int tab[] = { 0, 4, 10, 1, 2, 3, 6, 8, 5 };
	int n = 9;

	quickSort(tab, n);

	system("pause");
    return 0;
}

