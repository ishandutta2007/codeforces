#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int f[maxn],g[maxn];
	int dfn[maxn],fa[maxn],tim;
	void dfs(int u,int f)
	{
		dfn[u]=++tim;
		fa[tim]=dfn[f];
		for(int &i:e[u])if(i!=f)dfs(i,u);
	}
	int ans[maxn];
	int calc(int lim)
	{
		if(ans[0]!=-1)memset(ans,-1,sizeof ans);
		if(~ans[lim])return ans[lim];
		int ret=0;
		memset(f,0,sizeof(int)*(n+1));
		memset(g,0,sizeof(int)*(n+1));
		for(int i=n;i>=1;i--)
		{
			if(f[i]+g[i]+1>=lim)ret++;
			else
			{
				f[fa[i]]=max(f[fa[i]],g[i]+1);
				if(f[fa[i]]>g[fa[i]])swap(f[fa[i]],g[fa[i]]);
			}
		}
		return ans[lim]=ret;
	}
}o;
int main()
{
	n=read();
	for(int i=1;i<n;i++)o.add(read(),read());
	o.dfs(1,0);
	int cur=1,blo=sqrt(n*log2(n));
	for(int i=1;i<=blo;i++)printf("%d\n",o.calc(i));
	cur=blo+1;
	while(cur<=n)
	{
		int to=cur,nval=o.calc(cur);
		int nl=cur,nr=n;
		while(nl<=nr)
		{
			int mid=(nl+nr)>>1;
			if(o.calc(mid)==nval)nl=mid+1,to=mid;
			else nr=mid-1;
		}
		for(int i=cur;i<=to;i++)printf("%d\n",nval);
		cur=to+1;
	}
	return 0;
}