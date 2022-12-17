#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=3e5+5;
int n,q,p[maxn<<1],fa[maxn<<1],last,tot,sz,rt[maxn<<1],st[maxn<<1],real[maxn<<1];
char s[maxn];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<2];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
struct SAM
{
	int ch[maxn<<1][26],len[maxn<<1];
	inline void insert(int c)
	{
		int np=++tot,p=last;
		last=np,len[np]=len[p]+1;
		while(!ch[p][c]&&p)ch[p][c]=np,p=fa[p];
		if(!p)fa[np]=1;
		else
		{ 
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;
				len[nq]=len[p]+1;
				memcpy(ch[nq],ch[q],sizeof(ch[nq]));
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				while(p&&ch[p][c]==q)ch[p][c]=nq,p=fa[p];
			}
		}
	}
}sam;
struct seg
{
	int tot;
	int sum[maxn*40],ls[maxn*40],rs[maxn*40];
	seg(){tot=0;}
	inline void pushup(int u)
	{
		sum[u]=sum[ls[u]]+sum[rs[u]];
	}
	inline void update(int &u,int l,int r,int x)
	{
		if(!u)u=++tot;
		if(l==r)
		{
			sum[u]++;
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			if(x<=mid)update(ls[u],l,mid,x);
			else update(rs[u],mid+1,r,x);
			pushup(u);
		}
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(!u)return 0;
		else if(x<=l&&y>=r)return sum[u];
		else
		{
			int mid=(l+r)>>1;
			int ret=0;
			if(x<=mid)ret+=query(ls[u],l,mid,x,y);
			if(y>mid)ret+=query(rs[u],mid+1,r,x,y);
			return ret;
		}
	}
	inline int merge(int x,int y,int l,int r)
	{
		int u=++tot;
		if(!x||!y)return x+y;
		if(l==r)///!!!
		{
			sum[u]=sum[x]+sum[y];
			return u;
		}
		else
		{
			int mid=(l+r)>>1;
			ls[u]=merge(ls[x],ls[y],l,mid);
			rs[u]=merge(rs[x],rs[y],mid+1,r); 
			pushup(u);
		}
		return u;
	}
}tree;
inline void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(sam.len[u]==sam.len[v])real[v]=real[u];///
		else real[v]=v; 
		dfs(v);
		rt[u]=tree.merge(rt[u],rt[v],1,n);
	}
}
int main()
{
	last=tot=1;
	memset(p,-1,sizeof(p));
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		last=1;
		for(int j=1;s[j];++j)sam.insert(s[j]-'a'),tree.update(rt[last],1,n,i);///last
		st[i]=last;///!!! not the tot
	}
	for(int i=1;i<=tot;++i)add(fa[i],i);
	real[1]=1;
	dfs(1);
	for(int i=1;i<=q;++i)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);///real==>the same 
		printf("%d\n",tree.query(rt[real[st[k]]],1,n,l,r));
	}
	return 0;
}