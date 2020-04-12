#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"
#include "benchmark.h"

#define SIZE 9999

int main() {

	int array[SIZE] = { 0 }; // ������ ������� �����������
	int ARR[SIZE] = { 0 }; // ����������� ������

	srand(time(0)); // ������������ ������ � ��������� �� 0 �� 1000
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 1001 + 0;
		ARR[i] = array[i];
	}

	PrintTable(); 

	for (int i = 0; i < 5; i++) {
		Sleep(700);
		PrintNameSort(i);
		for (int j = 0; j < 3; j++) {
			Benchmark(i, array, j);

			for (int k = 0; k < SIZE; k++) // ���������� �� ��������������� ������
				array[k] = ARR[k];
		}
		printf("\n");
	}
	return 0;
}