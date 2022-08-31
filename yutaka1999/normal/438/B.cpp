#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100050

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

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
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(nd[x]<nd[y]) swap(x,y);//nd[x]>=nd[y]
		par[y]=x;
		nd[x]+=nd[y];
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
	int get(int x)
	{
		return nd[find(x)];
	}
};
UF uf;
int val[SIZE];
P in[SIZE];
vector <int> vec[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
		in[i]=P(val[i],i);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if(val[a]<val[b]) swap(a,b);//val[a]>=val[b]
		vec[b].push_back(a);
	}
	sort(in,in+n);
	uf.init(n+2);
	ll sum=0;
	for(int i=n-1;i>=0;i--)
	{
		int v=in[i].second;
		for(int j=0;j<vec[v].size();j++)
		{
			int to=vec[v][j];
			if(!uf.same(to,v))
			{
				int l=uf.get(v),r=uf.get(to);
				sum+=((ll) l)*((ll) r)*((ll) val[v]);
				uf.unite(to,v);
			}
		}
	}
	printf("%.8f\n",(double) sum*2.0/(double) (((ll)n)*((ll) n-1)));
	return 0;
}