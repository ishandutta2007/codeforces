#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 998244353;

const int N = 1006;

LL ppow(LL a,LL n)
{
    LL ret=1,now=a;
    while (n)
    {
        if (n&1)
        {
            ret = (ret*now) % mod;
        }
        now = (now * now) % mod;
        n >>= 1;
    }
    return ret;
}

LL f[N],revf[N];

void build()
{
    f[0] = revf[0] = 1;
    for (int i=1;N>i;i++)
    {
        f[i] = (f[i-1] * i) % mod;
        revf[i] = ppow(f[i],mod-2);
    }
}

LL C(int n,int m)
{
    return ((f[n]*revf[m])%mod * revf[n-m]) % mod;
}

int a[N];
LL dp[N];

int main ()
{
    build();
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    dp[0] = 1;
    for (int i=1;n>=i;i++)
    {
        LL pre=0;
        for (int j=0;i>j;j++) pre+=dp[j];
        if (a[i] <= 0) continue;
        pre %= mod;
        for (int j=i+1;n>=j;j++)
        {
            if (j-i+1 >= a[i]+1)
            {
                dp[j] += pre*C(j-i-1,a[i]-1);
                dp[j] %= mod;
            }
        }
    }
    LL ans=0;
    for (int i=1;n>=i;i++)
    {
        ans += dp[i];
        //cout << "i = " << i << " , dp = " << dp[i] <<endl;
    }
    printf("%lld\n",ans%mod);
}