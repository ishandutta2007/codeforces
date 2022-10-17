#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lson tr[now].l
#define rson tr[now].r
#define int long long
using namespace std;

struct tree
{
    int l,r,sum,val,ans;
}tr[5000050];

int rt[100010],cl[100010],cnt,n,anss[100010];
vector<int> g[100010];

int push_up(int now)
{
    if(tr[lson].sum>tr[rson].sum)
    {
        tr[now].sum=tr[lson].sum;
        tr[now].val=tr[lson].val;
        tr[now].ans=tr[lson].ans;
    }
    if(tr[rson].sum>tr[lson].sum)
    {
        tr[now].sum=tr[rson].sum;
        tr[now].val=tr[rson].val;
        tr[now].ans=tr[rson].ans;
    }
    if(tr[lson].sum==tr[rson].sum)
    {
        tr[now].sum=tr[lson].sum;
        tr[now].val=tr[lson].val;
        tr[now].ans=tr[lson].ans+tr[rson].ans;
    }
}

int update(int &now,int l,int r,int pos,int v)
{
    if(!now) now=++cnt;
    if(l==r)
    {
        tr[now].val=l;
        tr[now].sum+=v;
        tr[now].ans=l;
        return 0;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(lson,l,mid,pos,v);
    else update(rson,mid+1,r,pos,v);
    push_up(now);
}

int merge(int a,int b,int l,int r)
{
    if(!a) return b;
    if(!b) return a;
    if(l==r)
    {
        tr[a].val=l;
        tr[a].sum+=tr[b].sum;
        tr[a].ans=l;
        return a;
    }
    int mid=(l+r)>>1;
    tr[a].l=merge(tr[a].l,tr[b].l,l,mid);
    tr[a].r=merge(tr[a].r,tr[b].r,mid+1,r);
    push_up(a);
    return a;
}

int dfs(int now,int f)
{
    for(int i=0;i<g[now].size();i++)
    {
        if(g[now][i]==f) continue;
        dfs(g[now][i],now);
        merge(rt[now],rt[g[now][i]],1,100000);
    }
    update(rt[now],1,100000,cl[now],1);
    anss[now]=tr[rt[now]].ans;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&cl[i]);
        rt[i]=i;
        cnt++;
    }
    int from,to;
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&from,&to);
        g[from].push_back(to);
        g[to].push_back(from);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",anss[i]);
    }
}