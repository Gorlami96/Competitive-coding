#include <stdio.h>

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
}

void print(struct node * root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}

void Insert(struct node ** head,int y,int x){
    struct node * temp=newnode(x);
    struct node * cur=*head;
    while(cur->next->data!=y){
        cur=cur->next;
    }
    temp->next=cur->next;
    cur->next=temp;
}

int main(){
    head=NULL;
    InsertAtBeg(&head,5);
    InsertAtBeg(&head,6);
    InsertAtBeg(&head,7);
    InsertAtEnd(&head,9);
    Insert(&head,9,0);
    print(head);
}
