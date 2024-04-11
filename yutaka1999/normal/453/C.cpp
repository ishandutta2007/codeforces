#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

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
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b) return;
		if(rank[a]<rank[b])
		{
			par[a]=b;
		}
		else
		{
			par[b]=a;
			if(rank[a]==rank[b]) rank[a]++;
		}
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
};
UF uf;
vector <int> vec[SIZE];
vector <int> tree[SIZE];
int tp[SIZE],ans[SIZE*4];
int sz,f;
bool use[SIZE];

void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(!use[to])
		{
			dfs(to);
			tree[v].push_back(to);
		}
	}
}
void make(int v)
{
	int cnt=tree[v].size()+1;
	tp[v]=(tp[v]+cnt)%2;
	for(int i=0;i<tree[v].size();i++)
	{
		int to=tree[v][i];
		make(to);
	}
}
void solve(int v)
{
	ans[sz++]=v;
	if(tree[v].size()==0) return;
	for(int i=0;i<tree[v].size();i++)
	{
		int to=tree[v][i];
		solve(to);
		ans[sz++]=v;
		if(tp[to]==1)
		{
			ans[sz++]=to;
			ans[sz++]=v;
			tp[v]^=1;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	uf.init(n+2);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
		uf.unite(a,b);
	}
	f=-1;
	for(int i=0;i<n;i++)
	{
		use[i]=false;
		scanf("%d",&tp[i]);
		if(tp[i]==1) f=i;
	}
	if(f==-1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(tp[i]==1&&!uf.same(i,f))
		{
			puts("-1");
			return 0;
		}
	}
	dfs(f);
	make(f);
	solve(f);
	if(tp[f]==1) sz--;
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}