#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
}*head;

int n=0;

struct node * newnode(int value){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    n++;
    return temp;
}

void InsertAtBeg(struct node ** head,int x){
    struct node * temp=newnode(x);
    temp->next=*head;
    *head=temp;
}


void print(struct node * root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}

int checkPalindrome(struct node * head){
    int arr[n];
    int i=0;
    struct node * temp =head;
    while(temp!=NULL){
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }
    int flag=0;
    for(i=0;i<n/2;i++){
        if(arr[i]!=arr[n-1-i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    head=NULL;
    char c='y';
    char t[4];
    while(c=='y'){
        int temp;
        scanf("%d\n",&temp);
        InsertAtBeg(&head,temp);
        scanf("%c",&c);
    }
    if(checkPalindrome(head)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    print(head);
    return 0;
}
