#include <stdio.h>
#include <stdlib.h>

long long exp_by_squaring(long long a,long long b){
	if(b<0){
		return exp_by_squaring(1/a,-b);
	}
	if(b==0){
		return 1;
	}
	else if(b==1){
		return a;
	}
	else if(b%2==0){
		return exp_by_squaring(a*a,b/2);
	}
	else{
		return a*exp_by_squaring(a*a,(b-1)/2);
	}
}

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long res=exp_by_squaring(a,b);
	printf("%lld\n",res);
}	
