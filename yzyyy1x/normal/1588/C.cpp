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
#define int long long
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

const int N = 2e6 + 100;
const ll inf = 1e18;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

int n;
int a[N];

ll seg[2][N];
ll cnt[2][N];
ll laz[2][N];

void push_up(int k)
{
	for(int i = 0; i < 2; i++)
	{
		seg[i][k] = min(seg[i][ls], seg[i][rs]);
		cnt[i][k] = 0;
		if(seg[i][k] == seg[i][ls])
			cnt[i][k] += cnt[i][ls];
		if(seg[i][k] == seg[i][rs])
			cnt[i][k] += cnt[i][rs];
	}
}

void push_down(int k)
{
	for(int i = 0; i < 2; i++)
	{
		if(!laz[i][k])
			continue;
		seg[i][ls] += laz[i][k];
		seg[i][rs] += laz[i][k];
		laz[i][ls] += laz[i][k];
		laz[i][rs] += laz[i][k];
		laz[i][k] = 0;
	}
}

void build(int l = 1, int r = n + 1, int k = 1)
{
	laz[0][k] = laz[1][k] = 0;
	if(l == r)
	{
		if(l == n + 1)
			seg[0][k] = seg[1][k] = -1, cnt[0][k] = cnt[1][k] = 0;
		else
		{
			seg[0][k] = seg[1][k] = inf;
			cnt[1][k] = (l & 1);
			cnt[0][k] = 1 - cnt[1][k];
		}
		return;
	}
	build(l, mid, ls);
	build(mid + 1, r, rs);
	push_up(k);
}

void add(int type, int L, int R, ll val, int l = 1, int r = n + 1, int k = 1)
{
	if(l > R || r < L)
		return;
	if(L <= l && r <= R)
	{
		seg[type][k] += val;
		laz[type][k] += val;
		return;
	}
	push_down(k);
	add(type, L, R, val, l, mid, ls);
	add(type, L, R, val, mid + 1, r, rs);
	push_up(k);
}

void ins(int type, int to, ll val, int l = 1, int r = n + 1, int k = 1)
{
	if(l == r)
	{
		seg[type][k] = val;
		return;
	}
	push_down(k);
	if(to <= mid)
		ins(type, to, val, l, mid, ls);
	else
		ins(type, to, val, mid + 1, r, rs);
	push_up(k);
}

int find(int l = 1, int r = n + 1, int k = 1)
{
	if(l == r)
		return l;
	push_down(k);
	if(seg[0][ls] < 0 || seg[1][ls] < 0)
		return find(l, mid, ls);
	return find(mid + 1, r, rs);
}

pll mg(pll x, pll y)
{
	pll res;
	res.fi = min(x.fi, y.fi);
	res.sc = 0;
	if(x.fi == res.fi)
		res.sc += x.sc;
	if(y.fi == res.fi)
		res.sc += y.sc;
	return res;
}

pll ask(int L, int R, int l = 1, int r = n + 1, int k = 1)
{
	if(l > R || r < L)
		return pll(inf, 0);
	if(L <= l && r <= R)
		return mg(pll(seg[0][k], cnt[0][k]), pll(seg[1][k], cnt[1][k]));
	push_down(k);
	return mg(ask(L, R, l, mid, ls), ask(L, R, mid + 1, r, rs));
}

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	ll ans = 0;
	for(int i = n - 1; i >= 1; i--)
	{
		if(i & 1)
		{
			add(0, i + 3, n, -a[i]);
			add(1, i + 2, n, a[i]);
			ins(0, i + 1, a[i + 1] - a[i]);
		}
		else
		{
			add(1, i + 3, n, -a[i]);
			add(0, i + 2, n, a[i]);
			ins(1, i + 1, a[i + 1] - a[i]);
		}
		int ps = find();
		pll x = ask(i, ps - 1);
		if(x.fi == 0)
			ans += x.sc;
	}
	for(int i = 1; i <= n; i++)
		ans += (a[i] == 0);
	cout << ans << '\n';
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