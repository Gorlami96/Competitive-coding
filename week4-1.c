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

void insertion_sort(struct book books[],int n){
    int i,j;
    struct book key;
   for (i = 1; i < n; i++)
   {
       key=books[i];
       j = i-1;
       while (j >= 0 && books[j].price > key.price)
       {
           books[j+1] = books[j];
           j = j-1;
       }
       books[j+1] = key;
   }
}

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
    int n,i;
    scanf("%d",&n);
    rand_input(fp,n);
    fclose(fp);
    struct book books[n];
    for(i=0;i<n;i++){
        scanf("%s %s %s %d %d %d %d",books[i].name,books[i].author_name,books[i].publication,&books[i].edition,&books[i].ISBN_number,&books[i].publication_year,&books[i].price);
    }
    insertion_sort(books,n);
    printf("\n\n\n");
    for(i=0;i<n;i++){
        printf("%s %s %s %d %d %d %d\n",books[i].name,books[i].author_name,books[i].publication,books[i].edition,books[i].ISBN_number,books[i].publication_year,books[i].price);
    }
    return 0;
}
