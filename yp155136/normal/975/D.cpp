#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

pii operator-(const pii &p1,const pii &p2)
{
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}

LL cross(pii p,pii q)
{
    return p.first * q.second - p.second * q.first;
}

LL sgn(LL x)
{
    if (x==0) return 0;
    else if (x>0) return 1;
    else if (x<0) return -1;
}

int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    LL ans=0;
    map<LL,LL> mp1;
    map<pii,LL> mp2;
    for (int i=1;n>=i;i++)
    {
        LL x,vx,vy;
        scanf("%lld %lld %lld",&x,&vx,&vy);
        LL tmp = 0;
        tmp -= mp2[ make_pair(vx,vy) ];
        tmp += mp1[ a * vx - vy ];
        ans += tmp * 2;
        mp1[a*vx-vy]++;
        mp2[make_pair(vx,vy)]++;
    }
    printf("%lld\n",ans);
}