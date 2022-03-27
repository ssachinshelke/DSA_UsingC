#include "include/queue.h"
 
bool is_queue_empty(queue *q) {
	if (q->front == -1)
		return true;
	return false;
}

bool is_queue_full(queue *q) {
	if (((q->front == 0) && (q->rear == q->size - 1)) ||
		((q->rear + 1) == q->front))
		return true;
	return false;
}

queue * queue_init(int size) {
	queue *q = (queue *)malloc(sizeof(queue));
	q->size = size;
	q->front = q->rear = -1;
	q->data = (int *)malloc(sizeof(int)*size);
	return q;
}

void queue_deinit(queue *q) {
	free(q->data);
	free(q);
}

bool enque(queue *q, int num) {
	if(is_queue_full(q)) {
		printf("\nQUEUE is FULL ...\n");
		return false;
	}
	if (q->front == -1)
		q->front = 0;
	q->rear = (q->rear + 1) % q->size;
	q->data[q->rear] = num;
	
	return true;
}

int dequeue(queue *q) {
	int element;
	if(is_queue_empty(q)) {
		printf("\nQUEUE is Empty ...\n");
		return -1;
	}
	element = q->data[q->front];
	if(q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	} else {
		q->front = (q->front + 1)%q->size;
	}

	return element;
}

void print_queue(queue *q) {
	printf("Queue:");
	for(int i = 0; i < q->size; i++) {
		printf(" %d", q->data[i]);
	}
	printf("\n");
}

/*
int main() {
	queue *q = queue_init(5);
	enque(q,1);
	enque(q,2);
	enque(q,3);
	enque(q,4);
	print_queue(q);
	for(int i=0; i < q->size;i++)
	{
		printf("Dequeue:%d ", dequeue(q));
	}
	printf("\n");
	return 0;
}
*/
