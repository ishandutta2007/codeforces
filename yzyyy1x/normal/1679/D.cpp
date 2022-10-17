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
ll step;
int a[N];

pii edge[N];
VI adj[N];

bool vis[N];
ll mx_d;

int dfn[N], low[N], tim;
ll can[N];
bool ins[N];
vector<int> stk;

void dfs(int x)
{
	dfn[x]=low[x]=++tim;
	ins[x]=1;
	stk.pb(x);
	can[x] = 1;
	trav(nx, adj[x])
	{
		if(!dfn[nx])
		{
			dfs(nx);
			low[x]=min(low[x],low[nx]);
			can[x] = max(can[x], can[nx] + 1);
		}
		else
		{
			if(ins[nx])
			{
				low[x]=min(low[x],dfn[nx]);
			}
			else
			{
				can[x] = max(can[x], can[nx] + 1);
			}
		}
	}
	if(low[x]==dfn[x])
	{
		int nw;
		int sz = 0;
		while(1)
		{
			nw=stk.back(), stk.pop_back();
			ins[nw]=0;
			++sz;
			if(nw==x)break;
		}
		if(sz >= 2)
			mx_d = step + 5;
	}
	mx_d = max(mx_d, can[x]);
}

void sol()
{
	cin >> n >> m >> step;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> edge[i].fi >> edge[i].sc;
	int l = 1, r = inf + 5, res = inf + 5, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		for(int i = 1; i <= n; i++)
			adj[i].clear(), dfn[i] = 0;
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			tie(u, v) = edge[i];
			if(a[u] <= mid && a[v] <= mid)
				adj[u].pb(v);
		}
		mx_d = 0, tim = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] <= mid && !dfn[i])
				dfs(i);
		}
		if(mx_d >= step)
			res = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	if(res > inf)
		res = -1;
	cout << res << '\n';
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