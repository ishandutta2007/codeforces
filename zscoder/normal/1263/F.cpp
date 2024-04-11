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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MX = 5555;
const int INF = int(1e9);
struct MaxFlow //by yutaka1999, have to define INF and MX (the Max number of vertices)
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	MaxFlow mf;
	int s = MX-1; int e = MX-2;
	int a; cin>>a;
	for(int i=1;i<a;i++)
	{
		int x; cin>>x; x--;
		//connects i and x
		mf.addedge(i,x,INF);
	}
	vi V;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; x--; V.pb(x);
	}
	for(int i=0;i<a;i++)
	{
		mf.addedge(i,e,1); //chosen nodes on top
	}
	int b; cin>>b;
	for(int i=1;i<b;i++)
	{
		int x; cin>>x; x--;
		mf.addedge(x+a,i+a,INF);
	}
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; x--; 
		mf.addedge(x+a,V[i],INF);
	}
	for(int i=a;i<a+b;i++)
	{
		mf.addedge(s,i,1);
	}
	mf.addedge(s,0,INF);
	mf.addedge(a,e,INF);
	int fl = mf.maxflow(s,e);
	cout<<max(a-1,max(b-1,a-1+b-1-(fl-2)))<<'\n';
}