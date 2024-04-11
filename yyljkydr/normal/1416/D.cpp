#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,Q,m;

int p[N];

int a[N],b[N];

struct Query{
	int t,x;
}q[N];

int nd,fa[N],del[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int rt[N];

vector<int>g[N];

int vis[N];

int st[N],ed[N],dc,rev[N];

void dfs(int x)
{
	if(vis[x])
		return;
	st[x]=++dc;
	vis[x]=1;
	rev[st[x]]=x;
	for(auto v:g[x])
		dfs(v);
	ed[x]=dc;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int cnt;

struct T{
	int ls,rs,l,r;
	pii mx;
}t[N*2+1];

void update(int x)
{
	t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].mx=mp(p[rev[l]],l);
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int p,int v)
{
	if(t[x].l==t[x].r)
	{
		t[x].mx.fs=v;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		change(t[x].ls,p,v);
	else
		change(t[x].rs,p,v);
	update(x);
}

pii query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].mx;
	int mid=(t[x].l+t[x].r)>>1;
	pii mx=mp(0,0);
	if(l<=mid)
		mx=max(mx,query(t[x].ls,l,r));
	if(r>mid)
		mx=max(mx,query(t[x].rs,l,r));
	return mx;
}

int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&q[i].t,&q[i].x);
		if(q[i].t==2)
			del[q[i].x]=1;
	}
	nd=n;
	for(int i=1;i<=m;i++)
		if(!del[i])
		{
			int fx=find(a[i]),fy=find(b[i]);
			if(fx==fy)
				continue;
			++nd;
			g[nd].push_back(fx);
			g[nd].push_back(fy);
			fa[fx]=fa[fy]=fa[nd]=nd;
		}
	for(int i=Q;i>=1;i--)
	{
		if(q[i].t==2)
		{
			int fx=find(a[q[i].x]),fy=find(b[q[i].x]);
			if(fx==fy)
				continue;
			++nd;
			g[nd].push_back(fx);
			g[nd].push_back(fy);
			fa[fx]=fa[fy]=fa[nd]=nd;
		}
		else
			rt[i]=find(q[i].x);
	}
	for(int i=nd;i>=1;i--)
		dfs(i);
	build(1,nd);
	for(int i=1;i<=Q;i++)
	{
		if(q[i].t==1)
		{
			pii ans=query(1,st[rt[i]],ed[rt[i]]);
			printf("%d\n",ans.fs);
			if(ans.sd)
				change(1,ans.sd,0);
		}
	}
}