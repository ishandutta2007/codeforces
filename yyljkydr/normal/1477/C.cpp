#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,vis[N];

struct P{
    ll x,y;
    int id;
}p[N];

bool cmp(P a,P b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

ll dis(P a,P b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool chk(P a,P b,P c)
{
    return (a.x-b.x)*(c.x-b.x)+(a.y-b.y)*(c.y-b.y)>0;
}

vector<int>v;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y),p[i].id=i;
    sort(p+1,p+n+1,cmp);
    v.push_back(1);
    vis[1]=1;
    int ok=1;
    for(int i=2;i<=n;i++)
    {
        int x=v[i-2];
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis(p[v[i-2]],p[j])>dis(p[v[i-2]],p[x]))
                x=j;
        v.push_back(x);
        vis[x]=1;
        if(i>=3)
            ok&=chk(p[v[i-1]],p[v[i-2]],p[v[i-3]]);
    }
    if(!ok)
        puts("NO");
    else
        for(auto x:v)
            printf("%d ",p[x].id);
}