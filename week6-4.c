#include <stdio.h>

int main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pz=-1,ppz=-1,pmz,max=0;
    for(i=0i;i<n;i++){
        if(arr[i]==0){
            if(i-ppz>max){
                max=i-ppz;
                pmz=pz;
            }
            ppz=pz;
            pz=i;
        }
    }
    if(n-ppz>max){
        max=i-ppz;
        pmz=pz;
    }
    printf("%d",pmz);
    return 0;
}
