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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct SCC
{
	const int INF = int(1e9);
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	vi topo;
	
	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		topo.clear();
		vec.resize(n);
	}
	
	void addedge(int u, int v) //u -> v
	{
		vec[u].pb(v);
	}
	
	void connect(int u)
	{
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++)
		{
			int v = vec[u][i];
			if(idx[v] == -1)
			{
				connect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			}
			else if(onstack[v])
			{
				lowlink[u] = min(lowlink[u], idx[v]);
			}
		}
		if(lowlink[u] == idx[u])
		{
			while(1)
			{
				int v = s.top();
				s.pop();
				onstack[v] = false;
				sccidx[v] = scccnt;
				if(v == u) break;
			}
			scccnt++;
		}
	}
	
	void tarjan()
	{
		for(int i = 0; i < vec.size(); i++)
		{
			if(idx[i] == -1)
			{
				connect(i);
			}
		}
	}
	
	void toposort() //if graph is a DAG and i just want to toposort
	{
		tarjan();
		int n = vec.size();
		topo.resize(n);
		vector<ii> tmp;
		for(int i = 0; i < n; i++)
		{
			tmp.pb(mp(sccidx[i],i));
		}
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		for(int i = 0; i < n; i++)
		{
			topo[i]=tmp[i].se;
			if(i>0) assert(tmp[i].fi!=tmp[i-1].fi);
		}
	}
};

struct Graph
{
	struct edge
	{
		int v; ll weight;
	};
	vector<vector<edge> > adj;
	int n;
	
	Graph(int _n)
	{
		adj.resize(_n);
		n = _n;
	}
	
	void addedge(int u, int v, ll c)
	{
		edge tmp;
		tmp.v = v; tmp.weight = c;
		adj[u].pb(tmp);
	}
	
	void reset()
	{
		adj.clear();
	}
	
	vector<ll> dist;
	vi par;
	
	void bfs(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		queue<int> q; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v;
				if(dist[v] >= INFI)
				{
					dist[v] = dist[u] + 1;
					par[v] = u;
					q.push(v);
				}
			}
		}
	}
	
	void bfs01(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		deque<int> q; q.pb(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop_front();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v; ll w = adj[u][i].weight;
				if(dist[v] >= INFI)
				{
					if(w == 1)
					{
						dist[v] = dist[u] + 1;
						par[v] = u;
						q.push_back(v);
					}
					else
					{
						dist[v] = dist[u];
						par[v] = u;
						q.push_front(v);
					}
				}
			}
		}
	}
	
	void dijkstra(int s, bool ret = 0)
	{
		ll INFI = ll(1e18);
		if(ret)
		{
			dist.clear();
			dist.assign(n, INFI);
			par.assign(n, -1);
		}
		dist[s]=0; par[s]=-1;
		priority_queue<pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		pq.push(mp(0, s));
		while(!pq.empty())
		{
			int u = pq.top().se; ll d = pq.top().fi; pq.pop();
			if(d>dist[u]) continue;
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v; ll w = adj[u][i].weight;
				if(d + w < dist[v])
				{
					dist[v] = d + w;
					par[v] = u;
					pq.push(mp(dist[v], v));
				}
			}
		}
	}
	
	vector<vector<ll> > d;
	
	void Floyd()
	{
		ll INFIN = ll(1e18);
		d.resize(n);
		for(int i = 0; i < n; i++)
		{
			d[i].assign(n, INFIN);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < adj[i].size(); j++)
			{
				d[i][adj[i][j].v] = adj[i][j].weight;
			}
			d[i][i] = 0;
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	
	bool BellmanFord(int s) //returns true if negative weight cycle exists
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0;
		for(int step = 1; step <= n; step++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < adj[i].size(); j++)
				{
					int u = i; int v = adj[i][j].v; ll w = adj[i][j].weight;
					if(dist[v] > dist[u] + w)
					{
						if(step == n)
						{
							return true;
						}
						dist[v] = dist[u] + w;
					}
				}
			}
		}
		return false;
	}
	
	ll shortest(int s, int e) //returns the distance by Dijkstra
	{
		return dist[e];
	}

};

vector<pair<ii,int> > E[222222];

vi rep[222222];
ll gd[222222];
ll stor[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	SCC scc; scc.init(n);
	vector<pair<ii,int> > edges;
	for(int i=0;i<m;i++)
	{
		int u,v,w; cin>>u>>v>>w; u--; v--;
		edges.pb({{u,v},w});
		scc.addedge(u,v);
		//adj[u].pb({v,w}); adj[v].pb({u,w});
	}
	scc.tarjan();
	Graph G(n); Graph G2(n);
	memset(rep,-1,sizeof(rep));
	for(int i=0;i<n;i++)
	{
		rep[scc.sccidx[i]].pb(i);
	}
	for(int i=0;i<m;i++)
	{
		int u=edges[i].fi.fi; int v=edges[i].fi.se;
		int w=edges[i].se;
		if(scc.sccidx[u]==scc.sccidx[v])
		{
			//adj[u].pb({v,w});
			//radj[v].pb({u,w});
			E[scc.sccidx[u]].pb({{u,v},w});
			G.addedge(u,v,w);
			G2.addedge(v,u,w);
		}
	}
	bool hajimete=1;
	for(int i=0;i<=n;i++)
	{
		if(rep[i].empty()) continue;
		G.dijkstra(rep[i].front(),hajimete);
		G2.dijkstra(rep[i].front(),hajimete);
		hajimete=0;
		int r=rep[i].front();
		ll gd=0;
		for(int v:rep[i])
		{
			gd=__gcd(gd,G.dist[v]+G2.dist[v]);
		}
		for(auto x:E[i])
		{
			int u=x.fi.fi; int v=x.fi.se; ll w=x.se;
			gd=__gcd(gd,G.dist[u]+w+G2.dist[v]);
		}
		stor[i]=gd;
	}
	int q; cin>>q;
	while(q--)
	{
		int u; ll s,t; cin>>u>>s>>t;
		u--;
		int id = scc.sccidx[u];
		if(s==0) {cout<<"YES\n"; continue;}
		ll mn = __gcd(s,t);
		if(stor[id]==0){cout<<"NO\n"; continue;}
		//cycle gd is stor[id];
		if(mn%__gcd(t,stor[id])==0)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}