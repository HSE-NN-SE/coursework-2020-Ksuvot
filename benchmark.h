#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct timer {
	float start;
	float finish;
}TIMER;

void PrintTable();
void PrintNameSort(int name);

//��� ������� ������ ������ ���� �����
//���� ��� ��������� 3 ������� �� ����� � ��� �� ������
void PrintTimeData1(const TIMER* t, int sort);
void PrintTimeData2(const TIMER* t, int sort);
void PrintTimeData3(const TIMER* t, int sort);

void Benchmark(int choice, int* array, int data);

#endif