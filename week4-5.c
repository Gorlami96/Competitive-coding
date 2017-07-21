#include<stdio.h>

int binarySearch(int arr[],int l,int r,int target){
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==target){
            return m;
        }
        else if(arr[m]>target){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return -1;
}

int findPivot(int arr[],int l,int r){
    if(l==r){
        return l;
    }
    if(l<r){
        int m=(l+r)/2;
        if(arr[m]>arr[m+1]){
            return m;
        }
        if(arr[m]<arr[m-1]){
            return m-1;
        }
        if(arr[l]>arr[m]){
            return findPivot(arr,l,m-1);
        }
        return findPivot(arr,m+1,r);
    }
    return -1;
}

void main(){
    int n,i,target;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&target);
    int pivot=findPivot(arr,0,n-1);
    if(arr[pivot]==target){
        printf("%d",pivot);
    }
    else if(target>=arr[0]){
        printf("%d",binarySearch(arr,0,pivot-1,target));
    }
    else{
        printf("%d",binarySearch(arr,pivot+1,n-1,target));
    }
    return 0;
}