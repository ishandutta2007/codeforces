#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200006;

LL a[N];
LL pre[N];

int main ()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
        pre[i] = pre[i-1] + a[i];
    }
    LL now=0;
    for (int i=1;q>=i;i++)
    {
        LL k;
        scanf("%lld",&k);
        now += k;
        int ii = upper_bound(pre,pre+n+1,now) - pre;
        --ii;
        if (ii == n)
        {
            ii = 0;
            now = 0;
        }
        printf("%d\n",n - ii);
    }
}