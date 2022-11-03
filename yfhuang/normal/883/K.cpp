#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int N=210000;
int l[N],r[N],x[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]);
        r[i]+=l[i];
        x[i]=r[i];
    }
    int flg=0;
    long long sum=0;
    for(int i=2;i<=n;i++)x[i]=min(x[i-1]+1,x[i]);
    for(int i=n-1;i>=1;i--)x[i]=min(x[i+1]+1,x[i]);
    for(int i=1;i<=n;i++){if(x[i]<l[i])flg=-1;sum+=x[i]-l[i];}
    if(flg==-1)cout<<-1<<endl;
    else
    {
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)cout<<x[i]<<" ";
        cout<<endl;
    }
}