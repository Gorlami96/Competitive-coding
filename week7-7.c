#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
int n;
void push(int stack[],int x){
	top=top+1;
	stack[top]=x;
}
void pop(int stack[]){
	top=top-1;
}

char peek(int stack[]){
	return stack[top];
}

int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int size(){
	return top+1;
}

int countPairs(int stack[],int arr[]){
    push(stack,arr[0]);
    int count=0,i,next,element;
    for(i=1;i<n;i++){
        next=arr[i];
        if(!isEmpty()){
            element=peek(stack);
            pop(stack);
            while(element<next){
                count++;
                if(isEmpty()){
                    break;
                }
                element=peek(stack);
                pop(stack);
            }
            if(element>=next){
                push(stack,element);
                count++;
            }
        }
        push(stack,next);
    }
    return count;
}

int main(){
    int i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int stack[n];
    printf("%d\n",countPairs(stack,arr));
	return 0;
}