#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
int n;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	struct data
	{
		vector<int>val;
		int& operator [](int &i){return val[val.size()-i-1];}
		void push(int x){val.push_back(x);}
		int size(){return val.size();}
		friend void swap(data &a,data &b){swap(a.val,b.val);}
	}d[maxn];
	int f[maxn];
	void dfs(int u,int fa)
	{
		f[u]=-1;
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			if(d[i].size()>d[u].size())swap(d[u],d[i]),f[u]=f[i];
			for(int j=0;j<d[i].size();j++)
			{
				d[u][j]+=d[i][j];
				if(d[u][j]>d[u][f[u]]||(d[u][j]==d[u][f[u]]&&j<f[u]))f[u]=j;
			}
		}
		f[u]++;d[u].push(1);
		if(d[u][f[u]]==1)f[u]=0;
	}
}o;
int main()
{
	n=read();
	for(int i=1;i<=n-1;i++)o.add(read(),read());
	o.dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",o.f[i]);
	return 0;
}