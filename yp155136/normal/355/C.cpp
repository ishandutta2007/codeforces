#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100006;

LL pre[N];
int a[N];

int main ()
{
    int n,l,r,ql,qr;
    scanf("%d %d %d %d %d",&n,&l,&r,&ql,&qr);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        pre[i] = pre[i-1] + a[i];
    }
    LL ans=0;
    ans = min(pre[n]*l + (n-1)*ql,pre[n]*r + (n-1)*qr);
    for (int i=1;n>=i;i++)
    {
        int ll=i,rr=n-i;
        LL tmp=0;
        tmp = pre[i] * l + (pre[n]-pre[i])*r;
        if (ll >= rr)
        {
            ll -= rr;
            if (ll) ll--;
            tmp += ql*ll;
        }
        else
        {
            rr -= ll;
            if (rr) --rr;
            tmp += qr*rr;
        }
        ans = min(ans,tmp);
    }
    printf("%lld\n",ans);
}