//#define LOCAL
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

namespace Poly
{
	int wh[N], cc, len;
	void ntt(VLL &a, bool inv)
	{
		for(int i = 0; i < len; i++)
		{
			if(i < wh[i])
				swap(a[i], a[wh[i]]);
		}
		for(int l = 2, md; l <= len; l <<= 1)
		{
			md = l >> 1;
			ll tmp = qpow(3, (mod - 1) / l);
			for(int i = 0; i < len; i += l)
			{
				ll mo = 1;
				for(int j = 0; j < md; j++, mo = mo * tmp % mod)
				{
					ll ha = mo * a[i + j + md] % mod;
					a[i + j + md] = (a[i + j] - ha + mod) % mod;
					a[i + j] = (a[i + j] + ha) % mod;
				}
			}
		}
		if(inv)
		{
			ll tmp = qpow(len);
			for(int i = 1; i < len / 2; i++)
				swap(a[i], a[len - i]);
			for(int i = 0; i < len; i++)
				a[i] = a[i] * tmp % mod;
		}
	}
	VLL mul(VLL x, VLL y)
	{
		int ed = x.size() + y.size() - 1;
		cc = 0, len = 1;
		while(len <= ed)
			++cc, len <<= 1;
		for(int i = 1; i < len; i++)
		{
			wh[i] = (wh[i >> 1] >> 1) | (i & 1) << (cc - 1);
		}
		x.resize(len);
		y.resize(len);
		ntt(x, 0);
		ntt(y, 0);
		for(int i = 0; i < len; i++)
		{
			x[i] = x[i] * y[i] % mod;
		}
		ntt(x, 1);
		x.resize(ed);
		return x;
	}
}

ll fac[N];
int n, deg[N];
VI adj[N];

VLL buk[N];

void dfs(int x, int ff)
{
	trav(v, adj[x])
	{
		if(v == ff)
			continue;
		dfs(v, x);
		++deg[x];
	}
	buk[x].pb(1);
	if(deg[x])
		buk[x].pb(deg[x]);
	//cerr << x << ' ' << deg[x] << ' ' << buk[x].size() << '\n';
}

VLL dac(int l, int r)
{
	if(l == r)
		return buk[l];
	int mid = l + r >> 1;
	VLL ls = dac(l, mid), rs = dac(mid + 1, r);
	return Poly::mul(ls, rs);
}

void sol()
{
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 0);
	VLL g = dac(1, n);
	ll ans = 0;
	ll coef = 1;
	for(int i = 0; i < g.size(); i++)
	{
		ll nw = coef * g[i] % mod * fac[n - i] % mod;
		ans = (ans + nw) % mod;
		coef = mod - coef;
	}
	cout << ans << '\n';
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