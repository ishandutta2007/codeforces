#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+1e3+7;

int n,k;

int a[N];

int c[N];

int ans[N];

map<pair<int,int>,int >mp;

int query(int x,int y)
{
    if(mp.count({x,y}))
        return mp[{x,y}];
    mp[{x,y}]=0;
    for(int i=y;i<=x;i++)
        mp[{x,y}]^=((i&x)==i);
    return mp[{x,y}];
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int pr=a[i];
        for(int j=i;j<=n;j++)
        {
            int res=n-1-(j-i)-(i!=1)-(j!=n);
            int qk=max(k-(i!=1)-(j!=n),0ll);
            if(query(res,qk))
                ans[pr]^=1;
            if(a[j+1]>20)
                break;
            pr=pr*(1<<a[j+1]);
            if(pr>(1<<20))
                break;
        }
    }
    bool lead=1;
    for(int i=(1<<20)-1;i>=0;i--)
    {
        lead&=(!ans[i]);
        if(!lead)
            printf("%lld",ans[i]);
    }
    if(lead)
        printf("0");
    puts("");
}