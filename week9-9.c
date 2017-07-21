#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeChecker(char str[],int i,int j){
    int h=j;
    int l=i;
    while(h<l){
        if (str[l++] != str[h--])
        {
            return 0;;
        }
    }
    return 1;
}

void  printArray(char arr[],int i,int j){
    int k;
    for(k=i;k<=j;k++){
        printf("%c",arr[k]);
    }
    printf("\n");
}

int main()
{
    int i,j;
    char str[100];
    int count=0;
    scanf("%s",str);
    /*for(i=0;i<strlen(str);i++){
        for(j=strlen(str)-1;j>=i;j--){
            if(palindromeChecker(str,i,j)){
                count++;
                printArray(str,i,j);
                i=j;
                break;
            }
        }
    }*/
    if(palindromeChecker(str,0,strlen(str)-1)){
        printArray(str,0,strlen(str)-1);
    }
    return 0;
}
