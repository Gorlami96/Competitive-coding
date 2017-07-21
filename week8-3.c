#include <stdio.h>
#include <stdlib.h>

int l=0;

void max_heapify(int arr[],int i){
	int left=2*i;
	int right=2*i+1;
	int largest=i;
	if(left<=l&&arr[left]>arr[i]){
		largest=left;
	}
	if(right<=l&&arr[right]>largest){
		largest=right;
	}
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest);
	}
}

void InsertEle(int arr[],int x){
	l=l+1;
	arr[l]=x;
    int i=l;
    while(i>1&&arr[i/2]<arr[i]){
    	int temp=arr[i];
    	arr[i]=arr[i/2];
    	arr[i/2]=temp;
    	i=i/2;
    }
}

void deleteMax(int arr[]){
	if(l>=1){
		arr[1]=arr[l];
	    l=l-1;
	    max_heapify(arr,1);
	}
	else{
		printf("Underflow!");
	}
}

int maxEle(int arr[]){
	return arr[1];
}

void print(int arr[]){
	int i=0;
	for(i=1;i<=l;i++){
		printf("%d\n",arr[i]);
	}
}

int main(){
	int arr[1000];
	int choice;
	while(1){
		printf("Please enter choice - ");
		scanf("%d",&choice);
		if(choice==1){
			int temp;
			scanf("%d",&temp);
			InsertEle(arr,temp);
			print(arr);
		}
		else if(choice==2){
			deleteMax(arr);
			print(arr);
		}
		else if(choice==3){
			printf("%d\n",maxEle(arr));
		}
		else{
			break;
		}
	}
    return 0;
}