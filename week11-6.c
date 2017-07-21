#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getMin(int x,int y){
	return (x>y)?y:x ;
}

int minCoins(int total,int coins[],int dn){
	int T[total+1];
	int i,j;
	T[0]=0;
	for(i=1;i<=total;i++){
		T[i]=INT_MAX;
	}
	for(i=1;i<=total;i++){
		for(j=0;j<dn;j++){
			if(coins[j]<=i){
				int res=T[i-coins[j]];
				if(res!=INT_MAX && res+1<T[i]){
					T[i]=res+1;
				}
			}
		}
	}
	return T[total];
}

int main(){
	int dn,i,j,total;
	printf("Enter number of coins - ");
	scanf("%d",&dn);
	int coins[dn];
	printf("Enter the coins - \n");
	for(i=0;i<dn;i++){
		scanf("%d",&coins[i]);
	}
	printf("Enter total - ");
	scanf("%d",&total);
	int res=minCoins(total,coins,dn);
	printf("%d",res);
}