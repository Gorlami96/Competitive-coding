#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * tail=NULL;
struct node * newnode(int value){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
void InsertAtEnd(int x){
	struct node * temp=newnode(x);
	if(tail==NULL){
		tail=temp;
		tail->next=tail;
	}
	else{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}

void print(int n){
    if(tail==NULL){
        printf("List is empty!\n");
    }
    else{
        int i;
        struct node * curr=tail->next;
        for(i=0;i<n;i++){
            printf("%d ",curr->data);
            curr=curr->next;
        }
    }
    printf("\n");
}

void skip(int j,int k,int n){
	int i;
	struct node * curr=tail;
	for(i=0;i<j;i++){
		curr=curr->next;
	}
    int temp1=0;
    while(temp1<k-1){
    	curr=curr->next;
    	temp1++;
    }
    curr->data=0;
    int count=1;
	while(count<n-1){
		int temp=0;
		while(temp<k){
			curr=curr->next;
			if(curr->data!=0){
				printf("incrementing temp at %d\n",curr->data);
				temp++;
			}
		}
		printf("Making zero at %d\n",curr->data);
		curr->data=0;
		count++;
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
    for(i=0;i<n;i++){
    	InsertAtEnd(i+1);
    }
    int j,k;
    scanf("%d%d",&j,&k);
    skip(j,k,n);
    print(n);
    return 0;
}