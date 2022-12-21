#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define int long long
#define ll long long
#define ull unsigned long long
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
const int maxn=1e6+5;
int val[maxn];
ll dp[maxn],ans;
struct Trie
{
	int tot;
	int ch[maxn][26];
	inline void insert(string s,int v)
	{
		int now=1;
		for(int i=0;i<s.size();++i)
		{
			if(!ch[now][s[i]-'a'])
			{
				ch[now][s[i]-'a']=++tot;
			}
			now=ch[now][s[i]-'a'];
			val[now]+=v;
		}
	}
}trie;
int last=1,tot=1,fa[maxn],now[maxn],p[maxn],sz,len[maxn];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn){v=vv,nxt=nn;}
}e[maxn];
struct SAM
{
	int son[maxn][26],val[maxn];
	inline void insert(int c,int p)
	{
		int np=++tot;
		last=np,len[np]=len[p]+1;
		while(p&&!son[p][c])son[p][c]=np,p=fa[p];
		if(!p)fa[np]=1;
		else
		{
			int q=son[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;
				len[nq]=len[p]+1;
				memcpy(son[nq],son[q],sizeof(son[q]));
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				while(p&&son[p][c]==q)son[p][c]=nq,p=fa[p];
			}
		}
	}
}sam;
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs1(int u)
{
	int temp=last;
	dp[last]=val[u];
	for(int i=0;i<=25;++i)
	{
		if(trie.ch[u][i])
		{
			sam.insert(i,temp);
			dfs1(trie.ch[u][i]);
		}
	}
}
inline void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs(v);
		dp[u]+=dp[v];
	}
	ans=max(ans,dp[u]*len[u]);
}
int n;
char s[maxn];
vector<string>v;
signed main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	trie.tot=1;
	for(int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}	
	for(int i=0;i<=n-1;++i)
	{
		int va=getint(); 
		string s=v[i];
		trie.insert(s,va);
	}
	dfs1(1);
	for(int i=2;i<=tot;++i)add(fa[i],i);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}