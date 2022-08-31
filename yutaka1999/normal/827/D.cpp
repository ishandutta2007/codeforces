#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#define SIZE 200005
#define BT 20
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
vector <edge> vec[SIZE];
int A[SIZE],B[SIZE],C[SIZE];
int par[SIZE][BT];
int mx[SIZE][BT];
int query[SIZE][BT];
int ans[SIZE],dep[SIZE];
int n,m;

void dfs(int v=0,int p=-1,int bef=-1,int d=0)
{
	dep[v]=d;
	par[v][0]=p;
	mx[v][0]=bef;
	query[v][0]=INF;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i].to;
		if(to!=p) dfs(to,v,vec[v][i].cost,d+1);
	}
}
void build()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			query[j][i+1]=INF;
			if(par[j][i]==-1)
			{
				par[j][i+1]=-1;
				mx[j][i+1]=-1;
			}
			else
			{
				par[j][i+1]=par[par[j][i]][i];
				mx[j][i+1]=max(mx[j][i],mx[par[j][i]][i]);
			}
		}
	}
}
int LCA(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
		{
			b=par[b][i];
		}
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
int getmx(int v,int p)
{
	int ret=0;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[v][i]!=-1&&dep[par[v][i]]>=dep[p])
		{
			ret=max(ret,mx[v][i]);
			v=par[v][i];
		}
	}
	return ret;
}
void add(int v,int p,int c)
{
	for(int i=BT-1;i>=0;i--)
	{
		if(par[v][i]!=-1&&dep[par[v][i]]>=dep[p])
		{
			query[v][i]=min(query[v][i],c);
			v=par[v][i];
		}
	}
}
void pass()
{
	for(int i=BT-2;i>=0;i--)
	{
		for(int v=0;v<n;v++)
		{
			query[v][i]=min(query[v][i],query[v][i+1]);
			if(par[v][i]!=-1)
			{
				query[par[v][i]][i]=min(query[par[v][i]][i],query[v][i+1]);
			}
		}
	}
}
bool check(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	return par[b][0]==a;
}
int main()
{
	scanf("%d %d",&n,&m);
	vector <PP> vx;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
		A[i]--,B[i]--;
		vx.push_back(PP(C[i],P(A[i],B[i])));
	}
	sort(vx.begin(),vx.end());
	uf.init(n+2);
	for(int i=0;i<vx.size();i++)
	{
		P p=vx[i].second;
		if(!uf.same(p.first,p.second))
		{
			uf.unite(p.first,p.second);
			vec[p.first].push_back(edge(p.second,vx[i].first));
			vec[p.second].push_back(edge(p.first,vx[i].first));
		}
	}
	dfs();
	build();
	for(int i=0;i<m;i++)
	{
		if(!check(A[i],B[i]))
		{
			int p=LCA(A[i],B[i]);
			ans[i]=max(getmx(A[i],p),getmx(B[i],p))-1;
			add(A[i],p,C[i]);
			add(B[i],p,C[i]);
		}
	}
	pass();
	for(int i=0;i<m;i++)
	{
		if(check(A[i],B[i]))
		{
			int v=A[i];
			if(dep[A[i]]<dep[B[i]]) v=B[i];
			ans[i]=query[v][0]==INF?-1:query[v][0]-1;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}