#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int n;

struct P{
    ll a,b;
}p[N];

bool cmp(P x,P y)
{
    return x.b<y.b;
}

ll sa;

bool chk(ll c)
{
    ll t=c,lst=0,res=sa-c;
    for(int i=1;i<=n;i++)
    {
        if(!t)
            break;
        if(p[i].b>res)
            return 0;
        t-=min(t,p[i].a);
        res+=p[i].a;
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].a,&p[i].b),sa+=p[i].a;
    sort(p+1,p+n+1,cmp);
    ll l=0,r=sa+1;
    while(r-l>1)
    {
        ll mid=(l+r)>>1;
        if(chk(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%lld\n",l+(sa-l)*2);
}