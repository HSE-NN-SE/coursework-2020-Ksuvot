#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "timer.h"
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 9999

TIMER clockk;

void switch_case(int choice, int N, int array[]) {
	switch (choice) {
	case 1:
		clockk.start = clock();
		Selection_sort(N, array, clockk);
		clockk.finish = clock();
		break;

	case 2:
		clockk.start = clock();
		Insertion_sort(N, array);
		clockk.finish = clock();
		break;
	
	case 3:
		clockk.start = clock();
		Bubble_sort(N, array);
		clockk.finish = clock();
		break;

	case 4:
		clockk.start = clock();
		Merge_sort(array, 0, N - 1);
		clockk.finish = clock();
		break;

	case 5:
		clockk.start = clock();
		Bucket_sort(array, N);
		clockk.finish = clock();
		break;

	case 6:
		exit(0);
		break;

	default:
		printf("Unknown command!\n");
		break;
	}
}

int main() {

	int array[SIZE] = { 0 };
	int ARR[SIZE] = { 0 };
	int choice = 0;

	srand(time(0));
	//printf("Starting array:\n");
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 1001 + 0;
		ARR[i] = array[i];
		//printf("%d ", array[i]);
	}

	printf("Please, select a sort:\n");
	printf("**********************\n");
	printf("1)Selection sort\n2)Insertion_sort\n3)Bubble sort\n4)Merge sort\n5)Bucket sort\n6)Exit\n");
	printf("**********************\n");

	while (1) {
		printf("\n\nYour choice = ");
		scanf("%d", &choice);

		switch_case(choice, SIZE, array);

		if (choice < 6) {
			//printf("Sorted array:\n");
			//for (int i = 0; i < SIZE; i++)
				//printf("%d ", array[i]);
			//printf("\n");
			print_time(&clockk);
		}

		for (int i = 0; i < SIZE; i++)
			array[i] = ARR[i];
	}

	return 0;
}