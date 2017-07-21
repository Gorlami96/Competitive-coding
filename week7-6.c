#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
int n;
void push(char stack[],char x){
	top=top+1;
	stack[top]=x;
}
void pop(char stack[]){
	top=top-1;
}

char peek(char stack[]){
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

int countReversals(char string[],char stack[]){
	int len=strlen(string);
	int i;
	for(i=0;i<len;i++){
		if(string[i]==')'&&!isEmpty()){
			if(peek(stack)=='('){
				pop(stack);
			}
			else{
				push(stack,string[i]);
			}
		}
		else{
			push(stack,string[i]);
		}
	}
	int red_len=size();
	int n=0;
	while(!isEmpty()&&peek(stack)=='('){
		pop(stack);
		n++;
	}
	return ((red_len/2)+n%2);
}

int main(){
    char string[100];
    scanf("%s",string);
    n=strlen(string);
    char stack[1000];
    printf("%d\n",countReversals(string,stack));
	return 0;
}