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

int accepted(int arr[],int x,int n,int c){
    int prev=arr[0],i;
    int count=1;
    for(i=1;i<n;i++){
        if((arr[i]-prev)>=x){
            count++;
            prev=arr[i];
        }
    }
    if(count>=c){
        return 1;
    }
    else{
        return 0;
    }
}

int findMin(int arr[],int l,int r,int n,int c){
    if(l<=r){
        int m=(l+r)/2;
        if(accepted(arr,m,n,c)&&!accepted(arr,m+1,n,c)){
            return m;
        }
        else if(accepted(arr,m,n,c)){
            return findMin(arr,m+1,r,n,c);
        }
        else{
            return findMin(arr,l,m-1,n,c);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,c,i;
        scanf("%d%d",&n,&c);
        int arr[n];
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        mergeSort(arr,0,n-1);
        printf("%d", findMin(arr, 1,arr[n-1]-arr[0] , n, c));
    }
    return 0;
}
