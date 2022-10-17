#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
#define VI vector<int>
#define all(x) ((x).begin(), (x).end())
using namespace std;
const int N = 1e6 + 100;
const ll mod = 1e9 + 7;

ll n, num;
ll a[N];

ll qpow(ll x, ll y)
{
	ll res = 1;
	while(y)
	{
		if(y & 1)
			res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

map<ll, vector<ll>>adj;

map<ll, bool>vis;
map<ll, ll>col;

map<ll, ll>dp[6];

ll calc(ll x)
{
	for(ll i = n; i >= 1; i--)
	{
		if(1LL << (i - 1) <= x)
			return i;
	}
}

void dfs(ll x)
{
	//cerr << x << '\n';
	if(col.find(x) != col.end())
	{
		for(int i = 0; i < 6; i++)
			dp[i][x] = 0;
		dp[col[x]][x] = 1;
	}
	else
	{
		for(int i = 0; i < 6; i++)
			dp[i][x] = 1;
	}
	ll dep = calc(x);
	ll las = n - dep;
//	cerr << x << ' ' << dep << ' ' <<las << '\n';
	ll tmp = qpow(4, (1LL << las) - 1);
	if(adj.find(x) == adj.end() || adj[x].size() <= 1)
	{
		for(int i = 0; i < 6; i++)
			dp[i][x] = (dp[i][x] * tmp) % mod;
	}
	if(adj.find(x) == adj.end() || adj[x].size() == 0)
	{
		for(int i = 0; i < 6; i++)
			dp[i][x] = (dp[i][x] * tmp) % mod;
		return;
	}
	trav(v, adj[x])
	{
	//	cerr << "??" << x << ' ' << v << '\n';
		dfs(v);
		for(int i = 0; i < 6; i++)
		{
			if(!dp[i][x])
				continue;
			ll tmp = 0;
			for(int j = 0; j < 6; j++)
			{
				if(i == j || i == (j ^ 1))
					continue;
				tmp = (tmp + dp[j][v]) % mod;
			}
			dp[i][x] = (dp[i][x] * tmp % mod);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> num;
	for(int i = 1; i <= num; i++)
	{
		ll x;
		string s;
		cin >> x >> s;
		a[i] = x;
		if(s == "white")
			col[a[i]] = 0;
		if(s == "yellow")
			col[a[i]] = 1;
		if(s == "green")
			col[a[i]] = 2;
		if(s == "blue")
			col[a[i]] = 3;
		if(s == "red")
			col[a[i]] = 4;
		if(s == "orange")
			col[a[i]] = 5;
	}
	VI bin;
	for(int i = 1; i <= num; i++)
	{
		ll x = a[i];
		while(x > 1 && !vis[x])
		{
			vis[x] = 1;
			ll y = x / 2;
			adj[y].pb(x);
			x = y;
		}
	}
	dfs(1);
	ll ans = 0;
	for(int i = 0; i < 6; i++)
		ans = (ans + dp[i][1]) % mod;
	cout << ans << '\n';
	return 0;
}
/*
60
1
1152921504606846975 white
*/