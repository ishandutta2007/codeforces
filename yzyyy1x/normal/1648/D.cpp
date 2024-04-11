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
const int N = 2e6 + 100;
const ll inf = 1e18;

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


template<class node, class Mg = plus<node>>
struct Seg_tree{
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	const int n;
	const Mg mg;
	vector<node> seg;
	Seg_tree(int n):n(n), mg(Mg()), seg(n * 5){};
	Seg_tree(vector<node> init): Seg_tree(init.size())
	{
		function<void(int, int, int)> build = [&](int l, int r, int k)
		{
			if(l == r)
				return (void)(seg[k] = init[l]);
			build(l, mid, ls);
			build(mid + 1, r, rs);
			push_up(k);
		};
		build(1, n, 1);
	}
	void push_up(int k){seg[k] = mg(seg[ls], seg[rs]);}
	void upd(int to, const node &val, int l, int r, int k)
	{
		if(l == r)
			return (void)(seg[k] = val);
		if(to <= mid)
			upd(to, val, l, mid, ls);
		else
			upd(to, val, mid + 1, r, rs);
		push_up(k);
	}
	void upd(int to, const node &val)
	{upd(to, val, 1, n, 1);}
	node ask(int L, int R, int l, int r, int k)
	{
		if(l > R || r < L)
			return node();
		if(L <= l && r <= R)
			return seg[k];
		return mg(ask(L, R, l, mid, ls), ask(L, R, mid + 1, r, rs));
	}
	node ask(int L, int R)
	{return ask(L, R, 1, n, 1);}
	#undef mid
	#undef ls
	#undef rs
};

int n, m;
ll a[4][N];
ll f[N], g[N];
struct node1{
	ll x;
	node1(ll x = -inf):x(x){};
};
node1 operator +(const node1 &x, const node1 & y)
{
	return node1(max(x.x, y.x));
}

struct node2{
	ll x, y, sum;
	node2(ll x = -inf, ll y = -inf): x(x), y(y), sum(x + y){};
};
node2 operator +(const node2 &x, const node2 & y)
{
	node2 res;
	res.sum = max({x.x + y.y, x.sum, y.sum});
	res.x = max(x.x, y.x);
	res.y = max(x.y, y.y);
	return res;
}

void sol()
{
	cin >> n >> m;
	for(int row = 1; row <= 3; row++)
		for(int i = 1; i <= n; i++)
			cin >> a[row][i];
	for(int i = 1; i <= n; i++)
	{
		f[i] = a[1][i];
		if(i > 1)
			f[i] += f[i - 1] - a[2][i - 1];
	}
	for(int i = n; i >= 1; i--)
	{
		g[i] = a[3][i];
		if(i < n)
			g[i] += g[i + 1] - a[2][i + 1];
	}
	vector<array<ll, 3> > seg(m);
	for(int i = 0; i < m; i++)
		cin >> seg[i][0] >> seg[i][1] >> seg[i][2];
	sort(all(seg));
	Seg_tree<node1> seg_tree1(n);
	for(int i = 1; i <= n; i++)
	{
		seg_tree1.upd(i, node1(f[i]));
	}
	trav(v, seg)
	{
		auto [l, r, c] = v;
		ll mx = seg_tree1.ask(l, r).x;
		if(r + 1 <= n)
		{
			f[r + 1] = max(f[r + 1], mx - c);
			seg_tree1.upd(r + 1, node1(f[r + 1]));
		}
	} 
	Seg_tree<node2> seg_tree2(n);
	for(int i = 1; i <= n; i++)
		seg_tree2.upd(i, node2(f[i], g[i]));// cerr << "!!" << f[i] << ' ' << g[i] << '\n';
	ll ans = -inf;
	trav(v, seg)
	{
		auto [l, r, c] = v;
		ans = max(ans, seg_tree2.ask(l, r).sum - c);
	}
	for(int i = 1; i <= n; i++)
		ans += a[2][i];
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