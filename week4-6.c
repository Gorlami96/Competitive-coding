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

int binarySearch(int arr[],int l,int r,int target){
    int m;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]==target){
            return 1;
        }
        else if(arr[m]>target){
            return binarySearch(arr,l,m-1,target);
        }
        else{
            return binarySearch(arr,m+1,r,target);
        }
    }
    return 0;
}

int main()
{
    int n,i,x;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    /*for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }*/
    int  found=0;
    for(i=0;i<n;i++){
        int target=x-arr[i];
        if(target>=x){
            found=binarySearch(arr,i+1,n-1,target);
        }
        else{
            found=binarySearch(arr,0,i-1,target);
        }
        if(found==1){
            break;
        }
    }
    if(found==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
