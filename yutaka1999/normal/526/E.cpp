#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2000005

using namespace std;
typedef long long int ll;

struct UF
{
	int par[SIZE],rank[SIZE];
	int right[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=right[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)//right : x
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
			right[y]=right[x];
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	int reach(int x)
	{
		return right[find(x)];
	}
};
UF uf;
ll L[SIZE];
int nxt[SIZE];
int dep[SIZE];
int n,s;

int solve(ll d)
{
	ll now=0;
	int end=2*n-1;
	dep[2*n]=0;
	for(int i=2*n-1;i>=0;i--)
	{
		now+=L[i];
		while(now>d)
		{
			now-=L[end];
			end--;
		}
		nxt[i]=end+1;
		dep[i]=dep[nxt[i]]+1;
		//printf("%d ",nxt[i]);
	}
	//puts("");
	//for(int i=0;i<2*n;i++) printf("%d ",dep[i]);puts("");
	int ret=n*3;
	uf.init(n*2+2);
	for(int i=0;i<n;i++)
	{
		int now=uf.reach(i);
		bool up=true;
		while(now-i<n)
		{
			int to=nxt[now];
			uf.unite(to,now);
			now=uf.reach(now);
		}
		//printf("%d %d %d\n",now,dep[now],dep[i]);
		ret=min(ret,dep[i]-dep[now]);
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++) scanf("%I64d",&L[i]);
	for(int i=n;i<2*n;i++) L[i]=L[i-n];
	for(int i=0;i<s;i++)
	{
		ll d;
		scanf("%I64d",&d);
		printf("%d\n",solve(d));
	}
	return 0;
}