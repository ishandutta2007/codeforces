#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

struct UF
{
	int par[SIZE],rank[SIZE];
	int n;
	
	void init(int m)
	{
		n=m;
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
	int component_count()
	{
		int ret=0;
		for(int i=0;i<n;i++) ret+=par[i]==i;
		return ret;
	}
};
UF uf;
int A[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	uf.init(n);
	int pos=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);A[i]--;
		uf.unite(A[i],i);
		if(A[i]==i) pos=i;
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		if(uf.find(i)!=i) continue;
		int now=i;
		while(!use[now])
		{
			use[now]=true;
			now=A[now];
		}
		if(pos==-1)
		{
			ret++;
			pos=now;
			A[now]=now;
		}
		else if(pos!=now)
		{
			ret++;
			A[now]=pos;
		}
	}
	printf("%d\n",ret);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[i]+1);
	}puts("");
	return 0;
}