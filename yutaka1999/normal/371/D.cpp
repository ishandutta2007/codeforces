#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005

using namespace std;
typedef long long int ll;

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
	int find(int v)
	{
		if(v==par[v]) return v;
		return par[v]=find(par[v]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[x]=y;
	}
};
UF uf;
ll now[SIZE],lim[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	uf.init(n+2);
	for(int i=0;i<n;i++) scanf("%I64d",&lim[i]);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a;
			ll b;
			scanf("%d %I64d",&a,&b);a--;
			while(b)
			{
				a=uf.find(a);
				if(a>=n) break;
				if(now[a]+b>=lim[a])
				{
					b-=lim[a]-now[a];
					now[a]=lim[a];
					uf.unite(a,a+1);
				}
				else
				{
					now[a]+=b;
					break;
				}
			}
		}
		else
		{
			int a;
			scanf("%d",&a);a--;
			printf("%I64d\n",now[a]);
		}
	}
	return 0;
}