#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005
#define BT 20

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
};
UF uf;
vector <int> vec[SIZE];
vector <int> tree[SIZE];
int low[SIZE],ord[SIZE];
int left[SIZE],right[SIZE];
bool use[SIZE];
int A[SIZE],B[SIZE];
int par[SIZE][BT];
int dep[SIZE];
int id[SIZE];
int now_id;
int n,m,q;

void dfs(int v,int p)
{
	use[v]=true;
	low[v]=ord[v]=now_id++;
	bool up=false;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			if(!use[to])
			{
				dfs(to,v);
				low[v]=min(low[v],low[to]);
			}
			else
			{
				low[v]=min(low[v],ord[to]);
			}
		}
		else
		{
			if(up) low[v]=min(low[v],ord[to]);
			up=true;
		}
	}
}
bool bridge(int s,int t)
{
	if(ord[s]>ord[t]) swap(s,t);
	return ord[s]<low[t];
}
void make(int v,int p,int d)
{
	use[v]=true;
	par[v][0]=p;
	dep[v]=d;
	for(int i=0;i<tree[v].size();i++)
	{
		int to=tree[v][i];
		if(to!=p) make(to,v,d+1);
	}
}
void make_table()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int getLCA(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]!=-1&&dep[a]<=dep[par[b][i]])
		{
			b=par[b][i];
		}
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
void make_last(int v,int p)
{
	for(int i=0;i<tree[v].size();i++)
	{
		int to=tree[v][i];
		if(to!=p)
		{
			make_last(to,v);
			A[v]+=A[to];
			B[v]+=B[to];
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		left[i]=a,right[i]=b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	memset(use,false,sizeof(use));
	now_id=0;
	for(int i=0;i<n;i++) if(!use[i]) dfs(i,-1);
	uf.init(n+2);
	for(int i=0;i<m;i++)
	{
		if(!bridge(left[i],right[i]))
		{
			uf.unite(left[i],right[i]);
		}
	}
	int sz=0;
	for(int i=0;i<n;i++) if(uf.find(i)==i) id[i]=sz++;
	for(int i=0;i<n;i++) id[i]=id[uf.find(i)];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			if(id[i]!=id[to])
			{
				tree[id[i]].push_back(id[to]);
				tree[id[to]].push_back(id[i]);
			}
		}
	}
	for(int i=0;i<sz;i++)
	{
		sort(tree[i].begin(),tree[i].end());
		tree[i].erase(unique(tree[i].begin(),tree[i].end()),tree[i].end());
		//for(int j=0;j<tree[i].size();j++) printf("%d ",tree[i][j]);puts("");
	}
	memset(use,false,sizeof(use));
 	for(int i=0;i<sz;i++) if(!use[i]) make(i,-1,0);
	make_table();
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		a=id[a],b=id[b];
		int p=getLCA(a,b);
		if(p==-1)
		{
			puts("No");
			return 0;
		}
		//a->p->b
		A[a]++;
		A[p]--;
		B[p]--;
		B[b]++;
	}
	for(int i=0;i<sz;i++) if(par[i][0]==-1) make_last(i,-1);
	for(int i=0;i<sz;i++)
	{
		if(A[i]>0&&B[i]>0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}