#include <stdio.h>
#include <stdlib.h>

int length=0;

void printHeap(int heap[]){
	int i;
	for(i=1;i<=length;i++){
		printf("%d ",heap[i]);
	}
}

void max_heapify(int arr[],int i){
	int left=2*i;
	int right=2*i+1;
	int largest=i;
	if(left<=length&&arr[left]>arr[i]){
		largest=left;
	}
	if(right<=length&&arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest);
	}
	return ;
}

int extractMax(int heap[]){
	int temp=heap[1];
	//printf("swapped with %d\n",heap[length]);
	heap[1]=heap[length--];
	printf("%d\n",heap[1]);
	max_heapify(heap,1);
	return temp;
}

void Klargest(int heap[],int k){
	int temp[length+1],i;
	for(i=1;i<=length;i++){
		temp[i]=heap[i];
	}
	int kth;
	for(i=0;i<k;i++){
	    kth=extractMax(temp);
	}
	printf("%d\n",kth);
}

void Insert(int heap[],int value){
	length=length+1;
	heap[length]=value;
	int i=length;
	while(i>1&&heap[i]>heap[i/2]){
		int temp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=temp;
		i=i/2;
	}
}

int main(){
	int arr[1000];
	Insert(arr,56);
	Insert(arr,299);
	Insert(arr,35);
	Insert(arr,45);
	printf("%d\n",extractMax(arr));
	printHeap(arr);
	Klargest(arr,3);
}