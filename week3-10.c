#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE * sample;
    FILE * result;
	sample=fopen("sample.txt","r");
	result=fopen("result.txt","w+");
	char sent1[500],sent2[500];
	int count=0;
    while(1){
        count++;
        fgets(sent1,500,sample);
        count++;
        fgets(sent2,500,sample);
        fputs(sent2,result);
        fputs(sent1,result);
        strcpy(sent2,"");
        char ch1=fgetc(sample);
        ungetc(ch1,sample);
        if(ch1==EOF){
            break;
        }
    }
    fclose(sample);
    fclose(result);
    sample=fopen("sample.txt","w+");
    result=fopen("result.txt","r");
    char ch1=fgetc(result);
    while(ch1!=EOF){
        fputc(ch1,sample);
        ch1=fgetc(result);
    }
    return 0;
}
