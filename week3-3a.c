#include <stdio.h>

int main()
{
    int n,i,j,element=0;
    scanf("%d",&n);
    int dir,dir_change,count,steps_to_take,step_change;
    dir=1,count=0,steps_to_take=n-1,step_change=0;
    int *arr=(int *)malloc(n*n*sizeof(int));
    for(j=0;j<n;j++){
        *(arr + j)=++element;
    }
    i=0,j=n-1;
    while(steps_to_take!=0){
        if(element>=(n*n)){
            break;
        }
        if(dir==1){
            i++;
            *(arr+i*n+j)=++element;
            count++;
            if(count==steps_to_take){
                count=0;
                dir=2;
                step_change++;
                if(step_change==2){
                    steps_to_take--;
                    step_change=0;
                }
            }
        }
        else if(dir==2){
            j--;
            *(arr+i*n+j)=++element;
            count++;
            if(count==steps_to_take){
                count=0;
                dir=3;
                step_change++;
                if(step_change==2){
                    steps_to_take--;
                    step_change=0;
                }
            }
        }
        if(dir==3){
            i--;
            *(arr+i*n+j)=++element;
            count++;
            if(count==steps_to_take){
                count=0;
                dir=4;
                step_change++;
                if(step_change==2){
                    steps_to_take--;
                    step_change=0;
                }
            }
        }
        if(dir==4){
            j++;
            *(arr+i*n+j)=++element;
            count++;
            if(count==steps_to_take){
                count=0;
                dir=1;
                step_change++;
                if(step_change==2){
                    steps_to_take--;
                    step_change=0;
                }
            }
        }
    }
    if(n%2==0){
        *(arr+i*n+j)=(n*n)-3;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(arr+i*n+j));
        }
        printf("\n");
    }
    return 0;
}
