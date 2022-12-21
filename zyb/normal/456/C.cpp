#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;
__int64 a[maxn],f[maxn];
int main()
{
    __int64 m,n;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
    {
        cin>>m;
        a[m]+=m;
    }
    f[1]=a[1];
    for(int i=2;i<maxn;i++)
    {
        f[i]=max(f[i-1],f[i-2]+a[i]);
    }
    cout<<f[maxn-1]<<endl;
    return 0;
}