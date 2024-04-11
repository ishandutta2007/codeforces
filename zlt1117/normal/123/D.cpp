#pragma GCC optimize(4)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e5+5;
long long ans[maxn],p[maxn],sz;
char s[maxn];
long long sum=0;
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<2];
struct SAM
{
	long long fa[maxn<<1],tot,ch[maxn<<1][26],len[maxn<<1],last;///!!!
	SAM(){tot=last=1;}
	inline void insert(int c)
	{
		int np=++tot,p=last;
		len[np]=len[p]+1,last=np;
		while(p&&!ch[p][c])ch[p][c]=np,p=fa[p];
		if(p==0)fa[np]=1;
		else
		{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				len[nq]=len[p]+1;///!!!
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				while(p&&ch[p][c]==q)ch[p][c]=nq,p=fa[p];
			}
		}
		ans[np]=1;
	}
} sam;
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs(v);
		ans[u]+=ans[v];
	}
	sum+=ans[u]*(ans[u]+1)*(sam.len[u]-sam.len[sam.fa[u]])/2;
}
int main()
{
//	freopen("1.in","r",stdin);
	memset(p,-1,sizeof(p));
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)sam.insert(s[i]-'a');
	for(int i=2;i<=sam.tot;++i)add(sam.fa[i],i);
	dfs(1);
	printf("%lld\n",sum);
	return 0;
}