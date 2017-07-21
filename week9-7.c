#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int m,n;

struct node{
	int data;
	int i;
	int j;
};

struct MaxHeap{
	struct node * array;
	int capacity;
};

void swap(struct node * x,struct node *y){
	struct node * temp=x;
	*x=*y;
	*y=*temp;
}

void MaxHeapify(struct node * array,int i,int capacity){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<capacity&&array[l].data>array[i].data){
		largest=l;
	}
	if(r<capacity&&array[r].data>array[largest].data){
		largest=r;
	}
	if(largest!=i){
		swap(&array[i],&array[largest]);
		MaxHeapify(array,largest,capacity);
	}
}

struct node getMin(struct MaxHeap * hp){
	return hp->array[0];
}

struct MaxHeap * CreateMaxHeap(struct node Maxheap[],int capacity){
	struct MaxHeap * heap=(struct MaxHeap *)malloc(sizeof(struct MaxHeap));
    heap->capacity=capacity;
    heap->array=Maxheap;
    int i = (capacity)/2;
    while (i>=0)
    {
        MaxHeapify(heap->array,i,capacity);
        i--;
    }
    return heap;
}

void replaceMin(struct MaxHeap * hp,struct node root){
	hp->array[0]=root;
	MaxHeapify(hp->array,0,n);
}

void mergeArrays(int arr[][m]){
	struct node output[n*m];
	int i;
	struct node Maxheap[n];
	for(i=0;i<n;i++){
		Maxheap[i].data=arr[i][0];
		Maxheap[i].i=i;
		Maxheap[i].j=1;
	}
	struct MaxHeap * hp=CreateMaxHeap(Maxheap,n);
	int  count;
	for(count=0;count<n*m;count++){
        struct node root = getMin(hp);
        output[count] = root;
        printf("%d\n",root.data);
        if (root.j < m)
        {
            root.data = arr[root.i][root.j];
            root.j += 1;
        }
        else root.data =  INT_MAX; 
        replaceMin(hp,root);
	}

}

int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	int arr[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	mergeArrays(arr);
}