#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "sorting.h"
#include "benchmark.h"

#define SIZE_ARR 9999

int main() {

	int sort_array[SIZE_ARR] = { 0 };
	int const_array[SIZE_ARR] = { 0 };
	short int num[3] = { 0 };
	short int in_arr = 0, in_num = 0;

	FILE* test_1 = fopen("test1.txt", "r");
	if (test_1 == NULL) {
		printf("WRONG!");
		return -1;
	}

	num[0] = num[1] = num[2] = -1;
	while (!feof(test_1)) {
		char x = fgetc(test_1);
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
	fclose(test_1);

	for (int i = 0; i < SIZE_ARR; i++)
		sort_array[i] = const_array[i];

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