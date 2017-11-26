#include <stdio.h>

void quickSort(int* tab, int n);
void swap(double* a, double* b);



void quickSort(int* tab, int n) {
	int pivot = tab[n/2];
	int i, j;
	for (i = 0, j = --n; i-1 < j; i++, j--) {
		if (tab[i] < pivot && tab[j] > pivot) {
			swap(tab[i], tab[j]);
		}
	}

	for (int i = 0; i < n; i++)
		printf("%i ", tab[i]);
	printf("\n");
//	quickSort(tab, n / 2);

}

void swap(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	double tab[] = { 5, 4, 10, 0, 1, 3, 6, 8, 2 };
	int n = 9;

	quickSort(tab, n);

	system("pause");
    return 0;
}

