#ifndef SORTING_H
#define SORTING_H

typedef struct bucket {
	int count;
	int* value;
}BUCKET;

void Selection_sort(int N, int array[]);
void Insertion_sort(int N, int array[]);
void Bubble_sort(int N, int array[]);
void Merge_sort(int array[], int left, int right);
int Compare_number(const void* first, const void* second);
void Bucket_sort(int array[], int N);

#endif