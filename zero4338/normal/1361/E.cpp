#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(0);
int Rand(int l,int r){uniform_int_distribution<>gen(l,r);return gen(rnd);}
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n,m;
struct graph
{
	vector<int>e[maxn];
	void clear(){for(int i=1;i<=n;i++)e[i].clear();}
	void add(int x,int y){e[x].push_back(y);}
	bool vis[maxn],ins[maxn];
	bool dfs(int u)
	{
		vis[u]=1;ins[u]=1;
		for(int &i:e[u])
		{
			if(!vis[i]){if(dfs(i)){ins[u]=1;return true;}}
			else if(!ins[i]){ins[u]=0;return true;}
		}
		ins[u]=0;
		return false;
	}
	bool ans[maxn];
	int dep[maxn];
	pair<int,int>merge(pair<int,int>a,pair<int,int>b)
	{
		static int tmp[4];
		tmp[0]=a.first;tmp[1]=a.second;
		tmp[2]=b.first;tmp[3]=b.second;
		sort(tmp,tmp+4,[&](int &i,int &j){return dep[i]<dep[j];});
		return {tmp[0],tmp[1]};
	}
	pair<int,int>to[maxn];
	pair<int,int>getans1(int u)
	{
		to[u]={0,0};
		vis[u]=1;
		for(int &i:e[u])
		{
			if(!vis[i])dep[i]=dep[u]+1,to[u]=merge(to[u],getans1(i));
			else to[u]=merge(to[u],{i,0});
		}
		ans[u]=dep[to[u].second]>=dep[u];
		return to[u];
	}
	void getans2(int u)
	{
		vis[u]=1;
		for(int &i:e[u])if(vis[i])ans[u]&=ans[i];
		ans[u]&=ans[to[u].first];
		ans[u]&=ans[to[u].second];
		for(int &i:e[u])if(!vis[i])getans2(i);
	}
}o;
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		o.clear();
		for(int i=1;i<=m;i++){int u=read(),v=read();o.add(u,v);}
		int p=0;
		bool flag=0;
		memset(o.vis,0,sizeof(bool)*(n+1));
		int tim=100;
		while(tim--)
		{
			memset(o.vis,0,sizeof(bool)*(n+1));
			flag|=!o.dfs(p=Rand(1,n));
			if(flag)break;
		}
		if(!flag){puts("-1");continue;}
		o.dep[0]=n+1;o.dep[p]=0;o.ans[0]=1;
		memset(o.vis,0,sizeof(bool)*(n+1));
		o.getans1(p);
		memset(o.vis,0,sizeof(bool)*(n+1));
		o.getans2(p);
		int sum=0;
		for(int i=1;i<=n;i++)sum+=o.ans[i];
		if(sum>=ceil(n/5.0)){for(int i=1;i<=n;i++)if(o.ans[i])printf("%d ",i);putchar('\n');}
		else puts("-1");
	}
	return 0;
}