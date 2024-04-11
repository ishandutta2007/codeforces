#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 10005

using namespace std;

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
		if(rank[x]<rank[y]) par[x]=y;
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
};
UF uf;
int sum;
struct query
{
	int s,e,n;
	int v;
};
bool c1(const query&l,const query&r)
{
	if(l.s!=r.s) return l.s<r.s;
	return l.e>r.e;
}
bool c2(const query&l,const query&r)
{
	return l.n<r.n;
}
query in[2*SIZE];
int a[SIZE],b[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		query p;
		p.s=a;p.e=b;p.n=i;
		in[i]=p;
	}
	sort(in,in+q,c1);
	uf.init(n);sum=n;
	int pos=0;
	for(int i=0;i<m;i++)
	{
		UF u=uf;
		int s=sum;
		for(int j=m-1;j>=i;j--)
		{
			while(pos<q&&in[pos].s==i&&in[pos].e==j)
			{
				in[pos].v=s;
				pos++;
			}
			if(!u.same(a[j],b[j]))
			{
				u.unite(a[j],b[j]);
				s--;
			}
		}
		if(!uf.same(a[i],b[i]))
		{
			uf.unite(a[i],b[i]);
			sum--;
		}
	}
	sort(in,in+q,c2);
	for(int i=0;i<q;i++) printf("%d\n",in[i].v);
	return 0;
}