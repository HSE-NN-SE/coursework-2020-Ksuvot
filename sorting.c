#include "sorting.h"
#include "benchmark.h"
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void Selection_sort(int N, int array[]) {
	for (int i = 0; i < N; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++)
			if (array[min] > array[j])
				min = j;
		int x = array[min];
		array[min] = array[i];
		array[i] = x;
	}
}

void Insertion_sort(int N, int array[]) {
	for (int i = 1; i < N; i++) {
		int x = array[i];
		int j = i - 1;
		while ((j >= 0) && (x < array[j])) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}

void Bubble_sort(int N, int array[]) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++)
			if (array[j] > array[j + 1]) {
				int x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
	}
}

void Merge_sort(int array[], int left, int right) {
	if (left == right) return;

	int mid = (left + right) / 2;
	Merge_sort(array, left, mid);
	Merge_sort(array, mid + 1, right);

	int i = left;
	int j = mid + 1;
	int* tmp = (int*)malloc(right * sizeof(int));
	for (int step = 0; step < right - left + 1; step++) {
		if ((j > right) || ((i <= mid) && (array[i] < array[j]))) {
			tmp[step] = array[i];
			i++;
		}
		else {
			tmp[step] = array[j];
			j++;
		}
	}
	for (int step = 0; step < right - left + 1; step++)
		array[left + step] = tmp[step];
}

int Compare_number(const void* first, const void* second)
{
	int x = *((int*)first),
		y = *((int*)second);

	if (x == y) return 0;
	else if (x < y) return -1;
	else return 1;
}

void Bucket_sort(int array[], int N) {

	BUCKET buckets[3];
	int i, j, k;
	for (i = 0; i < 3; i++) {
		buckets[i].count = 0;
		buckets[i].value = (int*)malloc(sizeof(int) * N);
	}

	for (i = 0; i < N; i++) {
		if (array[i] < 301) buckets[0].value[buckets[0].count++] = array[i];
		else if (array[i] > 600) buckets[2].value[buckets[2].count++] = array[i];
		else buckets[1].value[buckets[1].count++] = array[i];
	}

	for (k = 0, i = 0; i < 3; i++) {
		qsort(buckets[i].value, buckets[i].count, sizeof(int), &Compare_number);
		for (j = 0; j < buckets[i].count; j++)
			array[k + j] = buckets[i].value[j];

		k += buckets[i].count;
		free(buckets[i].value);
	}
}
