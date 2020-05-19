#include "tests.h"

void RandomSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = rand() % size + 1;
}

void MiniSortTests(int* array, int size) {
	int count = size / 50;
	int flag = 1;
	for (int i = 0; i < size; i++) {
		if (flag == 1) {
			array[i] = rand() % size + 1;
			--count;
			if (count == 0) flag = 0;
		}
		else if (flag == 0) {
			array[i] = count;
			++count;
			if (count == size / 50) flag = 1;
		}
	}
}

void SwapSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = i;
	for (int i = 0; i < 10; i++) {
		int j = rand() % size;
		int k = rand() % size;
		int swap = array[j];
		array[j] = array[k];
		array[k] = swap;
	}
}

void RepeatSortTests(int* array, int size) {
	for (int i = 0; i < size; i++)
		array[i] = rand() % size + 1;
	for (int i = 0; i < 5; i++) {
		int x = rand() % (size - 500) + 1;
		int repeat = array[x];
		for (int j = x + 1; j < x + 99; j++)
			array[j] = repeat;
	}
}