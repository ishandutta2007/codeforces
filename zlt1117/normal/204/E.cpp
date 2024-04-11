#pragma GCC optimize(2)
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
const int maxn=1e5+5;
int n,belong[maxn<<1],p[maxn<<1],fa[maxn<<1],last=1,tot=1,sz,k,rt[maxn<<1],len[maxn<<1];
char s[maxn];
bool dp[maxn<<1];
ll ans[maxn<<1];
int las[maxn<<1];
vector<int>temp[maxn<<1],vec[maxn<<1];
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
	int son[maxn<<1][26];
	inline void insert(int c)
	{
		int np=++tot,p=last;
		len[np]=len[p]+1,last=np;
		while(p&&!son[p][c])son[p][c]=np,p=fa[p];
		if(p==0)fa[np]=1;
		else
		{
			int q=son[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;
				len[nq]=len[p]+1;
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				memcpy(son[nq],son[q],sizeof(son[q]));
				while(p&&son[p][c]==q)son[p][c]=nq,p=fa[p];
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
			sum[u]=1;
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
			sum[u]=sum[x]|sum[y];
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
struct Trie
{
	int son[maxn][26],tot;
	Trie(){tot=0;}
	inline void insert(char *s,int typ)
	{
		int now=0;
		int len=strlen(s+1);
		for(int i=1;i<=len;++i)
		{
			if(!son[now][s[i]-'a'])son[now][s[i]-'a']=++tot;
			now=son[now][s[i]-'a'];
			temp[now].push_back(typ);
		}
	}
	inline void dfs(int u,int now)
	{
		for(int i=0;i<=25;++i)
		{
			if(son[u][i])
			{
				last=now;
				sam.insert(i);
				dfs(son[u][i],last);
			}
		}
		for(int i=0;i<temp[u].size();++i)tree.update(rt[now],1,n,temp[u][i]);
		vec[now]=temp[u];
	}
}trie;
inline void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs(v);
		rt[u]=tree.merge(rt[u],rt[v],1,n);
		dp[u]|=dp[v];
	}
	if(dp[u]==0)dp[u]|=(tree.query(rt[u],1,n,1,n)>=k);
}
inline void dfs2(int u,ll res)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(dp[v])dfs2(v,len[v]);
		else dfs2(v,res);
	}
	for(int i=0;i<vec[u].size();++i)
	{
		ans[vec[u][i]]+=res;
	}
}
int main()
{
	last=tot=1;
	memset(p,-1,sizeof(p));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		trie.insert(s,i);
	}
	trie.dfs(0,1);
	for(int i=tot;i>=1;--i)add(fa[i],i);
	dfs(1);
	dfs2(1,0);
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}
/*
2 2
a
ba
*/