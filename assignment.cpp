#include <iostream>
#define MAX 50;
using namespace std;
int top=-1;
void push(char Stack[],char element,int n){
	if(top==n-1){
		cout<<"Overflow!";
	}
	else{
		top++;
		Stack[top]=element;
	}
}
void pop_procedure(char Stack[],int n,int &j,char ch,char answer[]){
    int a=1;
    while(a==1){
        pop(Stack,n);
        if(ch==')')
            a=0;
    }
}
void pop(char Stack[],int n){
	if(top==-1){
		cout<<"Underflow."<<endl;
	}
	else{
		top--;
	}
}
int main()
{
    int t;
    cin>>t;
    string formula;
    cin>>formula;
    int n=formula.length();
    char Stack[MAX];
    char answer[MAX];
    int j=0;
    for(i=formula.length()-1;i>=0;i--){
        if(formula[i]=='+'||formula[i]=='*'||formula[i]=='~'||formula[i]=='>'formula[i]=='('||formula[i]==')'){
                if(formula[i]=='('){
                    pop_procedure(Stack,n,j,formula[i],answer);
                }
                else{
                    push(Stack,formula[i],n);
                }
        }
        else{
            answer[j]=formual[i];
            j++;
        }
    }
    return 0;
}
