#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <functional>
#define SIZE 1005
#define INF 2000000005
#define MX 30005
#define BT 15

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct edge
{
	int to;
	P cost;
	edge(int to=0,P cost=P(0,0)):to(to),cost(cost){}
};
struct Graph
{
	vector <edge> vec[SIZE];
	vector <edge> tree[SIZE];
	int par[SIZE][BT],dep[SIZE];
	int low[SIZE],ord[SIZE];
	int cmb[SIZE],id[SIZE];
	int tour[SIZE],ch[SIZE];
	P back[SIZE];
	bool use[SIZE];
	int n,sz;//treevf
	int now_id;
	
	void init(int m)
	{
		n=m;
		for(int i=0;i<n;i++)
		{
			vec[i].clear();
			tree[i].clear();
		}
	}
	inline void add(int a,int b,int c,int d)
	{
		vec[a].push_back(edge(b,P(c,d)));
		vec[b].push_back(edge(a,P(c,d)));
	}
	void dfs(int v,int p)
	{
		use[v]=true;
		low[v]=ord[v]=now_id++;
		int cnt=0;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i].to;
			if(to!=p)
			{
				if(!use[to])
				{
					dfs(to,v);
					low[v]=min(low[v],low[to]);
				}
				else low[v]=min(low[v],ord[to]);
			}
			else
			{
				if(cnt>0) low[v]=min(low[v],ord[to]);
				cnt++;
			}
		}
	}
	void build_lowlink()
	{
		for(int i=0;i<n;i++) use[i]=false;
		now_id=0;
		for(int i=0;i<n;i++)
		{
			if(!use[i])
			{
				dfs(i,-1);
			}
		}
	}
	bool bridge(int s,int t)//  true
	{
		if(ord[s]<ord[t]) swap(s,t);//ord[s]>=ord[t]
		return low[s]>ord[t];
	}
	void dfs2(int v,int p,int d)
	{
		tour[v]=now_id++;
		par[v][0]=p;
		dep[v]=d;
		use[v]=true;
		for(int i=0;i<tree[v].size();i++)
		{
			int to=tree[v][i].to;
			if(to!=p)
			{
				back[to]=tree[v][i].cost;
				dfs2(to,v,d+1);
			}
		}
		ch[v]=now_id;
	}
	void build_LCA()
	{
		for(int i=0;i+1<BT;i++)
		{
			for(int j=0;j<sz;j++)
			{
				if(par[j][i]==-1) par[j][i+1]=-1;
				else par[j][i+1]=par[par[j][i]][i];
			}
		}
	}
	inline int LCA(int a,int b)
	{
		if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
		for(int i=BT-1;i>=0;i--)
		{
			if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
			{
				b=par[b][i];
			}
		}
		if(a==b) return b;
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
	void build_component()
	{
		build_lowlink();
		for(int i=0;i<n;i++) id[i]=-1;
		sz=0;
		for(int i=0;i<n;i++)
		{
			if(id[i]==-1)
			{
				id[i]=sz;
				queue <int> que;
				que.push(i);
				while(!que.empty())
				{
					int v=que.front();que.pop();
					for(int j=0;j<vec[v].size();j++)
					{
						int to=vec[v][j].to;
						if(id[to]==-1&&!bridge(v,to))
						{
							id[to]=sz;
							que.push(to);
						}
					}
				}
				sz++;
			}
		}
	}
	void build_tree()//component !!
	{
		build_component();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				int to=vec[i][j].to;
				if(bridge(i,to))
				{
					tree[id[i]].push_back(edge(id[to],vec[i][j].cost));
				}
			}
		}
		for(int i=0;i<sz;i++) use[i]=false;
		now_id=0;
		for(int i=0;i<sz;i++) if(!use[i]) dfs2(i,-1,0);
		build_LCA();
	}
	P get_score(int s,int t)
	{
		s=id[s];
		t=id[t];
		if(s==t) return P(-1,-1);
		int p=LCA(s,t);
		if(p==-1) return P(0,-1);
		P mn=P(INF,INF);
		int now=s;
		while(now!=p)
		{
			mn=min(mn,back[now]);
			now=par[now][0];
		}
		now=t;
		while(now!=p)
		{
			mn=min(mn,back[now]);
			now=par[now][0];
		}
		return mn;
	}
};
Graph G;
int A[MX],B[MX],C[MX];
int back[SIZE],id[SIZE];
vector <P> vec[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int S,T;
	scanf("%d %d",&S,&T);S--,T--;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
		A[i]--,B[i]--;
		vec[A[i]].push_back(P(B[i],i));
		vec[B[i]].push_back(P(A[i],i));
	}
	queue <int> que;
	que.push(S);
	memset(back,-1,sizeof(back));
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<vec[v].size();i++)
		{
			P e=vec[v][i];
			if(back[e.first]==-1)
			{
				back[e.first]=v;
				id[e.first]=e.second;
				que.push(e.first);
			}
		}
	}
	if(back[T]==-1)
	{
		puts("0");
		puts("0");
		puts("");
		return 0;
	}
	int now=T;
	int ret=INF;
	vector <int> ans;
	while(now!=S)
	{
		G.init(n+2);
		for(int i=0;i<m;i++)
		{
			if(i==id[now]) continue;
			G.add(A[i],B[i],C[i],i);
		}
		G.build_tree();
		P p=G.get_score(S,T);
		int gt=p.first;
		if(gt>=0&&gt+C[id[now]]<=ret)
		{
			ret=gt+C[id[now]];
			ans.clear();
			ans.push_back(id[now]);
			if(p.second!=-1) ans.push_back(p.second);
		}
		now=back[now];
	}
	if(ret==INF)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n",ret);
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%d",ans[i]+1);
		}puts("");
	}
	return 0;
}