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

struct Stack{
	int capacity;
	int top;
	char * array;
};

struct Stack * createStack(int capacity){
	struct Stack * stack=(struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(char *)malloc(sizeof(char)*capacity);
	return stack;
} 

void push(struct Stack * stack,char x){
	stack->array[++stack->top]=x;
}

int isEmpty(struct Stack * stack){
	return stack->top==-1;
}

char pop(struct Stack * stack){
	if (!isEmpty(stack))
        return stack->array[stack->top--] ;
}

int isOperand(char ch){
	return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}

char peek(struct Stack * stack){
	return stack->array[stack->top];
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char exp[]){
	int i, k;
   
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
         // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);
        
        //  If the scanned character is an ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression                
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
 
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
 
    exp[++k] = '\0';
    //printf( "%s\n", exp );
}


int main(){
	char str[100];
	scanf("%s",str);
    infixToPostfix(str);
    printf( "%s\n", str );
    //PostfixToExpression(str);
}