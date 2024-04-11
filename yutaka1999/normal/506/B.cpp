#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <functional>
#define SIZE 100005

using namespace std;

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
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)//x->y
	{
		x=find(x);
		y=find(y);
		par[y]=x;
	}
};
UF uf;
vector <int> vec[SIZE];
vector <int> rvec[SIZE];
vector <int> dag[SIZE];
vector <int> vs;
int cmb[SIZE],nd[SIZE],deg[SIZE];
int ord[SIZE],id[SIZE];
bool use[SIZE],ok[SIZE];
int n,m,bef;

void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<vec[v].size();i++) if(!use[vec[v][i]]) dfs(vec[v][i]);
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	use[v]=true;
	cmb[v]=k;
	nd[k]++;
	for(int i=0;i<rvec[v].size();i++) if(!use[rvec[v][i]]) rdfs(rvec[v][i],k);
}
int scc()
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=n-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	int now=0;
	bef=-1;
	for(int i=0;i<k;i++)
	{
		if(nd[i]>1)
		{
			if(bef==-1) bef=now++;
			id[i]=bef;
		}
		else id[i]=now++;
	}
	uf.init(n+2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			if(id[cmb[to]]!=id[cmb[i]]) uf.unite(id[cmb[to]],id[cmb[i]]);
		}
	}
	int ret=0;
	for(int i=0;i<now;i++) if(uf.find(i)==i) ret++;
	return n-(ret-(bef==-1?0:1));
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	printf("%d\n",scc());
	return 0;
}