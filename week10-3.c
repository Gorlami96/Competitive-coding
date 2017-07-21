#include <stdio.h>
#include <stdlib.h>

void printTable(int table[]){
	int i;
	for(i=0;i<10;i++){
		if(table[i]==-1){
			printf("\n");
		}
		else{
			printf("%d\n",table[i]);
		}
	}
}

int Search(int table[],int value){
	int hash_key=value%10;
	if(table[hash_key]==-1){
		printf("Element not present");
		return -1;
	}
	else if(table[hash_key]==value){
		printf("Element found");
		return hash_key;
	}
	else{
		int i=1;
		while(i<10){
			if(table[(hash_key+i)%10]==value){
				printf("Element found");
				return (hash_key+i)%10;
			}
			i++;
		}
	}
}

void Insert(int table[],int value){
	int hash_key=value%10;
	if(table[hash_key]==-1){
		table[hash_key]=value;
	}
	else{
		int i=1;
		while(i<10){
			if(table[(hash_key+i)%10]==-1){
				table[(hash_key+i)%10]=value;
				break;
			}
			i++;
		}
	}
}

int main(){
	int table[10];
	int i;
	for(i=0;i<10;i++){
		table[i]=-1;
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
	Search(table,39);
	printTable(table);
}