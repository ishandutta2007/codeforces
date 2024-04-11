#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define BT 20

using namespace std;

struct edge
{
	int to,id;
	edge(int to=0,int id=0):to(to),id(id){}
};
vector <edge> vec[SIZE];
vector <int> que[SIZE];
int par[SIZE][BT],dep[SIZE];
int ans[SIZE],val[SIZE];
int n;

void dfs(int v=0,int p=-1,int d=0)
{
	par[v][0]=p;
	dep[v]=d;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) dfs(e.to,v,d+1);
	}
}
void solve(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			solve(e.to,v);
			val[v]+=val[e.to];
			ans[e.id]=val[e.to];
		}
	}
}
void make()
{
	for(int i=0;i<BT-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int lca(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]==-1) continue;
		if(dep[par[b][i]]>=dep[a]) b=par[b][i];
	}
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	if(a!=b)
	{
		a=par[a][0];
		b=par[b][0];
	}
	return a;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(edge(b,i));
		vec[b].push_back(edge(a,i));
	}
	dfs();
	make();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		int p=lca(a,b);
		val[a]++;
		val[p]--;
		val[b]++;
		val[p]--;
	}
	solve();
	for(int i=0;i<n-1;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}