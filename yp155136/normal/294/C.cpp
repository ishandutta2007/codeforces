#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1000000007;

LL ppow(LL a,LL n)
{
    LL ret=1,now=a;
    while (n)
    {
        if (n&1)
        {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n >>= 1;
    }
    return ret;
}

const int N = 1006;

LL f[N];

void build()
{
    f[0] = 1;
    for (int i=1;N>i;i++)
    {
        f[i] = f[i-1] * i;
        f[i] %= mod;
    }
}

LL get_rev(LL x)
{
    return ppow(x,mod-2);
}

bool sagiri[N];

LL cal(LL x,bool is_one_way)
{
    if (is_one_way) return get_rev(f[x]);
    else return (ppow(2,x-1) * get_rev(f[x]))%mod;
}

int l[N];

int main ()
{
    build();
    int n,m;
    scanf("%d %d",&n,&m);
    LL ans=1;
    for (int i=1;m>=i;i++)
    {
        int x;
        scanf("%d",&x);
        sagiri[x] = true;
    }
    LL tot_no = 0;
    for (int i=1;n>=i;i++)
    {
        tot_no += (!sagiri[i]);
    }
    ans = f[tot_no];
    int last_okay = 0;
    sagiri[n+1] = true;
    sagiri[0] = true;
    for (int i=1;n>=i;i++)
    {
        if (!sagiri[i])
        {
            if (sagiri[i-1]) l[i] = i;
            else l[i] = l[i-1];
        }
    }
    for (int i=1;n+1>=i;i++)
    {
        if (sagiri[i] && !sagiri[i-1])
        {
            int ll = l[i-1],rr = i-1;
            ans *= cal(rr - ll + 1, ( (ll == 1) || (rr==n) ) );
            ans %= mod;
        }
    }
    printf("%lld\n",ans);
}