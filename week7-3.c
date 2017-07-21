#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head=NULL;
struct node * tail=NULL;
int n=0;
struct node * newnode(int value){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    n++;
    return temp;
}

void InsertAtBeg(int x){
    struct node * temp=newnode(x);
    if(head==tail&&head==NULL){
        head=tail=temp;
        head->next=tail->next=NULL;
        head->prev=tail->prev=NULL;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
        head->prev=tail;
        tail->next=head;
    }
}

void InsertAtEnd(int x){
    struct node * temp=newnode(x);
    if(head==tail&&head==NULL){
        head=tail=temp;
        head->next=tail->next=NULL;
        head->prev=tail->prev=NULL;
    }
    else{
        temp->prev=tail;
        temp->next=tail->next;
        head->prev=temp;
        tail->next=temp;
        tail=temp;
    }
}

void InsertAtIndex(int index,int x){
    struct node * temp=newnode(x);
    if(head==tail&&head==NULL){
        if(index==0){
            head=tail=temp;
            head->next=tail->next=NULL;
            head->prev=tail->prev=NULL;
        }
        else{
            printf("List is empty!");
        }
    }
    else{
        if(index>n-1){
            printf("Can't insert at that position!");
        }
        else{
            int i;
            struct node * curr=head;
            struct node * prevn;
            for(i=0;i<n;i++){
                prevn=curr;
                curr=curr->next;
                if(i==index-1){
                    prevn->next=temp;
                    temp->prev=prevn;
                    temp->next=curr;
                    curr->prev=temp;
                    break;
                }
            }
        }
    }
}

void print(){
    if(head==tail&&head==NULL){
        printf("List is empty!\n");
    }
    else{
        int i;
        struct node * curr=head;
        for(i=0;i<n;i++){
            printf("%d ",curr->data);
            curr=curr->next;
        }
    }
}

int main(){
    InsertAtBeg(3);
    InsertAtBeg(2);
    InsertAtBeg(1);
    InsertAtEnd(4);
    InsertAtIndex(2,8);
    print();
    return 0;
}
