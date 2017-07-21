#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_perm(char str[],int size){
    int i=size-1;
    int temp;
    while(i>0&&str[i-1]>=str[i]){
        i--;
    }
    if(i==0)
        return 0;
    int j = size - 1;
    while (str[j] <= str[i - 1])
        j--;
    temp = str[i - 1];
    str[i - 1] = str[j];
    str[j] = temp;

    // Reverse suffix
    j = size - 1;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int main()
{
    int n,a;
    scanf("%d",&n);
    for(a=0;a<n;a++){
        char str[100];
        scanf("%s",str);
        int check=next_perm(str,strlen(str));
        if(check==1){
            printf("%s",str);
        }
        else{
            printf("game terminated");
        }
    }
    return 0;
}
