#include <stdio.h>



int main()
{
    int matrix[6][6];
    int transpose[6][6];
    int i,j;
    int temp;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
                transpose[j][i]=matrix[i][j];
        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(transpose[i][j]!=0){
                printf("%d %d %d\n",i,j,transpose[i][j]);
            }
        }
    }
    return 0;
}
