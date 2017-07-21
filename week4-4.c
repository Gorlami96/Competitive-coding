#include <stdio.h>
#include <time.h>

int binarySearch(int arr[],int l,int r,int key){
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]>key){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return -1;
}

int ternary_search(int ar[],int l,int r,int x){
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(ar,l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(ar,mid2+1,r,x);
        else
            return ternary_search(ar,mid1+1,mid2-1,x);

    }
    return -1;
}

int count=0;

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
            coutn+=m-l+1;
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
    /*srand(time(NULL));
    for(i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    int key=rand()%n;
    clock_t start,end;
    double time_taken;*/
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    /*start=clock();
    int index=binarySearch(arr,0,n-1,arr[key]);
    end=clock();
    printf("binary search index - %d\n",index);
    time_taken=((double)(end-start))/CLOCKS_PER_SEC ;
    printf("time taken by binary search is - %f ", time_taken);
    printf("\n");
    start=clock();
    index=ternary_search(arr,0,n-1,arr[key]);
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC ;
    printf("ternary search index - %d\n",index);
    printf("time taken by ternary search is - %f ", time_taken);*/
    printf("%d",count);
    return 0;
}
