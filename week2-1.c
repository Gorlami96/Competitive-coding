#include <stdio.h>

int main(void) {
	long long cc_number;
	scanf("%lld",&cc_number);
	int n=0;
	long long temp=cc_number;
	while(temp){
	    temp=temp/10;
	    n++;
	}
	int digits[n];
	temp=cc_number;
	int i=0;
	while(temp){
	    digits[i++]=temp%10;
	    temp=temp/10;
	}
	int sum=0;
	for(i=0;i<n;i++){
	    if(i%2==1){
	        digits[i]=digits[i]*2;
	        if(digits[i]>9){
	            int temp2=digits[i]%10;
	            digits[i]=digits[i]/10;
	            digits[i]=digits[i]+temp2;
	        }
	    }
	    sum+=digits[i];
	}
	return 0;
}