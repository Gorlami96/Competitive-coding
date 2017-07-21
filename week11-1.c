#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node * left;
	struct node * right;
};

struct node * newnode(int data){
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->key=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* Insert(struct node* node, int key)
{
    if (node == NULL) return newnode(key);
    if (key < node->key)
        node->left  = Insert(node->left, key);
    else if (key > node->key)
        node->right = Insert(node->right, key);   
    return node;
}

void LCS(int a,int b,struct node * root){
	struct node * curr=root;
	while(1){
		if(a<(curr->key)&&b<(curr->key)){
			curr=curr->left;
		}
		else if(a>(curr->key)&&b>(curr->key)){
			curr=curr->right;
		}
		else{
			printf("%d\n",curr->key);
			break;
		}
	}
}

int main(){
	struct node * root=Insert(root,25);
	Insert(root,30);
	Insert(root,20);
	Insert(root,10);
	Insert(root,35);
	Insert(root,10);
	Insert(root,23);
	Insert(root,5);
	Insert(root,21);
	Insert(root,32);
	LCS(10,23,root);
}