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
const int inf = 1e9;
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

int n, rt;
ll a[N];
VI adj[N];

ll sum = 0;
ll val[N];

void dfs(int x, int ff)
{
	if(x == rt)
	{
		ll mx[2] = {0, 0};
		trav(v, adj[x])
		{
			if(v == ff)
				continue;
			dfs(v, x);
			if(val[v] > mx[1])
				mx[1] = val[v];
			if(mx[1] > mx[0])
				swap(mx[0], mx[1]);
		}
		sum += a[x] - mx[0];
		sum += a[x] - mx[1];
		return;
	}
	val[x] = 0;
	trav(v, adj[x])
	{
		if(v == ff)
			continue;
		dfs(v, x);
		val[x] = max(val[x], val[v]);
	}
	sum += max(0LL, a[x] - val[x]);
	val[x] = max(val[x], a[x]);
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rt = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] > a[rt])
			rt = i;
	}
	dfs(rt, 0);
	cout << sum << '\n';
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