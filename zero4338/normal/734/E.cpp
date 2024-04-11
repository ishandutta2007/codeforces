#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,ans;
struct graph
{
	vector<int>e[maxn];bool col[maxn];
	void link(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int cnt,vis[maxn];
	void dfs(int u,bool c)
	{
		vis[u]=cnt;
		for(int &i:e[u])if(col[i]==c&&!vis[i])dfs(i,c);
	}
}o;
struct tree
{
	vector<int>e[maxn];
	void link(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dep[maxn];
	void dfs(int u,int f)
	{
		dep[u]=dep[f]+1;
		for(int &i:e[u])if(i!=f)dfs(i,u);
	}
}v;
int main()
{
	generate_n(o.col+1,n=read(),read);
	for(int i=1;i<=n-1;i++)o.link(read(),read());
	for(int i=1;i<=n;i++)if(!o.vis[i]){o.cnt++;o.dfs(i,o.col[i]);}
	for(int i=1;i<=n;i++)
		for(int &j:o.e[i])
			if(o.vis[i]<o.vis[j])v.link(o.vis[i],o.vis[j]);
	v.dfs(1,0);
	int mx=0;
	for(int i=1;i<=o.cnt;i++)if(v.dep[i]>v.dep[mx])mx=i;
	v.dfs(mx,0);
	for(int i=1;i<=n;i++)ans=max(ans,v.dep[i]);
	printf("%d",ans/2);
	return 0;
}