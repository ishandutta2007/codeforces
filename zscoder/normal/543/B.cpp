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

int dist[3001][3001];
vi adj[3001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) dist[i][j] = 1000000;
		dist[i][i] = 0;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			//cerr << i << ' ' << u << '\n';
			for(int j = 0; j < adj[u].size(); j++)
			{
				int v = adj[u][j];
				if(dist[i][u] + 1 < dist[i][v])
				{
					dist[i][v] = dist[i][u] + 1;
					q.push(v);
				}
			}
		}
	}
	
	int s1, e1, t1;
	int s2, e2, t2;
	cin>>s1>>e1>>t1>>s2>>e2>>t2;
	s1--; e1--; s2--; e2--;
	int ans = 1230291;
	for(int i = 0; i < 2; i++)
	{
		swap(s1, e1);
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				int a1 = dist[s1][j] + dist[j][k] + dist[k][e1];
				int a2 = dist[s2][j] + dist[j][k] + dist[k][e2];
				//cerr << a1 << ' ' << a2 << '\n';
				if(a1 <= t1 && a2 <= t2)
				{
					ans = min(ans, a1+a2-dist[j][k]);
				}
			}
		}
	}
	if(dist[s1][e1]<=t1&&dist[s2][e2]<=t2) ans = min(ans, dist[s1][e1]+dist[s2][e2]);
	if(ans >= 100000)
	{
		cout << -1; return 0;
	}
	cout << m - ans;
}