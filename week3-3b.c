#include <stdio.h>
#include <string.h>

int main()
{
    FILE * fp;
    fp=fopen("sample.txt","r");
    int line_number=1;
    char str[500];
    char target[100];
    scanf("%s",target);
    //printf("%s",target);
    while(1){
        fgets(str,500,fp);
        char copy[500];
        strcpy(copy,str);
        //printf("%s",str);
        char * token=strtok(copy," ");
        while(1){
            if(!strcmp(token,target)){
                printf("Line number %d-",line_number);
                printf("%s",str);
                break;
            }
            token=strtok(NULL," ");
            //token=strcat(token,"\n");
            //printf("%s",token);
            if(token==NULL){
                break;
            }
        }
        char ch1=fgetc(fp);
        ungetc(ch1,fp);
        if(ch1==EOF){
            break;
        }
        line_number++;
    }
    return 0;
}
