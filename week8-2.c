#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int capacity;
	int front;
	int rear;
	int size;
	int * array;
}

struct Queue * createQueue(int capacity){
	struct Queue * queue=(struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity=capacity;
	queue->size=0;
	queue->front=-1;
	queue->rear=capacity-1; 
	queue->array=(int *)malloc(sizeof(int)*capacity);
	return queue;
}

int isFull(struct Queue * queue){
	return (queue->size==queue->capacity);
}

int isEmpty(struct Queue * queue){
	return(queue->size==0);
}

void enqueue(struct Queue * queue){
	if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

void dequeue(struct Queue * queue){
	if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void push(struct Queue * queue1,struct Queue * queue2){
	
}

int main(){

} 