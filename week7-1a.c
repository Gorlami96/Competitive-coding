#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

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

void separate(struct node ** head,struct node ** head1){
    struct node * curr=*head;
    while(curr!=NULL){
        if((curr->data)%2==0){
            InsertAtEnd(&*head1,curr->data);
        }
        curr=curr->next;
    }
    curr=*head;
    while(curr!=NULL){
        if((curr->data)%2==1){
            InsertAtEnd(&*head1,curr->data);
        }
        curr=curr->next;
    }
}

void print(struct node * root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
}


int main(){
    struct node * head=NULL;
    struct node * head1=NULL;
    InsertAtBeg(&head,6);
    InsertAtBeg(&head,5);
    InsertAtBeg(&head,4);
    InsertAtBeg(&head,3);
    InsertAtBeg(&head,2);
    InsertAtBeg(&head,1);
    separate(&head,&head1);
    print(head);
    printf("\n");
    print(head1);
}
