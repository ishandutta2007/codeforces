#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int INF = int(1e9);
const int MX = 1234;

struct MaxFlow
{
	struct edge
	{
		int to,cap,rev;
		edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
	};
	vector <edge> vec[MX];
	int level[MX];
	int iter[MX];
	
	void addedge(int s,int t,int c) //adds an edge of cap c to the flow graph
	{
		int S=vec[s].size(),T=vec[t].size();
		vec[s].push_back(edge(t,c,T));
		vec[t].push_back(edge(s,0,S));
	}
	void bfs(int s)
	{
		memset(level,-1,sizeof(level));
		queue <int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty())
		{
			int v = que.front();que.pop();
			for(int i=0;i<vec[v].size();i++)
			{
				edge&e=vec[v][i];
				if (e.cap>0&&level[e.to]<0)
				{
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	ll flow_dfs(int v,int t,ll f)
	{
		if (v==t) return f;
		for(int &i=iter[v];i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if (e.cap>0&&level[v]<level[e.to])
			{
				ll d=flow_dfs(e.to,t,min(f,ll(e.cap)));
				if (d>0)
				{
					e.cap-=d;
					vec[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	ll maxflow(int s,int t) //finds max flow using dinic from s to t
	{
		ll flow = 0;
		while(1)
		{
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			while (1)
			{
				ll f=flow_dfs(s,t,INF);
				if(f==0) break;
				flow += f;
			}
		}
	}
};

void solve()
{
	int n,m,k; cin>>n>>m>>k;
	vector<int> vec(m,-1);
	vector<ii> edges;
	vector<int> deg(n,0);
	map<ii,int> ma;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; deg[u]++; deg[v]++;
		edges.pb(mp(min(u,v),max(u,v))); ma[edges.back()] = i;
	}
	MaxFlow mf;
	int s=MX-1; int e=MX-2;
	for(int i=0;i<m;i++)
	{
		mf.addedge(s,i,1);
		int u=edges[i].fi; int v=edges[i].se;
		mf.addedge(i,u+m,1);
		mf.addedge(i,v+m,1);
	}
	int fl=0;
	for(int i=0;i<n;i++)
	{
		fl+=max(2*(deg[i]-k),0);
		mf.addedge(i+m,e,max(2*(deg[i]-k),0));
	}
	int mfval = mf.maxflow(s,e);
	if(fl!=mfval)
	{
		for(int i=0;i<m;i++)
		{
			cout<<0;
			if(i+1<m) cout<<' ';
		}
		cout<<'\n';
		return ;
	}
	int cc=1;
	for(int i=0;i<n;i++)
	{
		vi V;
		for(auto E:mf.vec[i+m])
		{
			int to = E.to;
			if(to>=0&&to<m&&E.cap==1)
			{
				//flow is passed 
				V.pb(to);
			}
		}
		for(int j=0;j+1<V.size();j+=2)
		{
			vec[V[j]]=vec[V[j+1]]=cc;
			cc++;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(vec[i]==-1) vec[i]=cc++;
	}
	for(int i=0;i<m;i++)
	{
		cout<<vec[i];
		if(i+1<m) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}