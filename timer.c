#include <stdio.h>
#include <time.h>
#include "timer.h"
#define _CRT_SECURE_NO_WARNINGS

void print_time(const TIMER* t) {
	float array = t->finish - t->start;
	printf("The time: %.4f ", array / CLOCKS_PER_SEC);
	printf("seconds;");
}