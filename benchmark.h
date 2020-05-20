#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef struct timer {
	double start, finish;
}TIMER;

void PrintTable();
void PrintNameSort(int sort_name);
void Benchmark(int sort_name, int* array, int data, int size);

#endif //!BENCHMARK_H