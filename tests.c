#include "tests.h"
#include "sorting.h"
#include <stdlib.h>

void RandomSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = rand() % size + 1;
}

void PartSortTests(int* array, int size) {
	int sizze = rand() % size;
	int* sort_array = (int*)malloc(sizze * sizeof(int));
	for (int i = 0; i < sizze; i++)
		sort_array[i] = rand() % size + 1;
	QuickSort(sort_array, 0, sizze - 1);

	int count = 0;
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (flag == 1) {
			array[i] = rand() % size + 1;
			--count;
			if (count == 0) flag = 0;
		}
		else if (flag == 0) {
			array[i] = sort_array[count];
			++count;
			if (count == sizze) flag = 1;
		}
	}
	free(sort_array);
}

void SwapSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = rand() % size + 1;
	QuickSort(array, 0, size - 1);
	int count = rand() % size;
	for (int i = 0; i < count; i++) {
		int j = rand() % size;
		int k = rand() % size;
		int swap = array[j];
		array[j] = array[k];
		array[k] = swap;
	}
}

void RandInsertSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = i;
	int count = rand() % size;
	for (int i = 0; i < count; i++) {
		int index = rand() % size;
		int value = rand() % size + 1;
		array[index] = value;
	}
}