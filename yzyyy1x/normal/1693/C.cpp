#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define all(x) (x).begin(), (x).end()
#define VI vector<int>
#define VLL vector<ll>
#define pll pair<ll, ll>
#define double long double
//#define int long long
using namespace std;

#ifdef LOCAL
void debug_out(){cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
	cerr << " " << to_string(H);
	debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
int deg[N];
VI adj[N];
int dis[N];

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[y].pb(x);
		++deg[x];
	}
	memset(dis, 63, sizeof dis);
	dis[n] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0, n));
	while(!pq.empty())
	{
		int nw = pq.top().sc;
		int d = pq.top().fi;
		pq.pop();
		if(d > dis[nw])
			continue;
		trav(v, adj[nw])
		{
			--deg[v];
			int tmp = d + deg[v] + 1;
			if(dis[v] > tmp)
			{
				dis[v] = tmp;
				pq.push(pii(tmp, v));
			}
		}
	}
	cout << dis[1] << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	int tt;
//	cin >> tt;
//	while(tt--)
		sol();
}