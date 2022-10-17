#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7,M=3e5;

int n,a[N];

struct BIT{

    long long c[N];

    void add(int x,int v)
    {
        while(x<=M)
        {
            c[x]+=v;
            x+=x&-x;
        }
    }

    long long qry(int x)
    {
        long long ret=0;
        while(x)
        {
            ret+=c[x];
            x-=x&-x;
        }
        return ret;
    }
}C,D,E;

int main()
{
    scanf("%d",&n);
    long long ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        ans+=1ll*a[i]*i+s;
        s+=a[i];
        C.add(a[i],1);
        D.add(a[i],a[i]);
        for(int j=a[i];j<=M;j+=a[i])
        {
            int s=(j+a[i]-1>=M?i:C.qry(j+a[i]-1))-(j-1<0?0:C.qry(j-1));
            ans-=1ll*s*(j/a[i])*a[i];
            E.add(j,j/a[i]*a[i]);
            if(j+a[i]<=M)
                E.add(j+a[i],-j/a[i]*a[i]);
        }
        // for(int j=1,k;j<=a[i];j=k+1)
        // {
        //     k=a[i]/(a[i]/j);
        //     ans-=1ll*a[i]/j*(D.qry(k)-D.qry(j-1));
        // }
        ans-=E.qry(a[i]);
        ans+=a[i];
        printf("%lld%c",ans," \n"[i==n]);
    }
}