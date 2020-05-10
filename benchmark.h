#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct timer {
	double start, finish;
}TIMER;

void PrintTable();
void PrintNameSort(int name);
void PrintTimeData(const TIMER* t, int sort, int data);
void Benchmark(int choice, int* array, int data, int size_arr);

#endif //!BENCHMARK_H