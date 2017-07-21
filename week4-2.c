#include <stdio.h>

int Mode(int arr[],int n){
    int max_ele=arr[0];
    int max_count=1;
    int curr_count=1;
    int i;
    for(i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            curr_count++;
        }
        else{
            curr_count=1;
        }
        if(curr_count>max_count){
            max_count=curr_count;
            max_ele=arr[i];
        }
    }
    return max_ele;
}

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
        if(L[i]<=R[j]){
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
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("%d",Mode(arr,n));
    return 0;
}
