#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

struct BIT
{
    static const int N = 200006;
    LL a[N];
    int n;
    void init(int _n)
    {
        n = _n;
        memset(a,0,sizeof(a));
    }
    void update(int pos,LL val)
    {
        for (int i=pos;n>=i;i+=i&(-i))
        {
            a[i] += val;
        }
    }
    LL query(int pos)
    {
        LL ret=0;
        for (int i=pos;i>0;i-=i&(-i))
        {
            ret += a[i];
        }
        return ret;
    }
} bit;

const int N = 200006;
const int P = 32;

set<pii> st[P];

LL a[N];

void addd(LL val,int pos)
{
    if (!val) st[0].insert(make_pair(pos,val));
    else
    {
        for (int i=P-1;i>=1;i--)
        {
            if (val >= (1LL<<(i-1)))
            {
                st[i].insert(make_pair(pos,val));
                break;
            }
        }
    }
}

void dell(LL val,int pos)
{
    if (!val) st[0].erase(make_pair(pos,val));
    else
    {
        for (int i=P-1;i>=1;i--)
        {
            if (val >= (1LL<<(i-1)))
            {
                st[i].erase(make_pair(pos,val));
                break;
            }
        }
    }
}

int main ()
{
    int n,q;
    scanf("%d %d",&n,&q);
    bit.init(n);
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
        bit.update(i,a[i]);
        addd(a[i],i);
    }
    while (q--)
    {
        int p,x;
        scanf("%d %d",&p,&x);
        dell(a[p],p);
        bit.update(p,-a[p]);
        a[p] = x;
        addd(a[p],p);
        bit.update(p,a[p]);
        int ans = -1;
        for (int i=0;P>i;i++)
        {
            auto iter = st[i].begin();
            int cnt = 2;
            while (cnt--)
            {
                if (iter == st[i].end()) break;
                pii p = (*iter);
                if (bit.query(p.first - 1) == p.second)
                {
                    ans = p.first;
                    break;
                }
                ++iter;
            }
        }
        printf("%d\n",ans);
    }
}