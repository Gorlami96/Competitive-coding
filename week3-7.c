#include <stdio.h>

int countLines(FILE * ptr){
    int lines=1;
    char ch1=fgetc(ptr);
    while(ch1!=EOF){
        if(ch1=='\n')
            lines++;
        ch1=fgetc(ptr);
    }
    return lines;
}

int countWords(FILE * ptr){
    int words=0;
    char ch1=fgetc(ptr);
    while(ch1!=EOF){
        if(ch1==' '||ch1=='\t'||ch1=='\n'){
            words++;
        }
        ch1=fgetc(ptr);
    }
    return words;
}

int countChars(FILE * ptr){
    int chars=1;
    char ch1=fgetc(ptr);
    while(ch1!=EOF){
        if(ch1!='\n'){
            chars++;
        }
        ch1=fgetc(ptr);
    }
    return chars;
}

int main()
{
    FILE * ptr;
    ptr=fopen("sample.txt","r");
    if(ptr==NULL){
        printf("error");
    }
    int lines=countLines(ptr);
    rewind(ptr);
    int words=countWords(ptr);
    rewind(ptr);
    int chars=countChars(ptr);
    printf("%d %d %d",lines,words,chars);
    return 0;
}
