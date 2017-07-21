#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    pair<int,int> pv[n];
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        pv[i]=make_pair(temp,i);
    }
    sort(pv,pv+n);
    int sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=abs(pv[j].second-j);
    }
    cout<<sum;
    return 0;
}
