#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

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
	bool isR(int x)
	{
		return x==find(x);
	}
};
UF u1,u2;

ll mpow(ll m,ll t)
{
	if(t==0) return 1;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	u1.init(n+2);
	u2.init(n*2+2);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		u1.unite(a,b);
		if(c==0)
		{
			u2.unite(a,b+n);
			u2.unite(a+n,b);
		}
		else
		{
			u2.unite(a,b);
			u2.unite(a+n,b+n);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(u2.same(i,i+n))
		{
			puts("0");
			return 0;
		}
	}
	int all=0;
	for(int i=0;i<n;i++) if(u1.isR(i)) all++;
	printf("%I64d\n",mpow(2LL,all-1));
	return 0;
}