#include<iostream>
using namespace std;
const int N=1e5+1;
const long long D=1e9+7;
int n,m,k,f[N],c[N],x,y,z;
long long t,A;
int F(int k)
{
    if(f[k]==k)
        return k;
    return f[k]=F(f[k]);
}
long long P(long long a,int b)
{
    t=1;
    while(b)
    {
        if(b&1)
            (t*=a)%=D;
        (a*=a)%=D,b/=2;
    }
    return t;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        f[i]=i,c[i]=1;
    m=n-1;
    while(m--&&cin>>x>>y>>z)
        if(!z)
            x=F(x),y=F(y),f[y]=x,c[x]+=c[y];
    for(int i=1;i<=n;i++)
        x=F(i),A+=P(c[x],k),c[x]=0;
    cout<<(P(n,k)-A%D+D)%D;
    return 0;
}