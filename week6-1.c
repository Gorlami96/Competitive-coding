#include <stdio.h>
#include <string.h>
struct student{
    char name[20];
    int group;
};

void swap(struct student * a,struct student * b){
    struct student temp=*a;
    *a=*b;
    *b=temp;
}


int main()
{
    int n,i,j;
    scanf("%d",&n);
    struct student list[n];
    for(i=0;i<n;i++){
        scanf("%s",list[i].name);
        scanf("%d",&list[i].group);
    }
    int high=n-1;
    int low=0;
    int mid=0;
    while(mid<=high){
        switch(list[mid].group){
            case 1:
            swap(&list[low++],&list[mid++]);
            break;
            case 2:
            mid++;
            break;
            case 3:
            swap(&list[mid],&list[high--]);
            break;
        }
    }
    for(i=0;i<n;i++){
        printf("%s--%d\n",list[i].name,list[i].group);
    }
    return 0;
}
