#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 62;

LL _1[N],_2[N];
LL mod[N];

int get_depth(LL x)
{
    int ret=0;
    while (x)
    {
        ++ret;
        x>>=1;
    }
    --ret;
    return ret;
}

LL find_par(LL x)
{
    int d = get_depth(x);
    x -= (1LL<<d);
    x += (_1[d] + _2[d])%mod[d];
    x %= mod[d];
    x += (1LL<<d);
    LL _ = (x>>1);
    --d;
    _ -= (1LL<<d);
    _ -= (_1[d]);
    _ = (_%mod[d] + mod[d]) % mod[d];
    _ += (1LL<<d);
    return _;
}

int main ()
{
    for (int i=0;N>i;i++)
    {
        mod[i] = (1LL<<(i));
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int T;
        scanf("%d",&T);
        if (T==3)
        {
            vector<LL> v;
            LL x;
            scanf("%lld",&x);
            while (x != 1)
            {
                v.push_back(x);
                x = find_par(x);
            }
            v.push_back(1);
            for (int i=0;v.size()>i;i++)
            {
                if (i) printf(" ");
                printf("%lld",v[i]);
            }
            puts("");
        }
        else if (T==1)
        {
            LL x,k;
            scanf("%lld %lld",&x,&k);
            int depth = get_depth(x);
            k = (k%mod[depth] + mod[depth]) % mod[depth];
            _1[depth] += k;
            _1[depth] %= mod[depth];
        }
        else if (T==2)
        {
            LL x,k;
            scanf("%lld %lld",&x,&k);
            int depth = get_depth(x);
            k = (k%mod[depth] + mod[depth]) % mod[depth];
            _2[depth] += k;
            _2[depth] %= mod[depth];
        }
    }
}