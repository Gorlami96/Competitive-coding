#include <stdlib.h>

int main()
{
    FILE * fp;
    char ch1=NULL;
    char ch2=NULL;
    fp=fopen("sample.c","r");
    if(fp==NULL){
        printf("Error in opening file!");
        return 0;
    }
    ch1=fgetc(fp);
    int flag=0;
    while(ch1!=EOF){
        ch2=ch1;
        ch1=fgetc(fp);
        if(ch1=='/'){
            flag=1;
        }
        if(ch1=='/'&&ch2=='/'){
            ch1=fgetc(fp);
            while(ch1!='\n'){
                ch2=ch1;
                ch1=fgetc(fp);
            }
            flag=0;
            printf("\n");
        }
        else if(ch1=='/'&&ch2=='*'){
            flag=0;
        }
        else if(flag==0){
            printf("%c",ch1);
        }
    }
    return 0;
}