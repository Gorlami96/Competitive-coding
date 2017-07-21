#include <stdio.h>

void reverse(char arr[],int j,int i){
    char temp;
    int k,l=0;
    for(k=j;k<=(i+j)/2;k++){
        temp=arr[k];
        arr[k]=arr[i-l];
        arr[i-l]=temp;
        l++;
    }
}

int main()
{
    char str[100];
    fgets(str,100,stdin);
    int i=0,j=0;
    while(1){
        if(str[i]==' '){
            reverse(str,j,i-1);
            j=i+1;
        }
        else if(str[i]=='\0'){
            reverse(str,j,i-1);
            break;
        }
        i++;
    }
    reverse(str,0,i-1);
    printf("%s",str);
    return 0;
}
