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
const int maxn=2e5+5;
int n;
vector<int>p[32];
struct graph
{
	vector<int>e[maxn];
	void link(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	vector<int>depp[maxn];
	int md;
	void dfs(int u,int fa,int dep)
	{
		md=max(md,dep);
		depp[dep].push_back(u);
		for(int &i:e[u])if(i!=fa)dfs(i,u,dep+1);
	}
}o;
int id[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)o.e[i].clear();
		for(int i=1;i<=n-1;i++)o.link(read(),read());
		for(int i=1;i<=n;i++)p[__builtin_clz(i)].push_back(i);
		o.md=0;o.dfs(1,0,1);
		for(int i=1;i<=32;i++)
		{
			if(!p[i].size())continue;
			int cnt=0;
			for(int j=1;j<=o.md;j++)if(j&1)cnt+=o.depp[j].size();
			bool use=0;
			if(cnt>=p[i].size())use=1;
			for(int j=1;j<=o.md;j++)
			{
				if((j&1)==use)
				{
					while(!p[i].empty()&&!o.depp[j].empty())
					{
						id[o.depp[j].back()]=p[i].back();
						p[i].pop_back();
						o.depp[j].pop_back();
					}
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",id[i]);printf("\n");
	}
	return 0;
}//