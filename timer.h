#ifndef TIMER_H
#define TIMER_H

typedef struct timer {
	float start;
	float finish;
}TIMER;

typedef struct bucket{
	int count;
	int* value;
}BUCKET;

void print_time(const TIMER* t);

#endif