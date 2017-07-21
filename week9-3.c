#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9];

int check_digits(int arr[]){
	int freq[10],i;
	for(i=1;i<10;i++){
		freq[i]=0;
	}
	for(i=0;i<9;i++){
		freq[arr[i]]++;
		if(freq[arr[i]]>1){
			return 0;
		}
	}
	return 1;
}

int main(){
	int flag=0,i,j;
	int arr[9];
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			scanf("%d",&sudoku[i][j]);
		}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			arr[j]=sudoku[i][j];
		}
		flag+=check_digits(arr);
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			arr[j]=sudoku[j][i];
		}
		flag+=check_digits(arr);
	}
	

	int k=0;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[k++]=sudoku[i][j];
		}
		flag+=check_digits(arr);
	}

	k=0;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[k++]=sudoku[i][j];
		}
		flag+=check_digits(arr);
	}

	k=0;


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[k++]=sudoku[i][j];
		}
		flag+=check_digits(arr);
	}

	k=0;

	
	printf("%d",flag);
}