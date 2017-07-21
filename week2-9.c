#include <stdio.h>
#include <string.h>

int n;

int first_occurence(char names[][50],int l,int r,char target[]){
    while(r>=l){
        int mid=(l+r)/2;
        if((mid==0||(strcmp(target,names[mid-1])>0))&&(strcmp(target,names[mid])==0)){
            return mid;
        }
        else if(strcmp(target,names[mid])>0){
            return first_occurence(names,(mid+1),r,target);
        }
        else{
            return first_occurence(names,l,(mid-1),target);
        }
    }
}

int last_occurence(char names[][50],int l,int r,char target[]){
    if(r >= l)
  {
    int mid = (l + r)/2;  
    if( ( mid == n-1 || (strcmp(target,names[mid+1]))<0) &&strcmp(target,names[mid])==0)
      return mid;
    else if(strcmp(target,names[mid])<0)
      return last_occurence(names,l, (mid -1), target);
    else
      return last_occurence(names, (mid + 1),r,target);      
  }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    char names[n][50];
    for(i=0;i<n;i++){
        scanf("%s",names[i]);
    }
    int index;
    char temp[50];
    for(i=0;i<n-1;i++){
        index=i;
        for(j=i+1;j<n;j++){
            if(strcmp(names[j],names[index])<0){
                index=j;
            }
        }
        strcpy(temp,names[i]);
        strcpy(names[i],names[index]);
        strcpy(names[index],temp);
    }
    /*for(i=0;i<n;i++){
        printf("%s\n",names[i]);
    }*/
    char target[50];
    scanf("%s",target);
    int first=first_occurence(names,0,n-1,target);
    int last=last_occurence(names,0,n-1,target);
    printf("%d",last-first+1);
    return 0;
}
