#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cassert>
#include <cmath>
#define SIZE 50005
#define INF 1000000005

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
struct edge
{
	int to,col,dt,id;
	edge(int to=0,int col=0,int dt=0,int id=0):to(to),col(col),dt(dt),id(id){}
};
UF uf;
vector <edge> vec[SIZE];
vector <int> nxt[SIZE];
bool use[SIZE],vis[SIZE],wh[SIZE];//wh c false AmatchingI true
int dep[SIZE];
int V[SIZE],U[SIZE],C[SIZE],T[SIZE];
int cnt[SIZE],bg[SIZE];
int ls,lt;
int n,m;

bool dfs(int v,int p=-1,int d=0)
{
	vis[v]=true;
	wh[v]=d%2==0?false:true;
	if(wh[v])
	{
		use[V[v]]=use[U[v]]=true;
		if(bg[V[v]]==-1) bg[V[v]]=C[v];
		if(bg[U[v]]==-1) bg[U[v]]=C[v];
	}
	for(int i=0;i<nxt[v].size();i++)
	{
		int to=nxt[v][i];
		if(to!=p)
		{
			if(vis[to])
			{
				if(wh[v]==wh[to]) return false;
				continue;
			}
			if(!dfs(to,v,d+1)) return false;
		}
	}
	return true;
}
bool solve(queue <int> que)
{
	while(!que.empty())
	{
		int i=que.front();que.pop();
		for(int j=0;j<vec[i].size();j++)
		{
			edge e=vec[i][j];
			if(e.col!=bg[i])
			{
				if(vis[e.id])
				{
					if(wh[e.id]) return false;
					continue;
				}
				int now=e.id,back=-1,dist=0;
				while(1)
				{
					vis[now]=true;
					wh[now]=dist%2==0?false:true;
					if(wh[now])
					{
						if(!use[V[now]])
						{
							use[V[now]]=true;
							if(bg[V[now]]==-1) bg[V[now]]=C[now];
							else return false;
							que.push(V[now]);
						}
						if(!use[U[now]])
						{
							use[U[now]]=true;
							if(bg[U[now]]==-1) bg[U[now]]=C[now];
							else return false;
							que.push(U[now]);
						}
					}
					int to=-1;
					for(int k=0;k<nxt[now].size();k++)
					{
						int t=nxt[now][k];
						if(t!=back)
						{
							to=t;
							break;
						}
					}
					if(to==-1) break;
					back=now;
					now=to;
					dist++;
				}
			}
		}
	}
	return true;
}
bool check(int lim)// limdestructing
{
	memset(use,false,sizeof(use));
	memset(cnt,0,sizeof(cnt));
	memset(bg,-1,sizeof(bg));
	memset(vis,false,sizeof(vis));
	memset(wh,false,sizeof(wh));
	for(int i=0;i<m;i++) nxt[i].clear();
	for(int i=0;i<n;i++)
	{
		int mx=0;
		int nm=0;
		for(int j=0;j<vec[i].size();j++)
		{
			edge e=vec[i][j];
			cnt[e.col]++;
			if(mx<cnt[e.col])
			{
				mx=cnt[e.col];
				nm=0;
			}
			if(mx==cnt[e.col]) nm++;
		}
		for(int j=0;j<vec[i].size();j++)
		{
			edge e=vec[i][j];
			cnt[e.col]--;
		}
		if(mx>=3||(mx==2&&nm>=2)) return false;
		use[i]=mx==2;
		if(mx==2)
		{
			int l=-1,r=-1;
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				cnt[e.col]++;
			}
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				if(cnt[e.col]==2)
				{
					bg[i]=e.col;
					if(l==-1) l=e.id;
					else r=e.id;
				}
			}
			nxt[l].push_back(r);
			nxt[r].push_back(l);
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				cnt[e.col]--;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(T[i]>lim)
		{
			if(vis[i])
			{
				if(wh[i]) return false;
				continue;
			}
			if(!dfs(i)) return false;
		}
	}
	queue <int> que;
	for(int i=0;i<n;i++) if(use[i]) que.push(i);
	if(!solve(que)) return false;
	for(int i=0;i<n;i++)
	{
		if(use[i])
		{
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				if(e.col!=bg[i])
				{
					assert(vis[e.id]&&!wh[e.id]);
				}
			}
		}
		else
		{
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				assert(cnt[e.col]==0);
				cnt[e.col]++;
			}
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				assert(cnt[e.col]==1);
				cnt[e.col]--;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(wh[i])
		{
			assert(use[U[i]]);
			assert(use[V[i]]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				if(!vis[e.id])
				{
					int now=e.id,back=-1,dist=0;
					while(1)
					{
						int to=-1;
						for(int k=0;k<nxt[now].size();k++)
						{
							int t=nxt[now][k];
							if(t!=back)
							{
								to=t;
								break;
							}
						}
						if(to==-1) break;
						back=now;
						now=to;
						dist++;
					}
					if(dist%2==0) dfs(e.id);
				}
			}
		}
	}
	//return true;
	uf.init(n+2);
	for(int i=0;i<m;i++)
	{
		if(!vis[i])
		{
			if(uf.same(U[i],V[i]))
			{
				if(!dfs(i)) return false;
			}
			uf.unite(U[i],V[i]);
		}
	}
	while(!que.empty()) que.pop();
	for(int i=0;i<n;i++) if(use[i]) que.push(i);
	if(!solve(que)) return false;
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			for(int j=0;j<vec[i].size();j++)
			{
				edge e=vec[i][j];
				if(!vis[e.id])
				{
					bg[i]=e.col;
					if(!dfs(e.id,-1,1)) return false;
					break;
				}
			}
			if(bg[i]!=-1)
			{
				while(!que.empty()) que.pop();
				que.push(i);
				if(!solve(que)) return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&m);
	vector <int> vx;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d %d",&V[i],&U[i],&C[i],&T[i]);
		V[i]--;U[i]--;
		vx.push_back(C[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<m;i++)
	{
		C[i]=lower_bound(vx.begin(),vx.end(),C[i])-vx.begin();
		vec[V[i]].push_back(edge(V[i],C[i],T[i],i));
		vec[U[i]].push_back(edge(U[i],C[i],T[i],i));
	}
	int l=-1,r=INF;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(check(m)) r=m;
		else l=m;
		//printf("%d %d\n",l,r);
	}
	if(r==INF)
	{
		puts("No");
		return 0;
	}
	check(r);
	puts("Yes");
	vector <int> ans;
	for(int i=0;i<m;i++)
	{
		if(wh[i])
		{
			ans.push_back(i);
		}
	}
	printf("%d %d\n",r,ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}