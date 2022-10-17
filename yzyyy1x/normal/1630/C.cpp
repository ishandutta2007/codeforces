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
//const ll inf = 1e18;
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

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)

int lim, seg[N << 1], sseg[N << 1];

int ask(int L, int R, int l = 0, int r = lim, int k = 1)
{
	if(l > R || r < L)
		return -inf;
	if(L <= l && r <= R)
		return seg[k];
	return max(ask(L, R, l, mid, ls), ask(L, R, mid + 1, r, rs));
}

int aask(int L, int R, int l = 0, int r = lim, int k = 1)
{
	if(l > R || r < L)
		return -inf;
	if(L <= l && r <= R)
		return sseg[k];
	return max(aask(L, R, l, mid, ls), aask(L, R, mid + 1, r, rs));
}

void push_up(int k)
{
	seg[k] = max(seg[ls], seg[rs]);
	sseg[k] = max(sseg[ls], sseg[rs]);
}

void cg(int to, int val, int l = 0, int r = lim, int k = 1)
{
	if(l == r)
		seg[k] = val, sseg[k] = val - l;
	else
	{
		if(to <= mid)
			cg(to, val, l, mid, ls);
		else
			cg(to, val, mid + 1, r, rs);
		push_up(k);
	}
}

void sol()
{
	int n;
	cin >> n;
	VI a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i], --a[i];
	VI bf(n, -1), fir(n, inf), las(n, -inf), nxt(n);
	for(int i = 0; i < n; i++)
	{
		fir[a[i]] = min(fir[a[i]], i);
		las[a[i]] = max(las[a[i]], i);
	}
	set<int>st;
	int ans = 0;
	VI buk;
	for(int i = 0; i < n; i++)
	{
		if(i < las[a[i]] && i > fir[a[i]])
		{
			++ans;
			continue;
		}
		if(i == fir[a[i]])
			buk.pb(a[i]), nxt[a[i]] = buk.size() - 1;
		else
			buk.pb(a[i]), bf[buk.size() - 1] = nxt[a[i]];
	}
	n = buk.size();
	lim = n - 1;
	memset(seg, -63, sizeof seg);
	memset(sseg, -63, sizeof sseg);
	VLL f(n);
	f[0] = 0;
	cg(0, 0);
	for(int i = 1; i < n; i++)
	{
		if(bf[i] != -1)
		{
			int nw;
			nw = ask(0, bf[i]) + (i - 1 - bf[i]);
//			cerr << "!!" << nw << '\n';
//			cerr << "??" << aask(bf[i + 1], i) << '\n';
			nw = max(nw, aask(bf[i] + 1, i) + (i - 1));
//			cerr << i << ' ' << nw << '\n';
			cg(i, nw);
		}
	}
	ans += ask(0, lim);
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