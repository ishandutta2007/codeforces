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
	int wh[N], len, cc;
	void ntt(VLL &a, bool inv)
	{
		for(int i = 0; i < len; i++)
			if(i < wh[i])swap(a[i], a[wh[i]]);
		for(int l = 2; l <= len; l <<= 1)
		{
			int md = l >> 1;
			ll tp = qpow(3, (mod - 1) / l);
			for(int i = 0; i < len; i += l)
			{
				ll mo = 1;
				for(int j = 0; j < md; j++, mo = mo * tp % mod)
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
		cc = 0, len = 1;
		while(len < x.size() + y.size())
			++cc, len <<= 1;
		for(int i = 1; i < len; i++)
		{
			wh[i] = (wh[i >> 1] >> 1) | ((i & 1) << (cc - 1));
		}
		int bf = x.size() + y.size() - 1;
		x.resize(len);
		y.resize(len);
		ntt(x, 0), ntt(y, 0);
		for(int i = 0; i < len; i++)
			x[i] = x[i] * y[i] % mod;
		ntt(x, 1);
		x.resize(bf);
		return x;
	}
}

ll fac[N], ifac[N];

ll C(ll x, ll y)
{
	if(x < y || y < 0)
		return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

void init()
{
	int n = N - 1;
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n]);
	for(int i = n - 1; i >= 0; i--)
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

int a[N], b[N], cnt[N];

const int lim = 2e5 + 100;

int fen[lim + 100];

void add(int x, int y)
{
	for( ; x <= lim; x += x & -x)
		fen[x] += y;
	return;
}

int ask(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += fen[x];
	return res;
}

void sol()
{
	init();
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]]++, add(a[i], 1);
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	ll sum = 0;
	for(int i = 0; i <= lim; i++)
	{
		if(cnt[i])
			++sum;
	}
	ll div = 1;
	for(int i = 1; i <= lim; i++)
	{
		if(cnt[i])
			div = div * ifac[cnt[i]] % mod;
	}
	ll ans = 0;
	bool ff = 1;
	for(int i = 1; i <= n && i <= m; i++)
	{
		ll t = fac[(n - i)] * div % mod;
		int nw = b[i];
		ll tmp = ask(nw - 1);
		tmp = tmp * t % mod;
		ans = (ans + tmp) % mod; 
		int cur = ask(nw) - ask(nw - 1);
		if(cur == 0)
		{
			ff = 0;
			break;
		}
		div = div * fac[cur] % mod;
		div = div * ifac[cur - 1] % mod;
		add(b[i], -1);
	}
	if(ff && n < m)
		ans = (ans + 1) % mod;
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