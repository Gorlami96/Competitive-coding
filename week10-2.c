#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
	struct node * prev;
};

struct node * Search(struct node table[],int value){
	int hash_key1=value%10;
	int hash_key2=7-value%7;
	if(table[hash_key1].data==value){
		return &table[hash_key1];
	}
	if(table[hash_key2].data==-1){
		return NULL;
	}
	else{
		struct node * curr=&table[hash_key2];
		while(curr){
			if(curr->data==value){
				printf("Element Found");
				return curr;
			}
			curr=curr->next;
		}
		if(curr==NULL){
			return NULL;
		}
	}
}

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

void Insert(struct node table[],int value){
	int hash_key1=value%10;
	int hash_key2=7-value%7;
	if(table[hash_key1].data==-1){
		table[hash_key1].data=value;
	}
	else{
		if(table[hash_key2].data==-1){
			table[hash_key2].data=value;
		}
		else{
			struct node * curr=&table[hash_key2];
			while(!(curr->next==NULL)){
				curr=curr->next;
			}
			struct node * temp=(struct node * )malloc(sizeof(struct node));
			temp->data=value;
			temp->prev=curr;
			curr->next=temp;
			temp->next=NULL;
		}
	}
}

void Delete(struct node table[],int value){
	struct node * curr=Search(table,value);
	if(curr->prev==NULL){
		*(curr)=*(curr->next);
	}
	else{
		if(curr->next==NULL){
			printf("%d\n",curr->prev->data);
			(curr->prev)->next=NULL;
			curr->prev=NULL;
		}
		else{
			curr->prev->next=curr->next;
			curr->next->prev=curr->prev;
		}
	}
}

int main(){
	struct node table[10];
	int i;
	for(i=0;i<10;i++){
		table[i].data=-1;
		table[i].next=NULL;
		table[i].prev=NULL;
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
	Delete(table,81);
	printTable(table);
}