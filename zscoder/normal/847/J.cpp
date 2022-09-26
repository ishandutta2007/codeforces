#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MX = 11111;
const int INF = int(1e8);
struct edge
{
	int to,cap,rev;
	edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
};
struct MaxFlow //by yutaka1999, have to define INF and MX (the Max number of vertices)
{
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
	int flow_dfs(int v,int t,int f)
	{
		if (v==t) return f;
		for(int &i=iter[v];i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if (e.cap>0&&level[v]<level[e.to])
			{
				int d=flow_dfs(e.to,t,min(f,(e.cap)));
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
	int maxflow(int s,int t) //finds max flow using dinic from s to t
	{
		int flow = 0;
		while(1)
		{
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			while (1)
			{
				int f=flow_dfs(s,t,INF);
				if(f==0) break;
				flow += f;
			}
		}
	}
};

int calc[5001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<pair<int,int> > edges;
	for(int i=0;i<m;i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		edges.pb(mp(u,v));
	}
	int lo=0;int hi=n-1;
	int ans=hi;
	while(lo<=hi)
	{
		MaxFlow mf;
		int s=MX-3; int e=MX-2;
		int mid=(lo+hi)>>1;
		for(int i=0;i<n;i++) mf.addedge(s,i,mid);
		for(int i=0;i<m;i++)
		{
			mf.addedge(edges[i].fi,i+n,1);
			mf.addedge(edges[i].se,i+n,1);
			mf.addedge(i+n,e,1);
		}
		if(mf.maxflow(s,e)==m)
		{
			ans=mid;
			hi=mid-1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<mf.vec[i].size();j++)
				{
					edge tmp = mf.vec[i][j];
					if(tmp.to>=n&&tmp.to<s&&tmp.cap==0)
					{
						calc[tmp.to-n] = i;
					}
				}
			}
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<m;i++)
	{
		if(edges[i].fi==calc[i])
		{
			cout<<edges[i].fi+1<<' '<<edges[i].se+1;
		}
		else
		{
			cout<<edges[i].se+1<<' '<<edges[i].fi+1;
		}
		cout<<'\n';
	}
}