#include<stdio.h>
int main(){
    int pf[100];
    int n;
    int i=0;
    scanf("%d",&n);
    while(n%2==0){
        pf[i++]=2;
        n=n/2;
    }
    int j;
    for(j=3;j<n;j=j+2){
        while(n%j==0){
            pf[i++]=j;
            n=n/j;
        }
    }
    if(n>2){
        pf[i++]=n;
    }
    printf("%d",i);
    /*for(j=0;j<i;j++){
        printf("%d",pf[j]);
    }*/
    return 0;
}