#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
bool deb;
const int maxn=2e5+5;
int n,q;
int nk;
struct graph
{
	vector<int>e[maxn];
	void link(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int fa[maxn],dep[maxn],sum[maxn],sonn[maxn],dfn[maxn],tim,eu[maxn<<1];
	void dfs(int u,int f)
	{
		fa[u]=f;
		dfn[u]=++tim;eu[tim]=u;
		sonn[u]=e[u].size()-(f>0);
		sum[u]=sum[f]+sonn[u];
		dep[u]=dep[f]+1;
		for(int &i:e[u])if(i!=f)dfs(i,u),eu[++tim]=u;
	}
	int st[21][maxn<<1];
	int mind(int &a,int &b){return dep[a]<dep[b]?a:b;}
	void prework()
	{
		for(int i=1;i<=tim;i++)st[0][i]=eu[i];
		for(int i=1;(1<<i)<=tim;i++)
			for(int j=1;j+(1<<i)-1<=tim;j++)
				st[i][j]=mind(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int lca(int x,int y)
	{
		x=dfn[x];y=dfn[y];if(x>y)swap(x,y);
		int k=log2(y-x+1);return mind(st[k][x],st[k][y-(1<<k)+1]);
	}
}o;
struct vtree
{
	vector<int>e[maxn];
	void link(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int sta[maxn],top;
	vector<int>node;
	void build()
	{
		sort(node.begin(),node.end(),[](int &a,int &b){return o.dfn[a]<o.dfn[b];});
		top=0;sta[++top]=1;
		vector<int>tmp;
		for(int &i:node)
		{
			int fa=o.lca(sta[top],i);tmp.push_back(fa);
			if(fa!=sta[top])
			{
				while(o.dfn[fa]<o.dfn[sta[top-1]])link(sta[top-1],sta[top]),top--;
				if(o.dfn[fa]>o.dfn[sta[top-1]])link(fa,sta[top]),sta[top]=fa;
				else link(fa,sta[top]),top--;
			}
			sta[++top]=i;
		}
		for(int i=1;i<=top-1;i++)link(sta[i],sta[i+1]);
		for(int &i:tmp)node.push_back(i);node.push_back(1);
		sort(node.begin(),node.end(),[](int &a,int &b){return o.dfn[a]<o.dfn[b];});
		node.resize(unique(node.begin(),node.end())-node.begin());
	}
	int f[maxn];
	void dfs(int u,int fa)
	{
		f[u]=o.sonn[u]-nk-1;
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			int val=f[i]+o.sum[o.fa[i]]-o.sum[u]-(o.dep[o.fa[i]]-o.dep[u])*(nk+1);
			if(val>0)f[u]+=val;
		}
	}
	int query(int u)
	{
		if(o.dfn[node.back()]<o.dfn[u])return o.sonn[u];
		auto it=lower_bound(node.begin(),node.end(),u,[](int a,int b){return o.dfn[a]<o.dfn[b];});
		if(o.lca(*it,u)!=u)return o.sonn[u];
		if(*it==u)return f[u]+nk+1;
		return max(o.sonn[u],f[*it]+o.sum[o.fa[*it]]-o.sum[u]-(o.dep[o.fa[*it]]-o.dep[u])*(nk+1)+o.sonn[u]);
	}
}v;
vector<pair<int,int>>ask[maxn];
int ans[maxn];
int id[maxn];
signed main()
{
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		o.link(x,y);
	}
	o.dfs(1,0);o.prework();
	q=read();
	for(int i=1;i<=q;i++)
	{
		int v=read();
		ask[read()].push_back({v,i});
	}
	for(int i=1;i<=n;i++)id[i]=i;sort(id+1,id+n+1,[](int &a,int &b){return o.sonn[a]>o.sonn[b];});
	for(int i=0;i<=2e5;i++)
	{
		if(ask[i].empty())continue;
		nk=i;
		for(int j=1;j<=n;j++)
		{
			if(o.sonn[id[j]]<=i+1)break;
			if(id[j]!=1)v.node.push_back(id[j]);
		}
		v.build();v.dfs(1,0);
		for(auto &j:ask[i])ans[j.second]=v.query(j.first);
		for(int &j:v.node)v.e[j].clear();v.node.clear();
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}