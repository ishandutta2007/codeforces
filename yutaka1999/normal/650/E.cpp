#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#include <map>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,P> PP;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
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
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
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
vector <int> vec[SIZE];
vector <int> vec2[SIZE];
int l1[SIZE],r1[SIZE];
int l2[SIZE],r2[SIZE];
int dep[SIZE],par[SIZE];
int dep2[SIZE],par2[SIZE];
int f2[SIZE],t2[SIZE];
vector <PP> ans;
set <P> org;

void dfs(int v=0,int p=-1,int d=0)
{
	par[v]=p;
	dep[v]=d;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,d+1);
	}
}
void dfs2(int v=0,int p=-1,int d=0)
{
	par2[v]=p;
	dep2[v]=d;
	for(int i=0;i<vec2[v].size();i++)
	{
		int to=vec2[v][i];
		if(to!=p) dfs2(to,v,d+1);
	}
}
void solve(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) solve(to,v);
	}
	if(p!=-1&&!uf.same(v,p))
	{
		int t=uf.find(v);
		ans.push_back(PP(P(v,p),P(f2[t],t2[t])));
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&l1[i],&r1[i]);
		l1[i]--,r1[i]--;
		if(l1[i]>r1[i]) swap(l1[i],r1[i]);
		org.insert(P(l1[i],r1[i]));
		vec[l1[i]].push_back(r1[i]);
		vec[r1[i]].push_back(l1[i]);
	}
	uf.init(n+2);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&l2[i],&r2[i]);
		l2[i]--,r2[i]--;
		if(l2[i]>r2[i]) swap(l2[i],r2[i]);
		if(org.count(P(l2[i],r2[i]))) uf.unite(l2[i],r2[i]);
		vec2[l2[i]].push_back(r2[i]);
		vec2[r2[i]].push_back(l2[i]);
	}
	dfs();
	dfs2();
	for(int i=1;i<n;i++)
	{
		if(!uf.same(i,par2[i]))
		{
			f2[uf.find(i)]=i;
			t2[uf.find(i)]=par2[i];
		}
	}
	solve();
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		P p=ans[i].first,q=ans[i].second;
		printf("%d %d %d %d\n",p.first+1,p.second+1,q.first+1,q.second+1);
	}
	return 0;
}