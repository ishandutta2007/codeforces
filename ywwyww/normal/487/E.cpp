#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<set>
using namespace std;
typedef long long ll;
list<int> l[500010];
int dfn[500010];
int low[500010];
int ti;
int c[500010];
int cnt;
int t[500010];
int vis[500010];
int st[500010];
int top;
int id[500010];
void dfs(int x,int fa)
{
	st[++top]=x;
	vis[x]=1;
	dfn[x]=low[x]=++ti;
	for(auto v:l[x])
		if(v!=fa)
		{
			if(!vis[v])
			{
				dfs(v,x);
				low[x]=min(low[x],low[v]);
				if(low[v]>=dfn[x])
				{
					cnt++;
					t[cnt]=x;
					int u;
					do
					{
						u=st[top];
						top--;
						c[u]=cnt;
					}
					while(u!=v);
				}
			}
			else
				low[x]=min(low[x],dfn[v]);
		}
}
int w[500010];
int lx[500010];
int ly[500010];
multiset<int> s[500010];
void add(int x,int y)
{
	l[x].push_back(y);
	l[y].push_back(x);
}
struct tree
{
	struct pp
	{
		int l,r,ls,rs,s;
		pp()
		{
			l=r=ls=rs=s=0;
		}
	};
	pp a[500010];
	int n,rt;
	void build(int &p,int l,int r)
	{
		p=++n;
		a[p].l=l;
		a[p].r=r;
		if(l!=r)
		{
			int mid=(l+r)>>1;
			build(a[p].ls,l,mid);
			build(a[p].rs,mid+1,r);
		}
	}
	void change(int p,int x,int v)
	{
		if(a[p].l==a[p].r)
		{
			a[p].s=v;
			return;
		}
		int mid=(a[p].l+a[p].r)>>1;
		if(x<=mid)
			change(a[p].ls,x,v);
		else
			change(a[p].rs,x,v);
		a[p].s=min(a[a[p].ls].s,a[a[p].rs].s);
	}
	int query(int p,int l,int r)
	{
		if(l<=a[p].l&&r>=a[p].r)
			return a[p].s;
		int mid=(a[p].l+a[p].r)>>1;
		int s=0x7fffffff;
		if(l<=mid)
			s=min(s,query(a[p].ls,l,r));
		if(r>mid)
			s=min(s,query(a[p].rs,l,r));
		return s;
	}
};
tree tr;
struct pp
{
	int d,f,w,t,sz,s;
	pp()
	{
		d=f=w=t=sz=s=0;
	}
};
pp a[500010];
int n,m,q;
int tcnt;
void dfs(int x,int fa,int dep)
{
	a[x].f=fa;
	a[x].d=dep;
	a[x].sz=1;
	int msz=0;
	for(auto v:l[x])
		if(v!=fa)
		{
			dfs(v,x,dep+1);
			a[x].sz+=a[v].sz;
			if(a[v].sz>msz)
			{
				a[x].s=v;
				msz=a[v].sz;
			}
		}
}
void dfs2(int x,int top)
{
	a[x].t=top;
	a[x].w=++tcnt;
	if(!a[x].s)
		return;
	dfs2(a[x].s,top);
	for(auto v:l[x])
		if(v!=a[x].f&&v!=a[x].s)
			dfs2(v,v);
}
int query(int x,int y)
{
	int s=0x7fffffff;
	while(a[x].t!=a[y].t)
		if(a[a[x].t].d>a[a[y].t].d)
		{
			s=min(s,tr.query(tr.rt,a[a[x].t].w,a[x].w));
			x=a[a[x].t].f;
		}
		else
		{
			s=min(s,tr.query(tr.rt,a[a[y].t].w,a[y].w));
			y=a[a[y].t].f;
		}
	if(a[x].d>a[y].d)
		swap(x,y);
	s=min(s,tr.query(tr.rt,a[x].w,a[y].w));
	if(x>n)
		s=min(s,w[a[x].f]);
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&lx[i],&ly[i]);
		add(lx[i],ly[i]);
	}
	cnt=0;
	top=0;
	ti=0;
	memset(c,0,sizeof c);
	dfs(1,0);
	int pcnt=n;
	for(i=1;i<=n;i++)
		l[i].clear();
	for(i=1;i<=cnt;i++)
	{
		id[i]=++pcnt;
		c[id[i]]=i;
	}
	for(i=1;i<=m;i++)
		if(c[lx[i]]!=c[ly[i]]&&lx[i]!=t[c[ly[i]]]&&ly[i]!=t[c[lx[i]]])
			add(c[lx[i]],c[ly[i]]);
	for(i=1;i<=n;i++)
		if(c[i])
		{
			add(id[c[i]],i);
			s[c[i]].insert(w[i]);
		}
	for(i=1;i<=cnt;i++)
	{
		add(t[i],id[i]);
		w[id[i]]=*s[i].begin();
	}
	tr.build(tr.rt,1,pcnt);
	tcnt=0;
	dfs(1,0,1);
	dfs2(1,1);
	for(i=1;i<=n;i++)
		tr.change(tr.rt,a[i].w,w[i]);
	for(i=1;i<=cnt;i++)
		tr.change(tr.rt,a[id[i]].w,w[id[i]]);
	char str[10];
	int x,y;
	tr.query(tr.rt,1,1);
	for(i=1;i<=q;i++)
	{
		scanf("%s%d%d",str,&x,&y);
		if(str[0]=='C')
		{
			tr.change(tr.rt,a[x].w,y);
			if(c[x])
			{
				s[c[x]].erase(s[c[x]].find(w[x]));
				s[c[x]].insert(y);
				tr.change(tr.rt,a[id[c[x]]].w,*s[c[x]].begin());
			}
			w[x]=y;
		}
		else
		{
			int ans=query(x,y);
			printf("%d\n",ans);
		}
	}
	return 0;
}