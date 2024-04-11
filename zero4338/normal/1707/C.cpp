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
int n,m;
class dsu
{
	private:
	int fa[maxn];
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	public:
	void init(){iota(fa+1,fa+n+1,1);}
	bool merge(int x,int y)
	{
		x=get(x);y=get(y);
		if(x==y)return false;
		fa[x]=y;return true;
	}
}S;
class graph
{
	private:
	vector<int>e[maxn];
	int son[maxn],fa[maxn],dep[maxn],top[maxn],siz[maxn];
	void getson(int u,int f)
	{
		fa[u]=f;siz[u]=1;
		for(int &i:e[u])
		{
			if(i==f)continue;
			dep[i]=dep[u]+1;
			getson(i,u);
			if(siz[i]>siz[son[u]])son[u]=i;
			siz[u]+=siz[i];
		}
	}
	void getroad(int u,int ance)
	{
		top[u]=ance;
		if(son[u])getroad(son[u],ance);
		for(int &i:e[u])if(i!=fa[u]&&i!=son[u])getroad(i,i);
	}
	public:
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	void build(){getson(1,0);getroad(1,1);}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int sid(int x,int y)
	{
		int ret=0;
		while(top[y]!=top[x])
		{
			ret=top[y];
			y=fa[top[y]];
		}
		if(y!=x)return son[x];
		return ret;
	}
	int mark[maxn];
	void dfs(int u,int f=0){for(int &i:e[u])if(i!=f)mark[i]+=mark[u],dfs(i,u);}
}o;
vector<pair<int,int>>out;
int main()
{
	n=read();m=read();
	S.init();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(S.merge(u,v))o.add(u,v);
		else out.emplace_back(u,v);
	}
	o.build();
	for(auto&[u,v]:out)
	{
		int lf=o.lca(u,v);
		if(lf==v)swap(u,v);
		if(lf==u){o.mark[o.sid(u,v)]++;o.mark[v]--;}
		else{o.mark[1]++;o.mark[u]--;o.mark[v]--;}
	}
	o.dfs(1);
	for(int i=1;i<=n;i++)putchar(o.mark[i]==0?'1':'0');
	putchar('\n');
	return 0;
}