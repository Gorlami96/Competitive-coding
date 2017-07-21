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

int getMin(int x,int y){
	return (x>y)?y:x;
}

int ClosestLeaf(struct node * root){
	if(root==NULL){
		return INT_MAX;
	}
	if(root->left==NULL&&root->right==NULL){
		return 0;
	}
	return 1+getMin(ClosestLeaf(root->left),ClosestLeaf(root->right));
}

int findClosestUtil(struct node *root, int k, struct node *ancestors[],
                                               int index)
{
    if (root == NULL)
        return INT_MAX;
    if (root->key == k)
    {
        int res = ClosestLeaf(root);
        for (int i = index-1; i>=0; i--)
            res = getMin(res, index - i + ClosestLeaf(ancestors[i]));
        return res;
    }
    ancestors[index] = root;
    return getMin(findClosestUtil(root->left, k, ancestors, index+1),
                  findClosestUtil(root->right, k, ancestors, index+1));
}

int findClosest(struct node * root,int k){
	struct node * ancestors[100];
	return findClosestUtil(root,k,ancestors,0);
}

int main(){
	struct node * root=newnode(10);
	root->left=newnode(12);
	root->right=newnode(13);
	root->right->left=newnode(14);
	root->right->right=newnode(15);
	printf("%d",findClosest(root,13));
	return 0;
}