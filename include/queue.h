#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int size;
	int *data;
	int front;
	int rear;
}queue;

bool is_queue_empty(queue *q);
bool is_queue_full(queue *q);
queue * queue_init(int size);
void queue_deinit(queue *q);
bool enque(queue *q, int num);
int dequeue(queue *q);
void print_queue(queue *q);