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
const int N = 2e6 + 100;
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

#define node tuple<int, int, int>

ll qpow(ll x, ll y = mod - 2)
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

int n;
vector<node> adj[N];

int in[N], ot[N], tim;

pii tofa[N];
vector<pii> del[N], add[N];

void dfs(int x, int ff)
{
	in[x] = ++tim;
	for(auto [v, p, q] : adj[x])
	{
		if(v == ff)
			continue;
		tofa[v] = pii(q, p);
		dfs(v, x);
	}
	ot[x] = tim;
	if(x != 1)
	{
		int q, p;
		tie(q, p) = tofa[x];
		for(int j = 2; j * j <= q; j++)
		{
			while(q % j == 0)
				add[j].pb(pii(in[x], ot[x])), q /= j;
		}
		//cerr << "!!" << x << ' ' << q << ' '<<p << '\n';
		if(q > 1)
			add[q].pb(pii(in[x], ot[x]));
		for(int j = 2; j * j <= p; j++)
		{
			while(p % j == 0)
				del[j].pb(pii(in[x], ot[x])), p /= j;
		}
		if(p > 1)
			del[p].pb(pii(in[x], ot[x]));
	}
}

int seg[N], laz[N];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

void push_up(int k)
{
	seg[k] = min(seg[ls], seg[rs]);
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

void upd(int L, int R, int val, int l = 1, int r = tim, int k = 1)
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

ll tot;

void dfs2(int x, int ff, ll nw)
{
	tot = (tot + nw) % mod;
	for(auto [v, p, q] : adj[x])
	{
		if(v == ff)
			continue;
		dfs2(v, x, nw * q % mod * qpow(p) % mod);
	}
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		adj[i].clear(), del[i].clear(), add[i].clear();
	tim = 0;
	for(int i = 1; i < n; i++)
	{
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		int g = __gcd(x, y);
		x /= g;
		y /= g;
		adj[u].pb(make_tuple(v, x, y));
		adj[v].pb(make_tuple(u, y, x));
	}
	dfs(1, 0);
	ll res = 1;
	for(int i = 1; i <= n; i++)
	{
		if(add[i].empty() && del[i].empty())
			continue;
		trav(v, add[i])
			upd(v.fi, v.sc, 1);
		trav(v, del[i])
			upd(v.fi, v.sc, -1);
		int nw = seg[1];
		//cerr << nw << '\n';
		nw = -nw;
		res = res * qpow(i, nw) % mod;
		trav(v, add[i])
			upd(v.fi, v.sc, -1);
		trav(v, del[i])
			upd(v.fi, v.sc, 1);
		//if(i == 3)exit(0);
	}
	tot = 0;
	dfs2(1, 0, res);
	cout <<tot << '\n';
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