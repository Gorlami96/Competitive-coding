#include <stdio.h>
#include <stdlib.h>

int m=3,n=4;

int canBeVisited(char map[][n],int r,int c,int visited[][n]){
	return (r >= 0) && (r < m) &&     
           (c >= 0) && (c < n) &&      
           (map[r][c]=='L' && !visited[r][c]); 
}

void DFS(char map[][n],int r,int c,int visited[][n]){
	int rnbr[]={1,0,-1,0};
	int cnbr[]={0,1,0,-1};
	int k;
	visited[r][c]=1;
	for(k=0;k<4;k++){
		if(canBeVisited(map,r+rnbr[k],c+cnbr[k],visited)){
			DFS(map,r+rnbr[k],c+cnbr[k],visited);
		}
	}
}

void countIsland(char map[][n]){
	int visited[m][n];
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			visited[i][j]=0;
		}
	}
	int count=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='L'&&!visited[i][j]){
				DFS(map,i,j,visited);
				count++;
			}
		}
	}
	printf("%d\n",count);
}

int main(){
	char map[][4]={{'W','W','W','L'},{'L','L','W','L'},{'L','W','W','L'}};
	countIsland(map);
	return 0;
}