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

struct node * reverse(struct node * head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    struct node *remaining=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return remaining;
}

int main(){
    head=NULL;
    struct node * a=NULL;
    InsertAtBeg(&a,15);
    InsertAtBeg(&a,10);
    InsertAtBeg(&a,5);
    InsertAtBeg(&a,9);
    print(a);
    print(reverse(a));
    return 0;
}
