#include <stdio.h>

int length=0;

void MinHeapify(int arr[],int i){
    int l=2*i;
    int r=2*i+1;
    int smallest=i;
    if(l<=length&&arr[l]<arr[i]){
        smallest=l;
    }
    if(r<=length&&arr[r]<arr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        MinHeapify(arr,smallest);
    }
}

void Insert(int arr[],int value){
    length=length+1;
    arr[length]=value;
    int i=length;
    while(i>1&&arr[i/2]>arr[i]){
        int temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }
}

void MinHeap(int arr[],int n){
    int i=n/2;
    while(i>=1){
        MinHeapify(arr,i);
    }
}

void Delete(int arr[],int element){
    int i;
    for(i=1;i<length;i++){
        if(arr[i]==element)
            break;
    }
    arr[i]=arr[length];
    length--;
    MinHeapify(arr,i);
}

void printArr(int arr[]){
    int i;
    for(i=1;i<=length;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[100];
    Insert(arr,7);
    Insert(arr,4);
    Insert(arr,3);
    Insert(arr,1);
    Delete(arr,7);
    printArr(arr);
}
