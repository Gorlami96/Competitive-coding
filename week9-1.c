#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char str[1000];
	scanf("%s",str);
	int hash[1000],i;
	for(i=0;i<1000;i++){
		hash[i]=0;
	}
	for(i=0;i<strlen(str);i++){
		if(hash[str[i]]==0){
			printf("%c",str[i]);
			hash[str[i]]++;
		}
	}
}