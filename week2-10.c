#include <stdio.h>

void printArr(int arr[],int size){
    int j=0;
	while(j<size){
	    printf("%d",arr[j]);
	    j++;
	}
}

int checkNine(int arr[],int size){
    int count=0,i;
    for(i=0;i<size;i++){
        if(arr[i]==9){
            count++;
        }
    }
    if(count==size){
        return 1;
    }
    else{
        return 0;
    }
}

int checkPalindrome(int numb[],int l,int r){
    int left=l;
    int right=r;
    while(left>=0){
        if(numb[left]==numb[right]){
            left--;
            right++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

void mirrorLeft(int arr[],int l,int r){
    while(l>=0){
        arr[r]=arr[l];
        r++;
        l--;
    }
}

int main(void) {
	int n,a;
	scanf("%d",&n);
	for(a=0;a<n;a++){
	    char num[1000];
	    int numb[1000];
	    int number_of_digits=0;
	    scanf("%s",num);
	    while(num[number_of_digits]!='\0'){
	        numb[number_of_digits]=num[number_of_digits]-'0';
	        number_of_digits++;
	    }
	    int l,r;
	    if(number_of_digits%2==0){
	        r=(number_of_digits)/2;
	        l=r-1;
	    }
	    else{
	        l=(number_of_digits/2)-1;
	        r=(number_of_digits/2)+1;
	    }
	    int i;
	    if(checkPalindrome(numb,l,r)==1){
	        if(checkNine(numb,number_of_digits)==1){
	            int palin[number_of_digits+1];
	            palin[0]=1;
	            palin[number_of_digits]=1;
	            for(i=1;i<number_of_digits;i++){
	                palin[i]=0;
	            }
	            printArr(palin,number_of_digits+1);
	        }
	        else{
	            int carry=1;
	            if(number_of_digits%2==0){
	                for(i=l;i>=0;i--){
	                    numb[i]=numb[i]+carry;
	                    if(numb[i]==10){
	                        numb[i]=0;
	                        carry=1;
	                    }
	                    else{
	                        carry=0;
	                    }
	                }
	            }
	            else{
	                for(i=l+1;i>=0;i--){
	                    numb[i]=numb[i]+carry;
	                    if(numb[i]==10){
	                        numb[i]=0;
	                        carry=1;
	                    }
	                    else{
	                        carry=0;
	                    }
	                }
	            }
	           mirrorLeft(numb,l,r);
	           printArr(numb,number_of_digits);
	        }
	    }
	    else{
	        int carry=1;
	        int left=l;
	        int right=r;
	        while(numb[left]==numb[right]){
	            left--;
	            right++;
	        }
	        if(numb[left]>numb[right]){
	            mirrorLeft(numb,l,r);
	        }
	        else{
	            if(number_of_digits%2==0){
	                for(i=l;i>=0;i--){
	                    numb[i]=numb[i]+carry;
	                    if(numb[i]==10){
	                        numb[i]=0;
	                        carry=1;
	                    }
	                    else{
	                        carry=0;
	                    }
	                }
	            }
	            else{
	                for(i=l+1;i>=0;i--){
	                    numb[i]=numb[i]+carry;
	                    if(numb[i]==10){
	                        numb[i]=0;
	                        carry=1;
	                    }
	                    else{
	                        carry=0;
	                    }
	                }
	            }
	            mirrorLeft(numb,l,r);
	            printArr(numb,number_of_digits);
	        }
	    }
	}
	return 0;
}

