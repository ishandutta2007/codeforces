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

const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, m;
int a[N], fr[N], nxt[N], rr[N];
map<int, int> mp;
int lp[N], rp[N];

int seg[N], laz[N];
int jp[N][20];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

void build(int l = 1, int r = n, int k = 1)
{
	seg[k] = 0;
	laz[k] = 0;
	if(l == r)
		return;
	build(l, mid, ls);
	build(mid + 1, r, rs);
}

void push_up(int k)
{
	seg[k] = max(seg[ls], seg[rs]);
}

void push_down(int k)
{
	if(laz[k])
	{
		seg[ls] = max(seg[ls], laz[k]);
		seg[rs] = max(seg[rs], laz[k]);
		laz[ls] = max(laz[ls], laz[k]);
		laz[rs] = max(laz[rs], laz[k]);
		laz[k] = 0;
	}
}

void upd(int L, int R, int val, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return;
	if(L <= l && r <= R)
	{
		seg[k] = max(seg[k], val);
		laz[k] = max(laz[k], val);
		return;
	}
	push_down(k);
	upd(L, R, val, l, mid, ls);
	upd(L, R, val, mid + 1, r, rs);
	push_up(k);
}

int ask(int to, int l = 1, int r = n, int k = 1)
{
	if(l == r)
		return seg[k];
	push_down(k);
	if(to <= mid)
		return ask(to, l, mid, ls);
	return ask(to, mid + 1, r, rs);
}


void sol()
{
	cin >> n >> m;
	build();
	mp.clear();
	for(int i = 0; i<= n + 10; i++)
		jp[i][0] = 0,rr[i]=0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];		
	}
	for(int i = 1; i <= n; i++)
	{
		int val = a[i];
		if(!mp.count(val))
			fr[i] = -1;
		else fr[i] = mp[val];
		mp[val] = i;
	}
	mp.clear();
	for(int i = n; i >= 1; i--)
	{
		int val = a[i];
		if(!mp.count(val))
			nxt[i] = n + 5;
		else nxt[i] = mp[val];
		mp[val] = i;
		jp[i][0] = nxt[i];
	}
	mp.clear();
	for(int i = 2; i <= n; i++)
		fr[i] = max(fr[i], fr[i - 1]);
	for(int i = n - 1; i >= 1; i--)
		nxt[i] = min(nxt[i], nxt[i + 1]);
	int	num = 0, lm = inf, rm = -inf;
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		int ps = lower_bound(fr + l, fr + n + 1, l) - fr;
		if(ps > r)
		{
			continue;
		}
		lp[++num] = ps;
		ps = upper_bound(nxt + 1, nxt + r + 1, r) - nxt;
		if(nxt[ps] > r)
			--ps;
		rp[num] = ps;
		lm = min(lm, lp[num]);
		rm = max(rm, rp[num]);
		upd(l, r, r);
	}
	jp[n + 5][0] = n + 5;
	for(int j = 1; j < 20; j++)
	{
		for(int i = 1; i <= n + 5; i++)
			jp[i][j] = jp[jp[i][j - 1]][j - 1];
	}
	for(int l = 1; l <= n; l++)
	{
		int r = ask(l);
		if(r < jp[l][0])
			continue;
		int nw = l;
		for(int j = 19; j >= 0; j--)
		{
			if(jp[nw][j] <= r)
				nw = jp[nw][j];
		}
		rr[l] = nw;
	}
	if(num == 0)
	{
		cout << 0 << '\n';
		return;
	}
	int res = n;
	for(int l = 1, r = rm; l <= lm; l++)
	{
		res = min(res, r - l + 1);
		r = max(r, rr[l]);
	}
	cout << res << '\n';
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