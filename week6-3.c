#include <stdio.h>
#include <string.h>

int n;

struct useful{
    char name[100][50];
    int j;
};

void setBits(int sum,int set[],int i){
    int count=0;
    while(sum){
        sum&=(sum-1);
        count++;
    }
    set[i]=count;
}

int sum(char name[]){
    int sum=0,j=0;
    while(1){
        sum+=name[j];
        j++;
        if(name[j]=='\n'||name[j]=='\0'){
            break;
        }
    }
    return sum;
}

int main()
{
    int i;
    scanf("%d\n",&n);
    char list[n][50];
    int set[n];
    char temp[50];
    struct useful arr[20];
    int sumd;
    
    for(i=0;i<20;i++){
        arr[i].j=0;
    }
    
    for(i=0;i<n;i++){
        fgets(list[i],50,stdin);
        sumd=sum(list[i]);
        setBits(sumd,set,i);
        int k=set[i];
        int l=arr[k].j;
        strcpy(arr[k].name[l],list[i]);
        arr[k].j++;
    }
    
    for(i=0;i<20;i++){
        int temp=arr[i].j;
        int k;
        for(k=0;k<temp;k++){
            printf("%s\n",arr[i].name[k]);
        }
    }
    
    return 0;
}
