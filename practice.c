#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;

struct node{
	char data;
	struct node * left;
	struct node * right;
};

struct node * createNode(char value){
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void push(struct node * stack[],struct node * value){
	stack[++top]=value;
}

int isEmpty(){
	return top==-1;
}

struct node * pop(struct node * stack[]){
	if(top==-1){
		printf("Underflow!");
		return NULL;
	}
	else{
		struct node * temp=stack[top];
		top--;
		return temp;
	}
}

int isOperand(char ch){
	return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}

struct node * PostfixToExpression(struct node * stack[],char exp[]){
	int i;
	for(i=0;i<strlen(exp);i++){
		if(isOperand(exp[i])){
			struct node * temp=createNode(exp[i]);
			push(stack,temp);
		}
		else{
			struct node * temp=createNode(exp[i]);
			struct node * temp1=pop(stack);
			struct node * temp2=pop(stack);
			temp->right=temp1;
			temp->left=temp2;
			push(stack,temp);
		}
	}
	struct node * temp=pop(stack);
	return temp;
}

void inOrder(struct node * root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	printf("%c",root->data);
	inOrder(root->right);
}

int main(){
	struct node * stack[100];
	char exp[100];
	scanf("%s",exp);
	struct node * root=PostfixToExpression(stack,exp);
	inOrder(root);
}