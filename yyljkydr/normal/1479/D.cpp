#include<bits/stdc++.h>
using namespace std;

const int N=6e5+1e3+7,B=500;

struct Query{
    int u,v,a,b;
    int p;
    int id;
    int l,r;
}q[N];

int ans[N];

int n,m;

vector<int>g[N];

int a[N],cnt[N],st[N],ed[N],totw,anc[N][21],dep[N],rev[N];

void dfs(int x,int f)
{
    st[x]=++totw;
    rev[totw]=x;
    anc[x][0]=f;
    dep[x]=dep[f]+1;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
    }
    ed[x]=++totw;
    rev[totw]=x;
}

void pre()
{
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

bool cmp(Query x,Query y)
{
    if(x.l/B!=y.l/B)
        return x.l/B<y.l/B;
    return x.r<y.r;
}

int vis[N],vg[N];

void update(int x)
{
    int val=a[rev[x]];
    vis[val]^=1;
    if(vis[val])
        vg[val/B]++;
    else
        vg[val/B]--;
}

int query(int l,int r)
{
    if(l/B==r/B)
    {
        for(int i=l;i<=r;i++)
            if(vis[i])
                return i;
        return -1;
    }
    else
    {
        while(l%B!=0)
            if(vis[l])
                return l;
            else
                l++;
        int L=l/B;
        while(r%B!=B-1)
            if(vis[r])
                return r;
            else
                r--;
        int R=r/B;
        for(int i=L;i<=R;i++)
            if(vg[i])
            {
                for(int j=i*B;j<(i+1)*B;j++)
                    if(vis[j])
                        return j;
            }
        return -1;
    }
}

int main()
{  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    pre();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&q[i].u,&q[i].v,&q[i].a,&q[i].b);
        q[i].id=i;
        if(st[q[i].u]>st[q[i].v])
            swap(q[i].u,q[i].v);
        q[i].p=lca(q[i].u,q[i].v);
        if(q[i].p==q[i].u)
            q[i].l=st[q[i].u],q[i].r=st[q[i].v];
        else
            q[i].l=ed[q[i].u],q[i].r=st[q[i].v];
    }
    sort(q+1,q+m+1,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(l<q[i].l)
			update(l),l++;
		while(l>q[i].l)
			l--,update(l);
		while(r<q[i].r)
			r++,update(r);
		while(r>q[i].r)
			update(r),r--;
		if(q[i].p!=q[i].u)
			update(st[q[i].p]);
        ans[q[i].id]=query(q[i].a,q[i].b);
        if(q[i].p!=q[i].u)
			update(st[q[i].p]);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}