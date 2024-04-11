#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=1;
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
}uf;
int vt[SIZE];
PP edge[SIZE];
int n,m,k;

bool check(int X)
{
	uf.init(n+2);
	int s=-1;
	for(int i=0;i<=X;i++)
	{
		P p=edge[i].second;
		uf.unite(p.first,p.second);
	}
	for(int i=0;i<k;i++) if(!uf.same(vt[0],vt[i])) return false;
	return true;
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int x;
		scanf("%d",&x);x--;
		vt[i]=x;
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);u--,v--;
		edge[i]=PP(w,P(u,v));
	}
	sort(edge,edge+m);
	int l=-1,r=m;
	while(r-l>1)
	{
		int d=(l+r)/2;
		if(check(d)) r=d;
		else l=d;
	}
	for(int i=0;i<k;i++) printf("%d ",edge[r].first);
	puts("");
	return 0;
}