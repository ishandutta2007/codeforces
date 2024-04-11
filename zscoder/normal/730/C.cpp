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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dist[5001];
vi adj[5001];
int c[5001];
int k[5001];
int p[5001];
int maxd[5001];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	memset(dist,-1,sizeof(dist));
	cin>>m;
	vector<pair<ll, ii> > vec;
	for(int i = 0; i < m; i++)
	{
		cin>>c[i]>>k[i]>>p[i];
		c[i]--;
		vec.pb(mp(p[i], mp(c[i],k[i])));
	}	
	sort(vec.begin(),vec.end());
	int q; cin>>q;
	while(q--)
	{
		int g; int r, a;
		cin>>g>>r>>a;
		g--;
		queue<int> q;
		q.push(g);
		memset(dist,-1,sizeof(dist));
		dist[g] = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int j = 0; j < adj[u].size(); j++)
			{
				int v = adj[u][j];
				if(dist[v] == -1)
				{
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		int lo = 0; int hi = n;
		int ans = -1;
		while(lo <= hi)
		{
			int mid = (lo+hi)>>1;
			bool pos = true;
			vector<ii> tmp;
			ll K = 0;
			for(int i = 0; i < m; i++)
			{
				if(dist[vec[i].se.fi] != -1 && dist[vec[i].se.fi] <= mid)
				{
					tmp.pb(mp(vec[i].fi, vec[i].se.se));
					K += vec[i].se.se;
				}
			}
			//cerr<<g<<' '<<r<<' '<<a<<' '<<mid<<' '<<K<<'\n';
			if(K < r)
			{
				pos = false;
			}
			else
			{
				ll C = 0; K = 0;
				for(int i = 0; i < tmp.size(); i++)
				{
					ll need = min(ll(r) - K, ll(tmp[i].se));
					K += need;
					//cerr<<g<<' '<<r<<' '<<a<<' '<<tmp[i].fi<<' '<<tmp[i].se<<' '<<need<<' '<<K<<'\n';
					C += ll(need)*ll(tmp[i].fi);
					if(C > a)
					{
						pos = false;
						break;
					}
					if(K >= r)
					{
						break;
					}
				}
				//cerr<<C<<' '<<K<<'\n';
				if(C > a)
				{
					pos = false;
				}
			}
			if(pos)
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}