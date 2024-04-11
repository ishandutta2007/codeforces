#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005

using namespace std;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE];
	int m1[SIZE],m2[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			m1[i]=m2[i]=0;
		}
	}
	void add(int k,int a,int b)
	{
		m1[k]=a;
		m2[k]=b;
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)//x->y
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	void con(int x,int y)
	{
		if(m1[x]+1<=m1[y])
		{
			m2[y]=max(m2[y],m1[x]+1);
			par[x]=y;
		}
		else//m1[x]>=m1[y]
		{
			if(m1[x]==m1[y])
			{
				m2[x]=m1[x];
				m1[x]=m1[y]+1;
			}
			else m2[x]=max(m2[x],m1[y]+1);
			par[y]=x;
		}
	}
	int get(int x)
	{
		x=find(x);
		return m1[x]+m2[x];
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
vector <int> vec[SIZE];
int m1[SIZE],m2[SIZE];
bool use[SIZE];

void dfs(int v,int p)
{
	use[v]=true;
	m1[v]=0;
	m2[v]=-SIZE;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			int d=m1[to]+1;
			if(d>m1[v])
			{
				m2[v]=m1[v];
				m1[v]=d;
			}
			else if(d>m2[v]) m2[v]=d;
		}
	}
}
P make(int v,int p)
{
	P ret=P(m1[v],v);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			int d;
			if(m1[v]==m1[to]+1) d=m2[v]+1;
			else d=m1[v]+1;
			if(d>m1[to])
			{
				m2[to]=m1[to];
				m1[to]=d;
			}
			else if(d>m2[to]) m2[to]=d;
			ret=min(ret,make(to,v));
		}
	}
	return ret;
}
void uni(int v,int p,int rt)
{
	uf.unite(v,rt);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) uni(to,v,rt);
	}
}
int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	uf.init(n+2);
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			dfs(i,-1);
			P p=make(i,-1);
			int rt=p.second;
			uni(i,-1,rt);
			uf.add(rt,max(0,m1[rt]),max(0,m2[rt]));
			//printf("%d %d %d\n",rt,m1[rt],m2[rt]);
		}
	}
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int v;
			scanf("%d",&v);v--;
			printf("%d\n",uf.get(v));
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);l--;r--;
			l=uf.find(l);
			r=uf.find(r);
			if(l!=r) uf.con(l,r);
		}
	}
	return 0;
}