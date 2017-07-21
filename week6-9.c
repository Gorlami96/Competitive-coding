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

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

int main(){
    head=NULL;
    struct node * res=NULL;
    struct node * a=NULL;
    struct node * b=NULL;
    InsertAtBeg(&a,15);
    InsertAtBeg(&a,10);
    InsertAtBeg(&a,5);
    InsertAtBeg(&b,20);
    InsertAtBeg(&b,3);
    InsertAtBeg(&b,2);
    res=SortedMerge(a,b);
    print(res);
    return 0;
}
