#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

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
vector <int> dr[SIZE];
vector <int> rvec[SIZE];
vector <P> dag[SIZE];
vector <int> vs;
PP edge[SIZE];
bool use[SIZE],vis[SIZE];
int cmb[SIZE],par[SIZE];
int n,m,sz;

void dfs1(int v)
{
	use[v]=true;
	for(int i=0;i<dr[v].size();i++)
	{
		int to=dr[v][i];
		if(!use[to]) dfs1(to);
	}
}
bool check()
{
	memset(use,false,sizeof(use));
	dfs1(0);
	for(int i=0;i<n;i++) if(!use[i]) return true;
	return false;
}
void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(!use[to]) dfs(to);
	}
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	cmb[v]=k;
	use[v]=true;
	for(int i=0;i<rvec[v].size();i++)
	{
		int to=rvec[v][i];
		if(!use[to]) rdfs(to,k);
	}
}
void fill(int v,int k)
{
	vis[v]=true;
	par[cmb[v]]=k;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(!vis[to]) fill(to,k);
	}
}
void scc()
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=n-1;i>=0;i--) if(!use[vs[i]]) rdfs(vs[i],k++);
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			int to=vec[i][j];
			if(cmb[i]!=cmb[to])
			{
				use[cmb[to]]=true;
			}
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&!use[cmb[i]])
		{
			fill(i,cmb[i]);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	sz=0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		dr[a].push_back(b);
		if(c==0)
		{
			vec[a].push_back(b);
			rvec[b].push_back(a);
		}
		else edge[sz++]=PP(P(a,b),i);
	}
	if(check())
	{
		puts("-1");
		return 0;
	}
	scc();
	for(int i=0;i<sz;i++)
	{
		PP p=edge[i];
		int s=p.first.first,t=p.first.second;
		if(cmb[s]!=cmb[t]&&!use[cmb[t]])
		{
			dag[par[cmb[s]]].push_back(P(cmb[t],p.second));
		}
	}
	queue <int> que;
	que.push(cmb[0]);
	use[cmb[0]]=true;
	vector <int> ans;
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<dag[v].size();i++)
		{
			P p=dag[v][i];
			if(!use[p.first])
			{
				use[p.first]=true;
				que.push(p.first);
				ans.push_back(p.second);
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]+1);
	return 0;
}