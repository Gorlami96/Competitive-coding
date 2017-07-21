#include <stdio.h>
#include <string.h>
int main()
{
    FILE * fp;
    fp=fopen("sample.txt","r");
    int disp_lines=0;
    scanf("%d",&disp_lines);
    int line_count=1;
    if(disp_lines){
        char ch1=fgetc(fp);
        while(ch1!=EOF){
            if(line_count<=disp_lines){
                printf("%c",ch1);
            }
            else
                break;
            if(ch1=='\n')
                line_count++;
            ch1=fgetc(fp);
        }
    }
    else{
        char ch1=fgetc(fp);
        while(ch1!=EOF){
            if(line_count<=10){
                printf("%c",ch1);
            }
            else
                break;
            if(ch1=='\n')
                line_count++;
            ch1=fgetc(fp);
        }
    }
    return 0;
}
