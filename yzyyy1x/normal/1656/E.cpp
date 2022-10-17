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
const int N = 1e6 + 100;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

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

int n, sum[N];
VI adj[N];
int fa[N], dep[N];

void dfs(int x, int ff)
{
	fa[x] = ff;
	trav(v, adj[x])
	{
		if(v == ff)
			continue;
		dep[v] = dep[x] ^ 1;
		dfs(v, x);
	}
	if(x == 1)
		sum[x] = 0;
	else
	{
		sum[x] = (dep[x] ? -1 : 1);
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dep[1] = 1, dfs(1, 0);
	for(int i = 1; i <= n; i++)
	{
		int val = sum[i];
		trav(v, adj[i])
		{
			if(v == fa[i])
				continue;
			val -= sum[v];
		}
		cout << val << ' ';
	}
	cout << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}