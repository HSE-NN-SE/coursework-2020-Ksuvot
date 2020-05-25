#include <stdio.h>
#include <stdlib.h>
#include "benchmark.h"
#include "tests.h"

#define SIZE_BIG 10000000
#define SIZE_SMALL 100000

enum TEST {
	test1 = 1, test2, test3, test4
};

int main() {
	srand(time(0));
	PrintTable();
	for (int i = 0; i < 6; i++) {
		int size;
		int* array;
		PrintNameSort(i);
		if (i < 3) {
			size = SIZE_SMALL;
			array = (int*)malloc(SIZE_SMALL * sizeof(int));
		}
		else {
			size = SIZE_BIG;
			array = (int*)malloc(SIZE_BIG * sizeof(int));
		}
		RandomSortTests(array, size);
		Benchmark(i, array, test1, size);	//	1
		PartSortTests(array, size);
		Benchmark(i, array, test2, size);	//	2
		SwapSortTests(array, size);
		Benchmark(i, array, test3, size);	//	3
		RandInsertSortTests(array, size);
		Benchmark(i, array, test4, size);	//	4
		printf("\n");
		free(array);
	}
	return 0;
}