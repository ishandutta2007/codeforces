#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 205

using namespace std;

struct UF
{
	int par[SIZE],nod[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			nod[i]=1;
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
		if(nod[x]<nod[y])
		{
			par[x]=y;
			nod[y]+=nod[x];
		}
		else
		{
			par[y]=x;
			nod[x]+=nod[y];
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
	bool only(int x)
	{
		return nod[find(x)]==1;
	}
};
UF uf;
bool ok[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	uf.init(n+m+2);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{
			int b;
			scanf("%d",&b);b--;
			uf.unite(i,b+n);
		}
	}bool up=true;
	for(int i=0;i<n;i++)
	{
		if(!uf.only(i)) up=false;
		ok[uf.find(i)]=true;
	}
	if(up) printf("%d\n",n);
	else
	{
		int ret=0;
		for(int i=0;i<n;i++) ret+=ok[i];
		ret--;
		printf("%d\n",ret);
	}
	return 0;
}