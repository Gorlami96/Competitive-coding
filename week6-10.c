#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
}*head;

struct node * newnode(int value){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
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

static void reverse(struct node ** head){
    struct node * prev=NULL;
    struct node * curr=*head;
    struct node * next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

int main(){
    head=NULL;
    struct node * a=NULL;
    InsertAtBeg(&a,15);
    InsertAtBeg(&a,10);
    InsertAtBeg(&a,5);
    InsertAtBeg(&a,9);
    print(a);
    reverse(&a);
    print(a);
    return 0;
}
