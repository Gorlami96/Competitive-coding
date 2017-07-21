#include <stdio.h>

int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    int largest=9;
    int lowest=1;
    printf("%d",lowest);
    lowest-=1;
    for(i=0;i<(n-k+1);i++){
        printf("%d",lowest);
    }
    lowest+=2;
    for(i=0;i<(k-2);i++){
        printf("%d",lowest);
        lowest+=1;
    }
    printf("\n");
    for(i=0;i<(n-k+1);i++){
        printf("%d",largest);
    }
    largest-=1;
    for(i=0;i<(k-1);i++){
        printf("%d",largest);
        largest-=1;
    }
    return 0;
}
