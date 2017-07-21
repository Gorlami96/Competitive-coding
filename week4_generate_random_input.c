#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct book{
    char name[100];
    char author_name[100];
    char publication[100];
    int edition;
    int ISBN_number;
    int price;
    int publication_year;
};

void rand_input(FILE * fp,int n){
    char alpha[26];
    int i,j;
    srand(time(NULL));
    strcpy(alpha,"abcdefghijklmnopqrtsuvwxyz");
    int length;
    char space=' ';
    char newline='\n';
    for(i=0;i<n;i++){
        length=rand()%20+1;
        for(j=0;j<length;j++){
            fprintf(fp,"%c",alpha[rand()%26]);
        }
        fputc(space,fp);

        length=rand()%20+1;
        for(j=0;j<length;j++){
            fprintf(fp,"%c",alpha[rand()%26]);
        }
        fputc(space,fp);

        length=rand()%20+1;
        for(j=0;j<length;j++){
            fprintf(fp,"%c",alpha[rand()%26]);
        }
        fputc(space,fp);
        fprintf(fp,"%d %d %d %d",rand()%10000,rand()%10000,rand()%10000,rand()%10000);
        fputc(newline,fp);
    }
}

int main()
{
    FILE * fp;
    fp=fopen("sample.txt","w");
    int n;
    scanf("%d",&n);
    rand_input(fp,n);
    return 0;
}
