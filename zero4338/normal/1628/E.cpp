#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n,q;
struct edge{int u,v,w;}ed[maxn];
struct dsu
{
	int fa[maxn<<1];
	void prework(){iota(fa+1,fa+2*n+1,1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
struct graph
{
	vector<int>e[maxn<<1];
	void add(int x,int y){e[x].push_back(y);}
	int rt;
	int fa[maxn<<1],dfn[maxn<<1],tim,son[maxn<<1],siz[maxn<<1],top[maxn<<1],dep[maxn<<1];
	void getson(int u)
	{
		dfn[u]=++tim;siz[u]=1;
		for(int &i:e[u])
		{
			fa[i]=u;dep[i]=dep[u]+1;
			getson(i);siz[u]+=siz[i];
			if(siz[i]>siz[son[u]])son[u]=i;
		}
	}
	void getroad(int u,int ance)
	{
		top[u]=ance;
		if(son[u])getroad(son[u],ance);
		for(int &i:e[u])if(i!=son[u])getroad(i,i);
	}
	int lca(int x,int y)
	{
		assert(x&&y);
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	void build()
	{
		sort(ed+1,ed+n,[](edge &i,edge &j){return i.w<j.w;});
		S.prework();
		for(int i=1;i<n;i++)
			if(!S.check(ed[i].u,ed[i].v))
			{
				int x=S.get(ed[i].u),y=S.get(ed[i].v);
				add(n+i,x);add(n+i,y);S.merge(x,n+i);S.merge(y,n+i);
			}
		rt=S.get(1);
		getson(rt);
		getroad(rt,rt);
	}
}o;
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mip,mxp,curmip,curmxp,tag;}t[maxn<<2];
	int mind(const int &x,const int &y){if(!x||!y)return x|y;return o.dfn[x]<o.dfn[y]?x:y;}
	int maxd(const int &x,const int &y){if(!x||!y)return x|y;return o.dfn[x]>o.dfn[y]?x:y;}
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].mip=t[u].mxp=l;return;}
		int mid=(l+r)>>1;
		build(L(u),l,mid);build(R(u),mid+1,r);
		t[u].mip=mind(t[L(u)].mip,t[R(u)].mip);
		t[u].mxp=maxd(t[L(u)].mxp,t[R(u)].mxp);
	}
	void _open(int u){t[u].tag=1;t[u].curmip=t[u].mip;t[u].curmxp=t[u].mxp;}
	void _close(int u){t[u].tag=-1;t[u].curmip=t[u].curmxp=0;}
	void pushdown(int u)
	{
		if(t[u].tag)
		{
			if(t[u].tag==1)_open(L(u)),_open(R(u));
			else _close(L(u)),_close(R(u));
			t[u].tag=0;
		}
	}
	void update(int u){t[u].curmip=mind(t[L(u)].curmip,t[R(u)].curmip);t[u].curmxp=maxd(t[L(u)].curmxp,t[R(u)].curmxp);}
	void open(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){_open(u);return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=nl)open(nl,nr,L(u),l,mid);
		if(mid+1<=nr)open(nl,nr,R(u),mid+1,r);
		update(u);
	}
	void close(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){_close(u);return;}
		pushdown(u);
		int mid=(l+r)>>1;
		if(mid>=nl)close(nl,nr,L(u),l,mid);
		if(mid+1<=nr)close(nl,nr,R(u),mid+1,r);
		update(u);
	}
	#undef L
	#undef R
}tr;
int main()
{
	n=read();q=read();
	for(int i=1;i<n;i++)ed[i].u=read(),ed[i].v=read(),ed[i].w=read();
	o.build();tr.build();
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read();
			tr.open(l,r);
		}
		else if(opt==2)
		{
			int l=read(),r=read();
			tr.close(l,r);
		}
		else if(opt==3)
		{
			int x=read();
			if(!tr.t[1].curmip||(tr.t[1].curmip==tr.t[1].curmxp&&tr.t[1].curmip==x))puts("-1");
			else printf("%d\n",ed[o.lca(x,o.lca(tr.t[1].curmip,tr.t[1].curmxp))-n].w);
		}
	}
	return 0;
}