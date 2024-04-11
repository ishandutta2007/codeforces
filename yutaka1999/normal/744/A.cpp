#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1005

using namespace std;
typedef long long int ll;

struct UF
{
	int par[SIZE],nd[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			nd[i]=1;
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
		if(nd[x]<nd[y]) swap(x,y);
		par[y]=x;
		nd[x]+=nd[y];
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
	int get(int v)
	{
		return nd[find(v)];
	}
};
UF uf;
bool use[SIZE];
bool mark[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int v;
		scanf("%d",&v);
		v--;
		use[v]=true;
	}
	uf.init(n+2);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		uf.unite(a,b);
	}
	vector <int> nd;
	for(int i=0;i<n;i++)
	{
		if(use[i])
		{
			int rt=uf.find(i);
			mark[rt]=true;
			nd.push_back(uf.get(i));
		}
	}
	sort(nd.begin(),nd.end());
	for(int i=0;i<n;i++)
	{
		if(uf.find(i)==i&&!mark[i])
		{
			int t=uf.get(i);
			nd[k-1]+=t;
		}
	}
	ll all=0;
	for(int i=0;i<k;i++) all+=(ll) nd[i]*(ll) (nd[i]-1)/2LL;
	printf("%lld\n",all-m);
	return 0;
}