#include <stdio.h>

int top=-1;

void push(int stack[],int value){
    stack[++top]=value;
}

int isEmpty(){
    return (top==-1); 
}

int pop(int stack[]){
    return stack[top--];
}

int peek(int stack[]){
    return stack[top];
}

int getMaxArea(int hist[],int n){
    int stack[n];
    int max_area=0;
    int tp;
    int area;
    int i=0;
    while(i<n){
        if(isEmpty()||hist[i]>=hist[peek(stack)]){
            push(stack,i++);
        }
        else{
            tp=pop(stack);
            area=hist[tp]*(isEmpty()?i:i-peek(stack)-1);
            if(max_area<area){
                max_area=area;
            }
        }
    }
    while(!isEmpty()){
        tp=pop(stack);
        area=hist[tp]*(isEmpty()?i:i-peek(stack)-1);
        if(max_area<area){
            max_area=area;
        }
    }
    return max_area;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    printf("%d\n",getMaxArea(hist,n));
    return 0;
}
