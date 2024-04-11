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
int n;
int c[maxn];
struct vgraph
{
	vector<int>e[maxn];
	void add(int x,int y){e[y].push_back(x);}
	bool vis[maxn];
	void bfs()
	{
		queue<int>q;
		for(int i=1;i<=n;i++)
			if(c[i]){vis[i]=1;q.push(i);}
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int &i:e[x])
				if(!vis[i]){vis[i]=1;c[i]=1;q.push(i);}
		}
	}
}v;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int siz[maxn],all;
	void dfs(int u,int fa)
	{
		siz[u]=c[u];
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			siz[u]+=siz[i];
			if(c[i]||siz[i]>=2)v.add(u,i);
		}
		for(int &i:e[u])
		{
			if(i==fa)continue;
			if(c[u]||all-siz[i]>=2)v.add(i,u);
		}
	}
}o;
int main()
{
	generate_n(c+1,n=read(),read);
	for(int i=1;i<=n-1;i++)o.add(read(),read());
	for(int i=1;i<=n;i++)o.all+=c[i];
	o.dfs(1,0);v.bfs();
	for(int i=1;i<=n;i++)printf("%d ",c[i]);putchar('\n');
	return 0;
}