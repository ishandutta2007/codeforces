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

int n;
int a[N], cnt[N], b[N];

VI adj[N];

bool vis[N], ins[N], ifok;

void dfs(int x)
{
	vis[x] = ins[x] = 1;
	trav(v, adj[x])
	{
		if(ins[v])
			ifok = 0;
		if(!vis[v])
			dfs(v);
	}
	ins[x] = 0;
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cnt[i] = 0, adj[i].clear(), vis[i] = ins[i] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], ++cnt[a[i]];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	int wh = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[i] > cnt[wh])
			wh = i;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == wh || b[i] == wh)
			continue;
		adj[a[i]].pb(b[i]);
	}
	ifok = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i])dfs(i);
	cout << (ifok ? "AC" : "WA") << '\n';
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
/*
1 3 2 2 4 4 4 4
2 2 4 4 1 3 4 4
*/