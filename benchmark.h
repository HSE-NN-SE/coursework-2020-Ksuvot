#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct timer {
	float start;
	float finish;
}TIMER;

void PrintTable();
void PrintNameSort(int name);

//Для каждого набора данных свой вывод
//пока что выводятся 3 прогона на одних и тех же данных
void PrintTimeData1(const TIMER* t, int sort);
void PrintTimeData2(const TIMER* t, int sort);
void PrintTimeData3(const TIMER* t, int sort);

void Benchmark(int choice, int* array, int data);

#endif