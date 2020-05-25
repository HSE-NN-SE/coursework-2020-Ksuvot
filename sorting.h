#ifndef SORTING_H
#define SORTING_H

typedef struct bucket {
	int count;
	int* value;
}BUCKET;

void SelectionSort(int size, int* array);
void InsertionSort(int size, int* array);
void BubbleSort(int size, int* array);
void MergeSort(int* array, int left, int right);
void BucketSort(int* array, int size);
void QuickSort(int* array, int first, int last);

#endif //!SORTING_H