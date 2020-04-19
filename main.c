#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"
#include "benchmark.h"

#define SIZE_ARR 9999

int main() {

	int sort_array[SIZE_ARR] = { 0 };
	int const_array[SIZE_ARR] = { 0 };

	srand(time(0));
	for (int i = 0; i < SIZE_ARR; i++) {
		sort_array[i] = rand() % 1001 + 0;
		const_array[i] = sort_array[i];
	}

	PrintTable(); 

	for (int i = 0; i < 5; i++) {
		Sleep(600);
		PrintNameSort(i);
		for (int j = 0; j < 3; j++) {
			Benchmark(i, sort_array, j);

			for (int k = 0; k < SIZE_ARR; k++)
				sort_array[k] = const_array[k];
		}
		printf("\n");
	}
	return 0;
}