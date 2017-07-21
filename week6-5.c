#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    char L[n1],R[n2];
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

void mergeSort(char arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}



int main()
{
    FILE * ptr;
    ptr=fopen("sample.txt","r");
    char names[100][50];
    int n=0,i,j,index;
    while(!feof(ptr)){
        fgets(names[n],50,ptr);
        strtok(names[n],"\n");
        n++;
    }
    char temp[50];
    for(i=0;i<n-1;i++){
        index=i;
        for(j=i+1;j<n;j++){
            if(strcmp(names[j],names[index])<0){
                index=j;
            }
        }
        strcpy(temp,names[i]);
        strcpy(names[i],names[index]);
        strcpy(names[index],temp);
    }
    char arr[n][50];
    for(i=0;i<n;i++){
        strcpy(temp,names[i]);
        mergeSort(temp,0,strlen(temp)-1);
        //printf("%s %s \n",temp,names[i]);
        strcpy(arr[i],temp);
    }
    char temp2[50];
    for(i=0;i<n-1;i++){
        index=i;
        for(j=i+1;j<n;j++){
            if(strcmp(arr[j],arr[index])<0){
                index=j;
            }
        }
        strcpy(temp,arr[i]);
        strcpy(temp2,names[i]);
        strcpy(arr[i],arr[index]);
        strcpy(names[i],names[index]);
        strcpy(arr[index],temp);
        strcpy(names[index],temp2);
    }
    for(i=0;i<n;i++){
        printf("%s %s \n",arr[i],names[i]);
    }
    return 0;
}
