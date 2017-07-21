#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head=NULL;
struct node * tail=NULL;

struct node * newnode(int x){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void InsertAtBeg(int x){
    struct node * temp=newnode(x);
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL){
        head->prev=temp;
    }
    head=temp;
}

void InsertAtEnd(int x){
    struct node *temp=newnode(x);
    if(head==NULL){
        head=temp;
    }
    else{
        struct node * curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
        return;
    }
}

void print(){
    struct node * curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

/*void reverse(){
    struct node *temp = NULL;  
    struct node *current = head;
    while (current !=  NULL)
    {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
    }      
    if(temp != NULL )
        head = temp->prev;
}*/

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
    
    InsertAtBeg(3);
    InsertAtBeg(2);
    InsertAtBeg(1);
    InsertAtEnd(4);
    print();
    printf("\n");
    print(reverse(head));
    return 0;
}
