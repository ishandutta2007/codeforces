#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e6+1e3+7,P=1e9+7;

int n,m,p[N],k[N],b[N],w[N],a[N],t[N],ans[N];

int seed,base;

ll s[N],sum;

int rnd()
{
    int ret=seed;
    seed=(1ll*seed*base+233)%1000000007;
    return ret;
}

void gen()
{
    p[0]=0;
    for(int i=1;i<=m;i++)
    {
        seed=b[i],base=w[i];
        for(int j=p[i-1]+1;j<=p[i];j++)
            t[j]=rnd()%2,a[j]=rnd()%k[i]+1;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&p[i],&k[i],&b[i],&w[i]);
    gen();
    for(int i=1;i<=n;i++)
        s[t[i]]+=a[i],ans[i]=a[i];
    int x=1;
    ll sum=0;
    if(s[t[1]]>s[t[1]^1])
    {
        s[t[1]]--;
        a[1]--;
        while(t[x]==t[1])
            x++;
    }
    int id=t[x];
    while(s[id]||sum)
    {
        if(t[x]!=id)
        {
            ll d=min(1ll*a[x],sum);
            a[x]-=d;
            sum-=d;
            s[t[x]]-=d;
        }
        else
        {
            sum+=a[x];
            s[t[x]]-=a[x];
            a[x]=0;
        }
        x=x%n+1;
    }
    ll out=1;
    for(int i=1;i<=n;i++)
        out=(out*(((ans[i]-a[i])^(1ll*i*i))%P+1))%P;
    printf("%lld\n",out);
}