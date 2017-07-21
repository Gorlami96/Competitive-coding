#include <iostream>
#include <set>
using namespace std;

void init(long long arr[],long long size[],long long x,long long y,long long men[],long long women[]){
    for(long long i=1;i<=x+y;i++){
        arr[i]=i;
        size[i]=1;
    }
    for(long long i=1;i<=x;i++){
        men[i]=1;
        women[i]=0;
    }
    for(long long i=x+1;i<=x+y;i++){
        women[i]=1;
        men[i]=0;
    }
}

long long root(long long arr[],long long i){
    while(arr[i]!=i){
        i=arr[i];
    }
    return i;
}

bool find(long long arr[],long long a,long long b){
    if(root(arr,a)==root(arr,b)){
        return true;
    }
    else{
        return false;
    }
}

void weighted_union(long long arr[],long long size[],long long a,long long b,long long men[],long long women[],int type){
    long long root_a=root(arr,a);
    long long root_b=root(arr,b);
    if(root_a!=root_b){
        if(size[root_a]<size[root_b]){
        arr[root_a]=root_b;
        size[root_b]+=size[root_a];
        if(type==1){
            men[root_b]+=men[root_a];
        }
        else if(type==2){
            women[root_b]+=women[root_a];
        }
        else{
            women[root_b]+=women[root_a];
            men[root_b]+=men[root_a];
        }
       }
       else{
        arr[root_b]=arr[root_a];
        size[root_a]+=size[root_b];
        if(type==1){
            men[root_a]+=men[root_b];
        }
        else if(type==2){
            women[root_a]+=women[root_b];
        }
        else{
            men[root_a]+=men[root_b];
            women[root_a]+=women[root_b];
        }
       }
    }
}

int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long arr[x+y+1],size[x+y+1];
    long long men[x+y+1],women[x+y+1];
    init(arr,size,x,y,men,women);
    long long q1;
    scanf("%lld",&q1);
    for(long long i=0;i<q1;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        weighted_union(arr,size,u,v,men,women,1);
    }
    long long q2;
    scanf("%lld",&q2);
    for(long long i=0;i<q2;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        weighted_union(arr,size,u+x,v+x,men,women,2);
    }
    long long q3;
    scanf("%lld",&q3);
    for(long long i=0;i<q3;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        weighted_union(arr,size,u,v+x,men,women,3);
    }
    set<long long> roots;
    for(long long i=1;i<=x+y;i++){
        roots.insert(arr[root(arr,i)]);
    }
    long long res=0;
    for(set<long long>::iterator i=roots.begin();i!=roots.end();i++){
        res+=men[*i]*(y-women[*i]);
        //cout<<"root="<<*i<<"men="<<men[*i]<<"women not in group ="<<(y-women[*i])<<endl;
    }
    //cout<<women[7];
    cout<<res;
    return 0;
}
