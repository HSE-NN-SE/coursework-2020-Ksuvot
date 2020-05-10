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
int CompareNumber(const void* first, const void* second);
void BucketSort(int array[], int N);

#endif //!SORTING_H