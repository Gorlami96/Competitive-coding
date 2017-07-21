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
    return temp;
}

void InsertAtBeg(struct node ** head,int x){
    struct node * temp=newnode(x);
    temp->next=*head;
    *head=temp;
    n++;
}

void InsertAtEnd(struct node ** head,int x){
    struct node *temp=newnode(x);
    if(*head==NULL){
        *head=temp;
    }
    else{
        struct node * Lastnode=*head;
        while(Lastnode->next!=NULL){
            Lastnode=Lastnode->next;
        }
        Lastnode->next=temp;
    }
    n++;
}

void print(struct node * root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}

void reverse(struct node ** head,int m,int l){
    struct node * prev1=NULL;
    struct node * curr=*head;
    int index=1,count=0;
    while(index!=l){
        prev1=curr;
        curr=curr->next;
        index++;
    }
    //printf("%d current\n%d prev",curr->data,prev1->data);
    struct node * curr1=curr;
    struct node * prev=NULL;
    struct node * next;
    while(curr!=NULL&&count!=m){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    prev1->next=prev;
    curr1->next=curr;
}

int main(){
    int m=3,l=2;
    head=NULL;
    InsertAtBeg(&head,7);
    InsertAtBeg(&head,6);
    InsertAtBeg(&head,5);
    InsertAtBeg(&head,4);
    InsertAtBeg(&head,3);
    InsertAtBeg(&head,2);
    InsertAtBeg(&head,1);
    printf("%d\n",n);
    reverse(&head,3,2);
    
    print(head);
    return 0;
}
