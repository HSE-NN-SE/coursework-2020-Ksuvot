#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "benchmark.h"

#define SIZE_ARR_TEST_1 9999
#define SIZE_ARR_TEST_2 1000
#define SIZE_ARR_TEST_3 2000

void CreateArray(FILE* test, int* const_array) {
	short int num[3] = { 0 };
	short int in_arr = 0, in_num = 0;
	num[0] = num[1] = num[2] = -1;
	while (!feof(test)) {
		char x = fgetc(test);
		if ((int)x != 32) {
			num[in_num] = (int)x - 48;
			++in_num;
		}
		else {
			int zero = 1;
			for (int i = 2; i > -1; i--) {
				if (num[i] != -1) {
					const_array[in_arr] += zero * num[i];
					zero *= 10;
				}
			}
			++in_arr;
			in_num = 0;
			num[0] = num[1] = num[2] = -1;
		}
	}
	fclose(test);
}

int main() {
	
	FILE* test_1 = fopen("test1.txt", "r");
	FILE* test_2 = fopen("test2.txt", "r");
	FILE* test_3 = fopen("test3.txt", "r");
	if ((test_1 == NULL) || (test_2 == NULL) || (test_3 == NULL)) {
		printf("\x1B[31mWRONG!\033[0m");
		return -1;
	}

	int *const_array_test_1 = (int*)malloc(SIZE_ARR_TEST_1 * sizeof(int));
	int *array_test_1 = (int*)malloc(SIZE_ARR_TEST_1 * sizeof(int));
	int *const_array_test_2 = (int*)malloc(SIZE_ARR_TEST_2 * sizeof(int));
	int *array_test_2 = (int*)malloc(SIZE_ARR_TEST_2 * sizeof(int));
	int *const_array_test_3 = (int*)malloc(SIZE_ARR_TEST_3 * sizeof(int));
	int *array_test_3 = (int*)malloc(SIZE_ARR_TEST_3 * sizeof(int));

	CreateArray(test_1, const_array_test_1);
	for (int i = 0; i < SIZE_ARR_TEST_1; i++)
		array_test_1[i] = const_array_test_1[i];

	CreateArray(test_2, const_array_test_2);
	for (int i = 0; i < SIZE_ARR_TEST_2; i++)
		array_test_2[i] = const_array_test_2[i];

	CreateArray(test_3, const_array_test_3);
	for (int i = 0; i < SIZE_ARR_TEST_3; i++)
		array_test_3[i] = const_array_test_3[i];

	PrintTable(); 
	for (int i = 0; i < 5; i++) {
		PrintNameSort(i);
		Benchmark(i, array_test_1, 1, SIZE_ARR_TEST_1);
		Benchmark(i, array_test_2, 2, SIZE_ARR_TEST_2);
		Benchmark(i, array_test_3, 3, SIZE_ARR_TEST_3);
		for (int i = 0; i < SIZE_ARR_TEST_1; i++)
			array_test_1[i] = const_array_test_1[i];
		for (int i = 0; i < SIZE_ARR_TEST_2; i++)
			array_test_2[i] = const_array_test_2[i];
		for (int i = 0; i < SIZE_ARR_TEST_3; i++)
			array_test_3[i] = const_array_test_3[i];
		printf("\n");
	}

	free(array_test_1);
	free(const_array_test_1);
	free(array_test_2);
	free(const_array_test_2);
	free(array_test_3);
	free(const_array_test_3);

	return 0;
}