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

const int N = 4e6 + 100;
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

int n;
ll a[N], s[N], f[N];
ll seg[N][3];

int m;

void build(int l = 1, int r = m, int k = 1)
{
	for(int i = 0; i < 3; i++)
		seg[k][i] = -inf;
	if(l == r)
		return;
	build(l, mid, ls);
	build(mid + 1, r, rs);
}

int ppp;

void upd(int to, ll val, int l = 1, int r = m, int k = 1)
{
	if(l == r)
	{
		seg[k][0] = max(seg[k][0], val - ppp);
		seg[k][1] = max(seg[k][1], val);
		seg[k][2] = max(seg[k][2], val + ppp);
		return;
	}
	if(to <= mid)
		upd(to, val, l, mid, ls);
	else
		upd(to, val, mid + 1, r, rs);
	for(int i = 0; i < 3; i++)
		seg[k][i] = max(seg[ls][i], seg[rs][i]);
	return;
}

ll ask(int L, int R, int tp, int l = 1, int r = m, int k = 1)
{
	if(l > R || r < L)
		return -inf;
	if(L <= l && r <= R)
		return seg[k][tp];
	return max(ask(L, R, tp, l, mid, ls), ask(L, R, tp, mid + 1, r, rs));
}

void sol()
{
	cin >> n;
	VLL buk;
	buk.pb(0LL);
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i - 1] + a[i], buk.pb(s[i]);
	sort(all(buk));
	buk.erase(unique(all(buk)), buk.end());
	for(int i = 0; i <= n; i++)
		s[i] = lower_bound(all(buk), s[i]) - buk.begin() + 1;
	m = buk.size() + 1;
	build();
	ppp = 0;
	upd(s[0], 0);
	for(int i = 1; i <= n; i++)
	{
		ll mx;
		mx = ask(1, s[i] - 1, 0) + i;
		mx = max(mx, ask(s[i], s[i], 1));
		mx = max(mx, ask(s[i] + 1, m, 2) - i);
		f[i] = mx;
		ppp = i;
		upd(s[i], f[i]);
	}
	cout << f[n] << '\n';
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
!!!5
4 4 2 5 1
*/