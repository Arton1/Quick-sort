#include <stdio.h>

void quickSort(int tab, int n);
void swap(int a, int b);



void quickSort(int tab[], int n) {
	int pivot = tab[n/2];
	int i, j;
	for (i = 0, j = n--; i < j; i++, j--) {
		if (tab[i] > pivot && tab[j] < pivot) {
			swap(&tab[i], &tab[j]);
		}
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
	int tab[] = { 0, 4, 10, 1, 5, 3, 6, 8, 2 };
	int n = 9;

	quickSort(tab, n);

	system("pause");
    return 0;
}

