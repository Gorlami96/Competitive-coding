#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,i;
		long long m=1000000000+7;
		scanf("%lld",&n);
		long long dp[n+1];
		dp[1]=1;
		dp[2]=2;
		for(i=3;i<=n;i++){
			dp[i]=((dp[i-1]%m)+((i-1)*dp[i-2])%m)%m;
		}
		printf("%lld",dp[n]);
	}
}