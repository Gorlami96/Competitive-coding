#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    int i,j,k;
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    i=0,j=0,k=l;
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

int countTriplets(int arr[],int n){
    int count=0,i,l,r;
    for(i=2;i<n;i++){
        l=0;
        r=i-1;
        while(l<r){
            if((arr[l]+arr[r])==arr[i]){
                count++;
                l++;
            }
            else if((arr[l]+arr[r])<arr[i]){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return count;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int count;
    mergeSort(arr,0,n-1);
    printf("%d",countTriplets(arr,n));
    return 0;
}
