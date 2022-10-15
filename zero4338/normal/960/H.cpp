#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e4+5;
int n,m,q,C,cost[maxn],col[maxn];
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dep[maxn],dfn[maxn],tim,eu[maxn<<1],Lg2[maxn<<1],st[21][maxn<<1];
	void dfs(int u,int f)
	{
		dep[u]=dep[f]+1;
		dfn[u]=++tim;eu[tim]=u;
		for(int &i:e[u])
			if(i!=f)
			{
				dfs(i,u);
				eu[++tim]=u;
			}
	}
	int mind(const int &x,const int &y){return dep[x]<dep[y]?x:y;}
	void prework()
	{
		for(int i=1;i<=tim;i++)st[0][i]=eu[i];
		for(int i=2;i<=tim;i++)Lg2[i]=Lg2[i>>1]+1;
		for(int i=1;(1<<i)<=tim;i++)
			for(int j=1;j+(1<<i)-1<=tim;j++)
				st[i][j]=mind(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int lca(int x,int y)
	{
		x=dfn[x];y=dfn[y];
		if(x>y)swap(x,y);int k=Lg2[y-x+1];
		return mind(st[k][x],st[k][y-(1<<k)+1]);
	}
	int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
	bool vis[maxn];int siz[maxn],maxp[maxn],nodenum,rt;
	void getrt(int u,int fa)
	{
		siz[u]=1;maxp[u]=0;
		for(int &i:e[u])
		{
			if(vis[i]||i==fa)continue;
			getrt(i,u);
			siz[u]+=siz[i];
			maxp[u]=max(maxp[u],siz[i]);
		}
		maxp[u]=max(maxp[u],nodenum-siz[u]);
		if(maxp[u]<maxp[rt])rt=u;
	}
}o;
struct dct
{
	int fa[maxn];
	ll depsum[maxn],dissum[maxn];int num[maxn];
	map<pair<int,int>,pair<int,ll>>val[maxn];
	void build(int u)
	{
		o.vis[u]=1;
		for(int &i:o.e[u])
		{
			if(o.vis[i])continue;
			o.rt=0;o.maxp[0]=n;o.nodenum=o.siz[i];
			o.getrt(i,u);
			fa[o.rt]=u;build(o.rt);
		}
	}
	void insert(int x,int c)
	{
		num[c]++;
		depsum[c]+=o.dep[x];
		int now=x,ls=0;
		while(now)
		{
			dissum[c]+=(val[now][{now,c}].first-val[now][{ls,c}].first)*o.dis(x,now)+val[now][{now,c}].second-val[now][{ls,c}].second;
			val[now][{now,c}].first++;
			val[now][{now,c}].second+=o.dis(x,now);
			if(ls)
			{
				val[now][{ls,c}].first++;
				val[now][{ls,c}].second+=o.dis(x,now);		
			}
			ls=now;now=fa[now];
		}
	}
	void del(int x,int c)
	{
		num[c]--;
		depsum[c]-=o.dep[x];
		int now=x,ls=0;
		while(now)
		{
			dissum[c]-=(val[now][{now,c}].first-val[now][{ls,c}].first)*o.dis(x,now)+val[now][{now,c}].second-val[now][{ls,c}].second;
			val[now][{now,c}].first--;
			val[now][{now,c}].second-=o.dis(x,now);
			if(ls)
			{
				val[now][{ls,c}].first--;
				val[now][{ls,c}].second-=o.dis(x,now);		
			}
			ls=now;now=fa[now];
		}
	}
	double query(int c){return 1.0*C*C-2.0*C*cost[c]*depsum[c]/n+1.0*cost[c]*cost[c]/n*(num[c]*depsum[c]-dissum[c]);}
}v;
int main()
{
	n=read();m=read();q=read();C=read();
	generate_n(col+1,n,read);
	for(int i=2;i<=n;i++)o.add(read(),i);
	generate_n(cost+1,m,read);
	o.dfs(1,0);o.prework();
	o.maxp[0]=n;o.nodenum=n;o.getrt(1,0);v.build(o.rt);
	for(int i=1;i<=n;i++)v.insert(i,col[i]);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),w=read();
			v.del(x,col[x]);
			col[x]=w;
			v.insert(x,col[x]);
		}
		else printf("%.12lf\n",v.query(read()));
	}
	return 0;
}