#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reset_hash(int hash[]){
	int i;
	for(i=0;i<200;i++){
		hash[i]=0;
	}
}

void main(){
	char str[200];
	scanf("%s",str);
	int hash[200],i;
	reset_hash(hash);
	int length=0;
	int max_length=0;
	int max_index;

	for(i=0;i<strlen(str);i++){
		if(hash[str[i]]==0){
			hash[str[i]]++;
			length++;
		}
		else{
			reset_hash(hash);
			if(length>max_length){
				max_length=length;
				max_index=i-max_length;
			}
			length=0;
			i--;
		}
	}
	if(length>max_length){
		max_length=length;
		max_index=i-max_length;
	}
	printf("%d",max_length);
	for(i=max_index;i<max_index + max_length;i++){
		printf("%c",str[i]);
	}
}