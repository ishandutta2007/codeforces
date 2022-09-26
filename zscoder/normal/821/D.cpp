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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

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
};

map<ii,int> ma;
int n,m,k; 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>k;
	vector<ii> v;
	int s=-1;
	Graph G(n+m+k*5+10);
	for(int i=0;i<k;i++)
	{
		int x,y; cin>>x>>y;
		x--; y--;
		v.pb(mp(x,y));
		ma[mp(x,y)]=i;
		if(x==0&&y==0) s=i;
	}
	int cnt=k;
	for(int i=0;i<k;i++)
	{
		int x=v[i].fi;int y=v[i].se;
		for(int j=0;j<4;j++)
		{
			int x2=x+dx[j]; int y2=y+dy[j];
			if(valid(x2,y2))
			{
				if(ma.find(mp(x2,y2))!=ma.end())
				{
					//cerr<<"FAIL\n";
					if(ma[mp(x2,y2)]<k) 
					{
						G.addedge(ma[mp(x,y)],ma[mp(x2,y2)],0);
					}
					else 
					{
						G.addedge(ma[mp(x2,y2)],ma[mp(x,y)],0);
					}
				}
				else
				{
					ma[mp(x2,y2)]=cnt++;
					v.pb(mp(x2,y2));
					G.addedge(cnt-1,ma[mp(x,y)],0);
				}
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		int x=v[i].fi; int y=v[i].se;
		if(i<k)
		{
			for(int j=max(x-1,0);j<=min(x+1,n-1);j++)
			{
				G.addedge(i,j+5*k,1);
			}
			for(int j=max(y-1,0);j<=min(y+1,m-1);j++)
			{
				G.addedge(i,j+n+5*k,1);
			}
		}
		G.addedge(x+5*k,i,0);
		G.addedge(y+n+5*k,i,0);
	}
	G.bfs01(s);
	ll ans=10000000;
	if(ma.find(mp(n-1,m-1))!=ma.end()) ans=min(ans,G.dist[ma[mp(n-1,m-1)]]);
	ans=min(ans,min(G.dist[5*k+n-1],G.dist[5*k+n+m-1]));
	if(ans>1000000) ans=-1;
	cout<<ans<<'\n';
}