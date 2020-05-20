#include <stdlib.h>
#include "sorting.h"

void SelectionSort(int N, int array[]) {
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

void InsertionSort(int N, int array[]) {
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

void BubbleSort(int N, int array[]) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++)
			if (array[j] > array[j + 1]) {
				int x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
	}
}

void Merge(int array[], int left, int mid, int right) {
	int size_left = mid - left + 1;
	int size_right = right - mid;

	int* array_left = (int*)malloc(size_left * sizeof(int));
	for (int i = 0; i < size_left; i++)
		array_left[i] = array[left + i];

	int* array_right = (int*)malloc(size_right * sizeof(int));
	for (int i = 0; i < size_right; i++)
		array_right[i] = array[mid + 1 + i];

	int i = 0, j = 0;
	int k = left;
	while (i < size_left && j < size_right) {
		if (array_left[i] <= array_right[j]) {
			array[k] = array_left[i];
			i++;
		}
		else {
			array[k] = array_right[j];
			j++;
		}
		k++;
	}

	while (i < size_left) {
		array[k] = array_left[i];
		i++;
		k++;
	}

	while (j < size_right) {
		array[k] = array_right[j];
		j++;
		k++;
	}

	free(array_right);
	free(array_left);
}

void MergeSort(int array[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}

int CompareNumber(const void* first, const void* second) {
	int x = *((int*)first),
		y = *((int*)second);

	if (x == y) return 0;
	else if (x < y) return -1;
	else return 1;
}

void BucketSort(int array[], int N) {

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
		qsort(buckets[i].value, buckets[i].count, sizeof(int), &CompareNumber);
		for (j = 0; j < buckets[i].count; j++)
			array[k + j] = buckets[i].value[j];

		k += buckets[i].count;
		free(buckets[i].value);
	}
}

void QuickSort(int array[], int first, int last) {
	if (first < last) {
		int left = first, right = last;
		int pivot = array[(left + right) / 2];
		do {
			while (array[left] < pivot) left++;
			while (array[right] > pivot) right--;
			if (left <= right) {
				int tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		QuickSort(array, first, right);
		QuickSort(array, left, last);
	}
}