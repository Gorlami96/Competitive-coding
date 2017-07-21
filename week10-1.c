#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

void printTable(struct node table[]){
	int i;
	for(i=0;i<10;i++){
		if(table[i].data!=-1){
			struct node  * curr=&table[i];
			while(curr){
				printf("%d ",curr->data);
				curr=curr->next;
			}
		}
		printf("\n");
	}
}

void Search(struct node table[],int value){
	int hash_key=value%10;
	if(table[hash_key].data==-1){
		printf("element not found\n");
	}
	else{
		struct node  * curr=&table[hash_key];
		while(curr){
			if(curr->data==value){
				printf("Element found\n");
				return;
			}
			curr=curr->next;
		}
		if(curr==NULL){
			printf("Element not found\n");
		}
	}
}

void Delete(struct node table[],int value){
	int hash_key=value%10;
	struct node * curr=&table[hash_key];
	if(curr->data==value){
		*curr=*(curr->next);
	}
	else{
		while(curr){
			if(curr->next->data==value){
				curr->next=curr->next->next;
				break;
			}
			curr=curr->next;
		}
	}
}

void Insert(struct node table[],int value){
	int hash_key=value%10;
	if(table[hash_key].data==-1){
		table[hash_key].data=value;
	}
	else{
		struct node * curr=&table[hash_key];
		while(!(curr->next==NULL)){
			curr=curr->next;
		}
		struct node * temp=(struct node * )malloc(sizeof(struct node));
		temp->data=value;
		temp->next=NULL;
		curr->next=temp;
	}
}

int main(){
	struct node table[10];
	int i;
	for(i=0;i<10;i++){
		table[i].data=-1;
		table[i].next=NULL;
	}
	Insert(table,71);
	Insert(table,23);
	Insert(table,73);
	Insert(table,99);
	Insert(table,44);
	Insert(table,19);
	Insert(table,49);
	Insert(table,93);
	Insert(table,81);
	Insert(table,39);
	Delete(table,19);
	//Search(table,44);
	printTable(table);
}
