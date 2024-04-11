#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 3005
#define MX 10005

using namespace std;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE],rank[SIZE];
	int cost[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=cost[i]=0;
		}
	}
	void add(int k,int x)
	{
		cost[k]=x;
	}
	int find(int x)
	{
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	int unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(rank[x]<rank[y])
		{
			par[x]=y;
			cost[y]+=cost[x];
			return cost[y];
		}
		else
		{
			par[y]=x;
			cost[x]+=cost[y];
			if(rank[x]==rank[y]) rank[x]++;
			return cost[x];
		}
	}
};
UF uf;
vector <P> vec[MX];

int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[c].push_back(P(a,b));
	}
	uf.init(n+2);
	int all=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		all+=a;
		uf.add(i,a+1);
	}
	int ret=1;
	for(int i=1;i<MX;i++)
	{
		int gt=0;
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			gt=max(gt,uf.unite(p.first,p.second));
		}
		if(gt>all) break;
		ret=i+1;
	}
	printf("%d\n",ret);
	return 0;
}