#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<pii,int>idx;

struct T{
	int ls,rs,l,r,mx,tag,mn;
};

struct G{
	vector<pii>g[N];

	int st[N],ed[N],son[N],dc,cnt,val[N],rev[N],dep[N];

	int pos[N];

	void add(int x,int y,int w)
	{
		g[x].push_back(mp(y,w));
		g[y].push_back(mp(x,w));
	}

	void dfs(int x,int f)
	{
		st[x]=++dc;
		rev[dc]=x;
		dep[x]=dep[f]+1;
		for(auto [v,w]:g[x])
		{
			if(v==f)
				continue;
			pos[idx[mp(min(x,v),max(x,v))]]=v;
			val[v]=val[x]^w;
			dfs(v,x);
		}
		ed[x]=dc;
	}

	T t[N*2+1];	

	void update(int x)
	{
		t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
		t[x].mn=max(t[t[x].ls].mn,t[t[x].rs].mn);
	}

	void pushdown(int x)
	{
		if(t[x].tag!=1)
		{
			t[t[x].ls].tag*=-1;
			t[t[x].rs].tag*=-1;
			swap(t[t[x].ls].mn,t[t[x].ls].mx);
			swap(t[t[x].rs].mn,t[t[x].rs].mx);
			t[x].tag=1;
		}
	}

	int build(int l,int r)
	{
		int x=++cnt;
		t[x].l=l,t[x].r=r;
		t[x].tag=1;
		if(l==r)
		{
			t[x].mx=dep[rev[l]]*(val[rev[l]]^1);
			t[x].mn=dep[rev[l]]*(val[rev[l]]);
			return x;
		}
		int mid=(l+r)>>1;
		t[x].ls=build(l,mid);
		t[x].rs=build(mid+1,r);
		update(x);
		return x;
	}

	void change(int x,int l,int r,int v)
	{
		if(l<=t[x].l&&t[x].r<=r)
		{
			swap(t[x].mx,t[x].mn);
			t[x].tag*=v;
			return;
		}
		pushdown(x);
		int mid=(t[x].l+t[x].r)>>1;
		if(l<=mid)
			change(t[x].ls,l,r,v);
		if(r>mid)
			change(t[x].rs,l,r,v);
		update(x);
	}

	void modify(int e)
	{
		int p=pos[e];
		change(1,st[p],ed[p],-1);
	}
}Tr[2];

vector<int>g[N];

int d[N];

void dfs(int x,int f)
{
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		d[v]=d[x]+1;
		dfs(v,x);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(v);
		g[v].push_back(u);
		Tr[0].add(u,v,w);
		Tr[1].add(u,v,w);
		idx[mp(min(u,v),max(u,v))]=i;
	}
	dfs(1,0);
	int p=max_element(d+1,d+n+1)-d;
	dfs(p,0);
	int q=max_element(d+1,d+n+1)-d;
	Tr[0].dfs(p,0);
	Tr[0].build(1,n);
	Tr[1].dfs(q,0);
	Tr[1].build(1,n);
	// printf("%d %d\n",p,q);
	scanf("%d",&q);
	while(q--)
	{
		int e;
		scanf("%d",&e);
		Tr[0].modify(e);
		Tr[1].modify(e);
		printf("%d\n",max(Tr[0].t[1].mx,Tr[1].t[1].mx)-1);
	}
}