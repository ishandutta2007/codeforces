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
const int maxn=105;
int n;
bool sa[maxn][maxn][maxn];
int d[maxn];
struct dsu
{
	int fa[maxn];
	void init(){iota(fa+1,fa+n+1,1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	bool merge(int x,int y)
	{
		x=get(x);y=get(y);
		if(x==y)return false;
		fa[x]=y;return true;
	}
	bool check(int x,int y){return get(x)==get(y);}
}S;
int getdep(int u)
{
	S.init();
	int ret=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(sa[u][i][j]&&S.merge(i,j))ret--;
	return ret;
}
vector<pair<int,int>>ans;
vector<int>getsa(int u,int to)
{
	vector<int>ret;
	for(int i=1;i<=n;i++)if(sa[u][to][i])ret.push_back(i);
	return ret;
}
bool dfs(int u,int fa)
{
	if(!S.merge(u,fa))return false;
	ans.push_back({u,fa});
	vector<int>to=getsa(u,fa);
	for(int &i:to)if(i!=fa&&!dfs(i,u))return false;
	return true;
}
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	void clear(){for(int i=1;i<=n;i++)e[i].clear();}
	int dep[maxn];
	void dfs(int u,int fa)
	{
		dep[u]=dep[fa]+1;
		for(int &i:e[u])if(i!=fa)dfs(i,u);
	}
}o;
bool check()
{
	if(ans.size()!=n-1)return false;
	S.init();
	for(auto&[x,y]:ans)if(!S.merge(x,y))return false;
	o.clear();
	for(auto&[x,y]:ans)o.add(x,y);
	for(int i=1;i<=n;i++)
	{
		o.dfs(i,0);
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((o.dep[j]==o.dep[k])!=sa[i][j][k])
				{
				
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=n-i;j++)
			{
				string s;cin>>s;
				for(int k=0;k<n;k++)
				{
					if(s[k]=='1')
					{
						sa[k+1][i][i+j]=sa[k+1][i+j][i]=true;
					}
					else sa[k+1][i][i+j]=sa[k+1][i+j][i]=false;
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)sa[i][j][j]=true;
		vector<int>mdp;int val=1e9;
		for(int i=1;i<=n;i++)
		{
			d[i]=getdep(i);
			if(d[i]<val)mdp={i},val=d[i];
			else if(d[i]==val)mdp.push_back(i);
		}
		if(mdp.size()>2){puts("No");continue;}
		ans.clear();S.init();
		bool flag=true;
		if(mdp.size()==1)
		{

			for(int i=1;i<=n;i++)
				if(d[i]==val+1&&!dfs(i,mdp[0])){flag=false;break;}
			if(!check())flag=false;
			if(!flag)puts("No");
			else
			{
				puts("Yes");
				for(auto&[x,y]:ans)printf("%d %d\n",x,y);
			}
		}
		else if(mdp.size()==2)
		{
			
			S.merge(mdp[0],mdp[1]);
			ans.push_back({mdp[0],mdp[1]});
			for(int i=1;i<=n;i++)
				if(d[i]==val+1)
				{
					if(sa[mdp[0]][i][mdp[1]])
					{
						if(!dfs(i,mdp[0])){flag=false;break;}
					}
					else if(sa[mdp[1]][i][mdp[0]])
					{
						if(!dfs(i,mdp[1])){flag=false;break;}
					}
				}

			if(!check())flag=false;
			if(!flag)puts("No");
			else
			{
				puts("Yes");
				for(auto&[x,y]:ans)printf("%d %d\n",x,y);
			}
		}
	}
	return 0;
}