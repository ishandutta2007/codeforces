#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int n,Q;

int c[N],ans[N];

void add(int x,int v)
{
    while(x)
    {
        c[x]=min(c[x],v);
        x-=x&-x;
    }
}

int query(int x)
{
    int ret=5e18;
    while(x<=n)
    {
        ret=min(ret,c[x]);
        x+=x&-x;
    }
    return ret;
}

vector<pii>v[N],q[N];

int x[N],y[N];

int st[N],top;

int calc(int l,int r)
{
    return (x[r]-x[l])*(y[l]+y[r]);
}

signed main()
{
    scanf("%lld%lld",&n,&Q);
    fill(c+1,c+n+1,5e18);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    {
        while(top&&y[i]<y[st[top]])
            top--;
        if(top)
            v[i].push_back({st[top],calc(st[top],i)});
        st[++top]=i;
    }
    top=0;
    for(int i=n;i>=1;i--)
    {
        while(top&&y[i]<y[st[top]])
            top--;
        if(top)
            v[st[top]].push_back({i,calc(i,st[top])});
        st[++top]=i;
    }
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%lld%lld",&l,&r);
        q[r].push_back({l,i});
    }
    for(int i=1;i<=n;i++)
    {
        for(auto [l,v]:v[i])
            add(l,v);
        for(auto [l,id]:q[i])
            ans[id]=query(l);
    }
    for(int i=1;i<=Q;i++)
        printf("%lld\n",ans[i]);
}