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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const ll INF = 100001;

set<pair<ii,bool> > s;
vector<ii> adj[INF];
ll dist[100001];
int par[100001];
set<ii> s2;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) dist[i] = ll(1e18);
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(mp(v, (w^1)+INF)); adj[v].pb(mp(u, (w^1)+INF));
		s.insert(mp(mp(u, v), w));
	}
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	dist[1] = 0;
	pq.push(mp(0, 1));
	while(!pq.empty())
	{
		ll d = pq.top().fi; int u = pq.top().se; pq.pop();
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].fi; ll w = adj[u][i].se;
			if(d + w < dist[v])
			{
				dist[v] = d + w;
				pq.push(mp(dist[v], v));
				par[v] = u;
			}
		}
	}
	
	//cerr << dist[n] << '\n';
	int cur = n;
	while(cur != 1)
	{
		//cerr << cur << ' ';
		s.erase(mp(mp(cur, par[cur]), 1));
		s.erase(mp(mp(par[cur], cur), 1));
		s2.insert(mp(cur,par[cur])); 
		s2.insert(mp(par[cur],cur));
		cur = par[cur];
	}
	//cerr << "1\n";
	int cnt = 0;
	for(set<pair<ii,bool> >::iterator it = s.begin(); it != s.end(); it++)
	{
		pair<ii,bool> tmp = (*it);
		if(!tmp.se && s2.find((*it).fi) == s2.end()) continue;
		cnt++;
	}
	cout << cnt << '\n';
	for(set<pair<ii,bool> >::iterator it = s.begin(); it != s.end(); it++)
	{
		pair<ii,bool> tmp = (*it);
		if(!tmp.se && s2.find((*it).fi) == s2.end()) continue;
		cout << tmp.fi.fi << ' ' << tmp.fi.se << ' ' << (tmp.se^1) << '\n';
	}
}