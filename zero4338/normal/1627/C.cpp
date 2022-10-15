#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n;
struct edge{int fr,to;}e[maxn];
struct graph
{
	vector<int>e[maxn];
	void clear(){for(int i=1;i<=n;i++)e[i].clear();}
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dep[maxn];
	void dfs(int u,int fa)
	{
		dep[u]=dep[fa]+1;
		for(int &i:e[u])
			if(i!=fa)dfs(i,u);
	}
}o;
int main()
{
	T=read();
	while(T--)
	{
		n=read();o.clear();
		for(int i=1;i<=n-1;i++)
			o.add(e[i].fr=read(),e[i].to=read());
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(o.e[i].size()>2){flag=0;break;}
		if(!flag)puts("-1");
		else
		{
			for(int i=1;i<=n;i++)
				if(o.e[i].size()==1){o.dfs(i,0);break;}
			for(int i=1;i<=n-1;i++)
			{
				if(min(o.dep[e[i].fr],o.dep[e[i].to])&1)printf("2 ");
				else printf("5 ");
			}
			putchar('\n');
		}
	}
	return 0;
}