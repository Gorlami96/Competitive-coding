#include <stdio.h>
#include <stdlib.h>

struct stack{
    int capacity;
    int top;
    int * array;
    int size;
};

struct stack * createStack(int capacity){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->top=-1;
    s->size=0;
    s->array=(int *)malloc(sizeof(int)*capacity);
    return s;
}

void printStack(struct stack * s){
    int i;
    for(i=0;i<(s->top+1);i++){
        printf("%d\n",s->array[i]);
    }
}

void push(struct stack * s,int value){
    s->array[++s->top]=value;
}

int pop(struct stack * s){
    return s->array[s->top--];
}

int isEmpty(struct stack * s){
    return ((s->top)==-1);
}

void enqueue(struct stack * s1,struct stack * s2,int x){
    while(!isEmpty(s1)){
        push(s2,pop(s1));
    }
    push(s1,x);
    while(!isEmpty(s2)){
        push(s1,pop(s2));
    }
}

int dequeue(struct stack * s1){
    return pop(s1);
}

int main(){
    struct stack * s1=createStack(100);
    struct stack * s2=createStack(100);
    int choice;
    while(1){
        scanf("%d",&choice);
        if(choice==1){
            int temp;
            scanf("%d",&temp);
            enqueue(s1,s2,temp);
        }
        else if(choice==2){
            printf("%d",dequeue(s1));
        }
        else if(choice==3){
            int temp;
            scanf("%d",&temp);
            if(temp==1){
                printStack(s1);
            }
            else{
                printStack(s2);
            }
        }
        else{
            break;
        }
    }
    return 0;
}
