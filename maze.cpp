#include <iostream>
using namespace std;

int n;
int maze[100][100],sol[100][100];

bool isSafe(int x,int y){
    if((x>=0&&x<n)&&(y>=0&&y<n)&&(maze[x][y]==1)){
        return true;
    }
    return false;
}

bool solUtil(int x,int y){
    if(isSafe(x,y)==true){
        sol[x][y]=1;
        if(x==n-1&&y==n-1){
            return true;
        }
        if(solUtil(x,y+1)==true){
            return true;
        }
        if(solUtil(x+1,y)==true){
            return true;
        }
        if(solUtil(x,y-1)==true){
            return true;
        }
        if(solUtil(x-1,y)==true){
            return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}

void printSol()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sol[i][j];
        }
        cout<<endl;
    }
}

bool solution(){
    if(solUtil(0,0)==false){
        cout<<"Maze cannot be solved"<<endl;
        return false;
    }
    printSol();
    return true;
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    solution();
    return 0;
}
