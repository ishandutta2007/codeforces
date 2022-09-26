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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
		tmp.v = u;
		adj[v].pb(tmp);
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
};

int D[444444];

bool cmp(int x, int y)
{
	if(D[x]!=D[y]) return D[x]<D[y];
	return x<y;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	vi special;
	for(int i=0;i<k;i++)
	{
		int x; cin>>x; x--; special.pb(x);
	}
	Graph G(n);
	Graph G2(n);
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		G.addedge(u,v,1); G2.addedge(u,v,1);
	}
	G.bfs(0); G2.bfs(n-1);
	for(int i=0;i<n;i++) D[i]=G.dist[i];
	ll ans = 0;
	sort(special.begin(),special.end(),cmp);
	ll mxv = G2.dist[special.back()];
	for(int i=int(special.size())-2;i>=0;i--)
	{
		//cerr<<mxv<<' '<<G.dist[i]<<' '<<G.dist[n-1]<<'\n';
		ans=max(ans,min(mxv+G.dist[special[i]]+1,G.dist[n-1]));
		mxv=max(mxv,G2.dist[special[i]]);
	}
	cout<<ans<<'\n';
}