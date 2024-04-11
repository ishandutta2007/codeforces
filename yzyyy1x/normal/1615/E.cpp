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
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n, m, num;
int a[N], lp[N], rp[N], val[N], dep[N], fa[N], wh[N];
bool vis[N];

VI adj[N];

void dfs(int x, int ff)
{
	bool flg = 1;
	lp[x] = inf, rp[x] = -inf;
	fa[x] = ff;
	trav(v, adj[x])
	{
		if(v == ff)
			continue;
		flg = 0;
		dep[v] = dep[x] + 1, dfs(v, x);
		lp[x] = min(lp[x], lp[v]);
		rp[x] = max(rp[x], rp[v]);
	}
	if(flg)
	{
		++num;
		lp[x] = rp[x] = num;
		val[num] = dep[x];
		wh[num] = x;
		return;
	}
}

int seg[N], laz[N];

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)

void push_up(int k)
{
	seg[k] = max(seg[ls], seg[rs]);
}

void push_down(int k)
{
	if(laz[k])
	{
		seg[ls] += laz[k];
		seg[rs] += laz[k];
		laz[ls] += laz[k];
		laz[rs] += laz[k];
		laz[k] = 0;
	}
}

void build(int l = 1, int r = num, int k = 1)
{
	if(l == r)
		return (void)(seg[k] = val[l]);
	build(l, mid, ls);
	build(mid + 1, r, rs);
	push_up(k);
}

int find(int l = 1, int r = num, int k = 1)
{
	if(l == r)
		return l;
	push_down(k);
	if(seg[rs] < seg[ls])
		return find(l, mid, ls);
	return find(mid + 1, r , rs);
}

void upd(int L, int R, int val, int l = 1, int r = num, int k = 1)
{
	if(l > R || r < L)
		return;
	if(L <= l && r <= R)
	{
		seg[k] += val;
		laz[k] += val;
		return;
	}
	push_down(k);
	upd(L, R, val, l, mid, ls);
	upd(L, R, val, mid + 1, r, rs);
	push_up(k);
}

void sol()
{
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dep[1] = 1, dfs(1, 0);
	//cerr << num << '\n';
	if(num <= m)
	{
		ll ans = -1e18;
		for(int i = num; i <= m; i++)
		{
			ans = max(ans, 1LL * i * (n - i));
		}
		cout << ans << '\n';
	}
	else
	{
		build();
		for(int i = 1; i <= m; i++)
		{
			int x = find();
			x = wh[x];
			while(x != 0 && !vis[x])
			{
				vis[x] = 1;
				upd(lp[x], rp[x], -1);
				x = fa[x];
			}
		}
		int blue = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
				++blue;
		}
		ll ans = 1e18;
		for(int i = 0; i <= blue; i++)
			ans = min(ans, 1LL * (n - m - i) * (m - i));
		cout << ans << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		sol();
}