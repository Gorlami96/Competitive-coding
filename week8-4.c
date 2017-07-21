#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n,k;

struct Deque
{
    int  arr[INT_MAX];
    int  front;
    int  rear;
    int  size;
};

struct Deque * createDeque(int size){
	struct Deque * temp=(struct Deque *)malloc(sizeof(struct Deque));
	temp->size=size;
	temp->front=-1;
	temp->rear=0;
	return temp;
}	

int isFull(struct Deque * dq)
{
    return ((dq->front == 0 && dq->rear == dq->size-1)||
            dq->front == dq->rear+1);
}
 
int isEmpty (struct Deque * dq)
{
    return (dq->front == -1);
}
 
void insertfront(struct Deque * dq,int key)
{
    if (isFull(dq))
    {
        return;
    }
 
    if (dq->front == -1)
    {
        dq->front = 0;
        dq->rear = 0;
    }
 
    else if (dq->front == 0)
        dq->front = dq->size - 1 ;
 
    else 
        dq->front = dq->front-1;
 
    dq->arr[dq->front] = key ;
}
 

void insertrear(struct Deque * dq,int key)
{
    if (isFull(dq))
    {
        return;
    }
 
    
    if (dq->front == -1)
    {
        dq->front = 0;
        dq->rear = 0;
    }

    else if (dq->rear == dq->size-1)
        dq->rear = 0;
    
    else
        dq->rear = dq->rear+1;

    dq->arr[dq->rear] = key ;
}
 
void deletefront(struct Deque * dq)
{
    
    if (isEmpty(dq))
    {
        return ;
    }
 
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->front == dq->size -1)
        dq->front = 0;
 
    else 
        dq->front = dq->front+1;
}
 

void deleterear(struct Deque * dq)
{
    if (isEmpty(dq))
    {
        return ;
    }
 
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if (dq->rear == 0)
        dq->rear = dq->size-1;
    else
        dq->rear = dq->rear-1;
}
 
int getFront(struct Deque * dq)
{
    
    if (isEmpty(dq))
    {
        return -9999999 ;
    }
    return dq->arr[dq->front];
}
 
int getRear(struct Deque * dq)
{
    if(isEmpty(dq) || dq->rear < 0)
    {
        return -9999999 ;
    }
    return dq->arr[dq->rear];
}

int printKMax(int arr[]){
	struct Deque * dq=createDeque(k);
	int i;
	for(i=0;i<k;i++){
		if(!isEmpty(dq)&&arr[i]>=arr[dq->rear]){
			deletefront(dq);
		}
		insertrear(dq,i);
	}
	//printf("%d",arr[dq->front]);
	for(;i<n;i++){
		printf("%d\n",arr[dq->front]);
		//sum+=arr[dq->front];
		while (!isEmpty(dq) && dq->front <= i - k){
            deletefront(dq); // Remove from front of queue
		}
		if(!isEmpty(dq)&&arr[i]>=arr[dq->rear]){
			deletefront(dq);
		}
		insertrear(dq,i);
	}
	printf("%d\n",arr[dq->front]);
	//sum+=arr[dq->front];
	return sum;	
}

int main(){
	scanf("%d%d",&n,&k);
	int array[n];
	int i;
	for(i=0;i<n;i++){
	    scanf("%d",&array[i]);	
	}
	printf("%d",printKMax(array));
}