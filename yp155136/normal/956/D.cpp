#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long LL;
typedef pair<int,int> pii;
const int N = 100006;

ld _1[N],_2[N];

ld val(int x,int y)
{
    int gcd = __gcd(abs(x),abs(y));
    x /= gcd;
    y /= gcd;
    if (x<0)
    {
        x = -x;
        y = -y;
    }
    ld _ = 1.0;
    return x * _ / y;
}

struct BIT
{
    static const int N = 100006;
    int a[N];
    int n;
    void init(int _n)
    {
        n = _n;
        memset(a,0,sizeof(a));
    }
    void update(int pos,int val)
    {
        for (int i=pos;n>=i;i+=i&(-i))
        {
            a[i] += val;
        }
    }
    int query(int pos)
    {
        int ret=0;
        for (int i=pos;i>0;i-=i&(-i))
        {
            ret += a[i];
        }
        return ret;
    }
    int queryLR(int l,int r)
    {
        return query(r) - query(l-1);
    }
} bit;

int main ()
{
    int n,w;
    scanf("%d %d",&n,&w);
    vector<ld> v1,v2;
    for (int i=1;n>=i;i++)
    {
        int x,v;
        scanf("%d %d",&x,&v);
        //case 1 --> (x / (v - w))
        _1[i] = val(x,v-w);
        v1.push_back(_1[i]);
        //case 2 --> (x / (v + w))
        _2[i] = val(x,v+w);
        v2.push_back(_2[i]);
    }
    sort(v1.begin(),v1.end());
    v1.resize(unique(v1.begin(),v1.end()) - v1.begin());
    sort(v2.begin(),v2.end());
    v2.resize(unique(v2.begin(),v2.end()) - v2.begin());
    bit.init(n);
    vector<pii> v;
    for (int i=1;n>=i;i++)
    {
        pii p;
        p.first = lower_bound(v1.begin(),v1.end(),_1[i]) - v1.begin() + 1;
        p.second = lower_bound(v2.begin(),v2.end(),_2[i]) - v2.begin() + 1;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),[](const pii &p1,const pii &p2)
    {
        return make_pair(p1.first , -p1.second) < make_pair(p2.first,-p2.second);
    });
    long long ans=0;
    for (pii p:v)
    {
        ans += bit.queryLR(p.second,n);
        bit.update(p.second,1);
    }
    printf("%lld\n",ans);
}