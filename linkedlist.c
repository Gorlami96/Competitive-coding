#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *next;
};
 struct LIST{
    struct node *head;
    int size;
};
struct LIST createlist()
{
    struct LIST sl;
    sl.head=NULL;
    sl.size=0;
    return sl;
}
struct LIST insert_element_left(int e,struct LIST sl)
{
    struct node *nl=(struct node *)malloc(sizeof(struct node));
    nl->data=e;
    nl->next=sl.head;
    sl.head=nl;
    sl.size++;
    return sl;
}
struct LIST insert_element_right(int e,struct LIST sl)
{
    struct node *temp=sl.head;
    if(temp==NULL)
    {
        struct node *nl=(struct node *)malloc(sizeof(struct node));
        nl->next=NULL;
        nl->data=e;
        sl.head=nl;
        return sl;
    }
    else
    {
        while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     struct node *nl=(struct node *)malloc(sizeof(struct node));
     temp->next=nl;
     nl->next=NULL;
     nl->data=e;
     return sl;
    }
}
void display(struct LIST sl)
{
    struct node *temp;
    temp=sl.head;
    do
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    while(temp!=NULL);
}

int main()
{
    int ch=1;
    struct LIST sl;
    sl=createlist();
    int e;
    while(1)
    {
        printf("please enter the data \n");
        scanf("%d",&e);
        sl=insert_element_right(e,sl);
        printf("do you  want to enter more data?\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
display(sl);
    return 0;
}
