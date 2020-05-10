#include <stdio.h>
#include <time.h>
#include "benchmark.h"

TIMER clockk;

void PrintTable() {
	printf("\t\t\t\t\t\x1B[1mTime on\n");
	printf("Sort Name");
	printf("\t\tData 1");
	printf("\t\tData 2");
	printf("\t\tData 3");
	printf("\n--------------------------------------------------------------\n\033[0m");
}

void PrintNameSort(int name) {
	char* name_sort[5] = { "Selection sort", "Insertion sort", "Bubble sort   ", "Merge sort    ", "Bucket sort " };
	printf("\x1B[32;1m%s\033[0m", name_sort[name]);
}

void PrintTimeData(const TIMER* t, int sort, int data) {
	char* name_sort[5] = { "\t\t", "\t\t", "\t\t", "\t\t", "\t\t" };
	double array = t->finish - t->start;
	printf(name_sort[sort]);
	if (data == 1) printf("\x1B[33m%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	if (data == 2) printf("\x1B[35m%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	if (data == 3) printf("\x1B[34;1m%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	printf("ms\033[0m");
}

void Benchmark(int choice, int* array, int data, int size_arr) {
	switch (choice) {
	case 0:
		clockk.start = clock();
		SelectionSort(size_arr, array, clockk);
		clockk.finish = clock();
		break;

	case 1:
		clockk.start = clock();
		InsertionSort(size_arr, array);
		clockk.finish = clock();
		break;

	case 2:
		clockk.start = clock();
		BubbleSort(size_arr, array);
		clockk.finish = clock();
		break;

	case 3:
		clockk.start = clock();
		MergeSort(array, 0, size_arr - 1);
		clockk.finish = clock();
		break;

	case 4:
		clockk.start = clock();
		BucketSort(array, size_arr);
		clockk.finish = clock();
		break;

	default:
		break;
	}
	PrintTimeData(&clockk, choice, data);
}