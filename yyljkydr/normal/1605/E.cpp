#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,a[N],b[N],c[N];

int q;

struct Line{
    int k,b;
}ans[N],pre[N];

bool operator <(const Line &a,const Line &b)
{
    return (long double)a.b/a.k>(long double)b.b/b.k;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]),ans[i].b=b[i];
    ans[1].k=-1,ans[1].b=a[1];
    for(int i=2;i<=n;i++)
        ans[i].k+=ans[1].k,ans[i].b+=ans[1].b;
    for(int i=2;i<=n;i++)
    {
        ans[i].k=-ans[i].k;
        ans[i].b=a[i]-ans[i].b;
        for(int j=i*2;j<=n;j+=i)
            ans[j].k+=ans[i].k,ans[j].b+=ans[i].b;
    }
    int cc=0,cb=0;
    for(int i=1;i<=n;i++)
        if(ans[i].k!=0)
            ans[++cc]=ans[i];
        else
            cb+=abs(ans[i].b);
    n=cc;
    sort(ans+1,ans+n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(ans[i].k<=0)
            pre[i].k+=ans[i].k,pre[i].b+=ans[i].b;
        else
            pre[i].k-=ans[i].k,pre[i].b-=ans[i].b;
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&b[1]);
        int l=0,r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(b[1]>=-(long double)ans[mid].b/ans[mid].k-1e-6)
                l=mid;
            else
                r=mid;
        }
        int sum=0;
        sum-=pre[l].k*b[1]+pre[l].b;
        sum-=(pre[l].k-pre[n].k)*b[1]+pre[l].b-pre[n].b;
        printf("%lld\n",sum+cb);
    }
}