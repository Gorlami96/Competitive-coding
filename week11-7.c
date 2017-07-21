#include <stdio.h>
#include <stdlib.h>

int min(int i,int k){
	return (i>k)?k:i ;
}

int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	printf("%d",binomialCoeff(n,r));
}