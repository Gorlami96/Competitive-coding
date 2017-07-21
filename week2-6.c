#include<stdio.h>

long long power(int exp){
    int i;
    long long exponent=1;
    for(i=0;i<exp;i++){
        exponent*=3;
    }
    return exponent;
}

int main(){
    long long n;
    scanf("%lld",&n);
    int number_of_digits=0;
    long long temp=n;
    while(temp){
        number_of_digits++;
        temp=temp/10;
    }
    int digits[number_of_digits];
    temp=n;
    int i;
    for(i=number_of_digits-1;i>=0;i--){
        digits[i]=temp%10;
        temp=temp/10;
    }
    long long count=0;
    for(i=1;i<number_of_digits;i++){
        count+=power(i);
    }
    i=0;
    
    while(i!=number_of_digits){
        if(digits[i]!=1&&digits[i]!=7&&digits[i]!=9){
            if(digits[i]>1&&digits[i]<7){
                count+=power(number_of_digits-i-1);
            }
            else if(digits[i]>7&&digits[i]<9){
                count+=2*power(number_of_digits-i-1);
            }
            break;
        }
        else{
            if(digits[i]==7){
                count+=power(number_of_digits-i-1);
            }
            else if(digits[i]==9){
                count+=2*power(number_of_digits-i-1);
            }
            i++;
        }
    }
    if(i==number_of_digits){
        count+=1;
    }
    printf("%lld",count);
    return 0;
}