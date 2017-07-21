#include<stdio.h>

int findPeak(int arr[],int l,int r,int n){
    int m=(l+r)/2;
    if((m==0||arr[m-1]<=arr[m])&&(m==n-1||arr[m+1]<=arr[m])){
        return m;
    }
    else if(m>0&&arr[m-1]>arr[m]){
        return findPeak(arr,l,m-1,n);
    }
    else{
        return findPeak(arr,m+1,r,n);
    }
}

void main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
    printf("%d",findPeak(arr,0,n-1,n));
    return 0;
}