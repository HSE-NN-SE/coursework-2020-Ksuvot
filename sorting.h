#ifndef SORTING_H
#define SORTING_H

typedef struct bucket {
	int count;
	int* value;
}BUCKET;

void SelectionSort(int N, int array[]);
void InsertionSort(int N, int array[]);
void BubbleSort(int N, int array[]);
void MergeSort(int array[], int left, int right);
void BucketSort(int array[], int N);
void QuickSort(int array[], int first, int last);

#endif //!SORTING_H