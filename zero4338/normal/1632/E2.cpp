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
const int maxn=3e5+5;
int n;
int ans[maxn];
int id[maxn];
struct graph
{
	vector<int>e[maxn];
	void clear(){for(int i=1;i<=n;i++)e[i].clear();}
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dep[maxn],fa[maxn],top[maxn],siz[maxn],son[maxn];
	void getdep(int u,int f)
	{
		dep[u]=dep[f]+1;siz[u]=1;fa[u]=f;son[u]=0;
		for(int &i:e[u])
		{
			if(i==f)continue;
			getdep(i,u);
			siz[u]+=siz[i];
			if(siz[i]>siz[son[u]])son[u]=i;
		}
	}
	void getroad(int u,int ance)
	{
		top[u]=ance;
		if(son[u])getroad(son[u],ance);
		for(int &i:e[u])if(i!=fa[u]&&i!=son[u])getroad(i,i);
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
}o;
int main()
{
	T=read();
	while(T--)
	{
		n=read();o.clear();
		for(int i=1;i<n;i++)o.add(read(),read());
		o.getdep(1,0);o.getroad(1,1);
		iota(id+1,id+n+1,1);id[n+1]=0;
		sort(id+1,id+n+1,[&](const int &i,const int &j){return o.dep[i]>o.dep[j];});
		int d0=id[1],d1=id[1],ldis=0;
		for(int i=1;i<=n;i++)ans[i]=n;
		for(int i=1;i<=n;i++)
		{
			int dis0=o.dis(id[i],d0),dis1=o.dis(id[i],d1);
			if(dis0>=dis1&&dis0>=ldis)d1=id[i],ldis=dis0;
			else if(dis1>=dis0&&dis1>=ldis)d0=id[i],ldis=dis1;
			if(o.dep[id[i]]!=o.dep[id[i+1]]&&o.dep[id[i]]-2-(ldis+1)/2>0)
				ans[o.dep[id[i]]-2-(ldis+1)/2]=o.dep[id[i]]-2;
		}
		for(int i=n-1;i>=1;i--)ans[i]=min(ans[i],ans[i+1]);
		int md=*max_element(o.dep+1,o.dep+n+1)-1;
		for(int i=1;i<=n;i++)ans[i]=min(ans[i],md);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);putchar('\n');
	}
	return 0;
}