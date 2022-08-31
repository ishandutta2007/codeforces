#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
		}
	}
	int find(int x)
	{
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[y]=x;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
int A[SIZE],B[SIZE],F[SIZE];
int C[SIZE],D[SIZE];
vector <int> vec[SIZE];
set <P> st[SIZE];
set <P>::iterator it;
bool use[SIZE];
ll sum;

void dfs(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			if(st[v].size()<st[to].size()) swap(st[v],st[to]);
			for(it=st[to].begin();it!=st[to].end();it++)
			{
				P p=*it;
				if(st[v].count(p)) st[v].erase(p);
				else st[v].insert(p);
			}
		}
	}
	if(p!=-1&&sum!=-1)
	{
		if(st[v].empty()) sum=-1;
		else
		{
			it=st[v].begin();
			sum+=it->first;
		}
	}
}
int main()
{
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	uf.init(n+2);
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&C[i],&D[i]);
		C[i]--,D[i]--;
		uf.unite(C[i],D[i]);
		vec[C[i]].push_back(D[i]);
		vec[D[i]].push_back(C[i]);
	}
	sum=0;
	ll df=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&A[i],&B[i],&F[i]);
		A[i]--,B[i]--;
		if(!uf.same(A[i],B[i]))
		{
			uf.unite(A[i],B[i]);
			vec[A[i]].push_back(B[i]);
			vec[B[i]].push_back(A[i]);
			df+=F[i];
		}
		st[A[i]].insert(P(F[i],i));
		st[B[i]].insert(P(F[i],i));
	}
	dfs();
	printf("%lld\n",sum-df);
	return 0;
}