#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int printPath(struct node * root,struct node * leaf){
	if(root==NULL){
		return 0; 
	}
	if(root==leaf||printPath(root->left,leaf)||printPath(root->right,leaf)){
		printf("%d-->",root->key);
		return 1;
	}
	return 0;
}

void getLeaf(struct node * root,int * max_sum_ref,int sum,struct node ** leaf_ref){
	if(root==NULL){
		return ;
	}
	sum+=root->key;

	if(root->left==NULL&&root->right==NULL){
		if(sum>*max_sum_ref){
			*max_sum_ref=sum;
			*leaf_ref=root;
		}
	}

	getLeaf(root->left,max_sum_ref,sum,leaf_ref);
	getLeaf(root->right,max_sum_ref,sum,leaf_ref);
}

void maxSum(struct node * root){
	if(root==NULL){
		return ;
	}
	struct node * leaf;
	int max_sum=INT_MIN;
	getLeaf(root,&max_sum,0,&leaf);
	printPath(root,leaf);
}

int main(){
	struct node * root = newnode(10);
    root->left = newnode(-2);
    root->right = newnode(7);
    root->left->left = newnode(8);
    root->left->right = newnode(-4);
    maxSum(root);
    return 0;
}