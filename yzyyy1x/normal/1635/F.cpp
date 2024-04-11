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
const ll inf = 5e18;

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

int n, qnum;
vector<pii> hav[N][2];
pll a[N];
ll ans[N];

ll lp[N], rp[N];

ll seg[N];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

void push_up(int k)
{
	seg[k] = min(seg[ls], seg[rs]);
}

void upd(int to, ll val, int l = 1, int r = n, int k = 1)
{
	if(l == r)
		seg[k] = min(seg[k], val);
	else
	{
		if(to <= mid)
			upd(to, val, l, mid, ls);
		else
			upd(to, val, mid + 1, r, rs);
		push_up(k);
	}
}

ll ask(int L, int R, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return inf;
	if(L <= l && r <= R)
		return seg[k];
	return min(ask(L, R, l, mid, ls), ask(L, R, mid + 1, r, rs));
}

ll calc(int i, int j)
{
	return (a[j].fi - a[i].fi) * (a[i].sc + a[j].sc);
}

void sol()
{
	cin >> n >> qnum;
	for(int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].sc;
	for(int i = 1; i <= qnum; i++)
	{
		int l, r;
		cin >> l >> r;
		hav[l][0].pb(pii(r, i));
		hav[r][1].pb(pii(l, i));
	}
	for(int i = 1; i <= qnum; i++)
		ans[i] = inf;
	VI stk;
	stk.pb(n + 1);
	memset(seg, 63, sizeof seg);
	for(int l = n; l >= 1; l--)
	{
		while(stk.size() > 1 && a[stk.back()].sc > a[l].sc)
			stk.pop_back();
		// if(l == 1)
		// 	cerr << stk.back() << '\n';
		if(stk.size() > 1)
		{
			ll val = calc(l, stk.back());
			// if(l == 1)
			// 	cerr << ">>" << val << '\n';
			upd(stk.back(), val);
		}
		trav(v, hav[l][0])
		{
			ans[v.sc] = min(ans[v.sc], ask(l, v.fi));
		}
		stk.pb(l);
	}
	stk.clear();
	stk.pb(0);
	memset(seg, 63, sizeof seg);
	for(int r = 1; r <= n; r++)
	{
		while(stk.size() > 1 && a[stk.back()].sc > a[r].sc)
			stk.pop_back();
		if(stk.size() > 1)
		{
			ll val = calc(stk.back(), r);
			upd(stk.back(), val);
		}
		trav(v, hav[r][1])
		{
			ans[v.sc] = min(ans[v.sc], ask(v.fi, r));
		}
		stk.pb(r);
	}
	for(int i = 1; i <= qnum; i++)
		cout << ans[i] << '\n';
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