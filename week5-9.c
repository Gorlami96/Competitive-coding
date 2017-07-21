#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(i=0;i<n2;i++){
        R[i]=arr[m+i+1];
    }
    i=0;j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]%10<=R[j]%10){
            arr[k]=L[i++];
        }
        else{
            arr[k]=R[j++];
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[]={ 7, 62, 5, 57, 12, 39, 5, 8, 16, 48 };
    mergeSort(arr,0,9);
    int i;
    for(i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
