#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "benchmark.h"

#define SIZE_ARR_TEST_1 9999
#define SIZE_ARR_TEST_2 1000
#define SIZE_ARR_TEST_3 2000

TIMER clockk;

void PrintTable() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 8));

	printf("                                    ");
	printf("Time on\n");
	printf("Sort Name");
	printf("              ");
	printf("Data 1");
	printf("        ");
	printf("Data 2");
	printf("        ");
	printf("Data 3");
	printf("\n---------------------------------------------------------\n");

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
}

void PrintNameSort(int name) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));

	char* name_sort[5] = { "Selection sort", "Insertion sort", "Bubble sort", "Merge sort", "Bucket sort" };
	printf(name_sort[name]);

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
}

void PrintTimeData1(const TIMER* t, int sort) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 6));

	char* name_sort[5] = { "         ", "         ", "            ", "             ", "             " };
	float array = t->finish - t->start;
	printf(name_sort[sort]);
	printf("%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	printf("ms");

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
}

void PrintTimeData2(const TIMER* t, int sort) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 5));

	char* name_sort[5] = { "         ", "         ", "         ", "         ", "         " };
	float array = t->finish - t->start;
	printf(name_sort[sort]);
	printf("%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	printf("ms");

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
}

void PrintTimeData3(const TIMER* t, int sort) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));

	char* name_sort[5] = { "          ", "          ", "          ", "          ", "          " };
	float array = t->finish - t->start;
	printf(name_sort[sort]);
	printf("%.0f ", (array / CLOCKS_PER_SEC) * 1000);
	printf("ms");

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
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

	Sleep(600);
	if (data == 1) PrintTimeData1(&clockk, choice);
	if (data == 2) PrintTimeData2(&clockk, choice);
	if (data == 3) PrintTimeData3(&clockk, choice);
}