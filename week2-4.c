#include <stdio.h>

int main()
{
    char str[1000],str1[1000];
    scanf("%[^\n]%*c",str);
    int k;
    scanf("%d",&k);
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            str1[j++]=str[i];
        }
        i++;
    }
    int cols=(j%k==0)?(j/k):((j/k)+1);
    char cipher[k][cols];
    int r,c,count=0;
    for(c=0;c<cols;c++){
        for(r=0;r<k;r++){
            if(c*k+r+1==j+1){
                break;
            }
            cipher[r][c]=str1[count++];
        }
        if(c*k+r+1==j+1){
            break;
        }
    }
    for(r=0;r<k;r++){
        for(c=0;c<cols;c++){
            printf("%c ",cipher[r][c]);
        }
        printf("\n");
    }
    return 0;
}
