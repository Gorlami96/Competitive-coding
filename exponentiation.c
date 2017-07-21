#include <stdio.h>

void multiply(long long F[2][2],long long M[2][2]){
	long long w=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	long long x=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	long long y=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	long long z=F[1][0]*M[0][1]+F[1][1]*M[1][1];

	F[0][0]=w;
	F[0][1]=x;
	F[1][0]=y;
	F[1][1]=z;

}

void power(long long F[2][2],long long n){
	if(n==0||n==1){
		return ;
	}
	long long M[2][2]={{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if(n%2!=0){
		multiply(F,M);
	}

}

long long fib(long long n){
	if(n==0){
		return 0;
	}
	long long F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	return F[0][0];
}

long long main(){
	long long n;
	scanf("%lld",&n);
	long long ans=fib(n);
	printf("%lld",ans);
}