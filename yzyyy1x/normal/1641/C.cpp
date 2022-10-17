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
const int inf = 1e9;
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

struct gg{
	int l, r, tim;
	gg(){};
	gg(int l, int r, int tim):l(l), r(r), tim(tim){};
}a[N], b[N], qry[N];

int n, qnum, anum, bnum, cnum;

int seg[N][2];
int laz[N];

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)

void push_down(int k, int l, int r)
{
	if(l == r)
		return;
	if(!laz[k])
		return;
	seg[ls][0] = laz[k];
	if(mid - l + 1 > 1)
		seg[ls][1] = laz[k];
	seg[rs][0] = laz[k];
	if(r - mid > 1)
		seg[rs][1] = laz[k];
	laz[ls] = laz[rs] = laz[k];
	laz[k] = 0;
}

void upd(int k, int val)
{
	if(val > seg[k][1])
		seg[k][1] = val;
	if(seg[k][1] > seg[k][0])
		swap(seg[k][0], seg[k][1]);
	return;
}

void push_up(int k, int l, int r)
{
	seg[k][0] = seg[k][1] = -1;
	upd(k, seg[ls][0]);
	if(l != mid)
		upd(k, seg[ls][1]);
	upd(k, seg[rs][0]);
	if(mid + 1 != r)
		upd(k, seg[rs][1]);
}

void build(int l = 1, int r = n, int k = 1)
{
	if(l == r)
		seg[k][0] = inf, seg[k][1] = -1;
	else
	{
		build(l, mid, ls);
		build(mid + 1, r, rs);
		push_up(k, l, r);
	}
}

void cg(int L, int R, int val, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return;
	if(L <= l && r <= R)
	{
		seg[k][0] = val;
		if(l != r)
			seg[k][1] = val;
		laz[k] = val;
		return;
	}
	push_down(k, l, r);
	cg(L, R, val, l, mid, ls);
	cg(L, R, val, mid + 1, r, rs);
	push_up(k, l, r);
}

pii mg(pii x, pii y)
{
	x.sc = max(x.sc, y.fi);
	if(x.sc > x.fi)
		swap(x.sc, x.fi);
	x.sc = max(x.sc, y.sc);
	if(x.sc > x.fi)
		swap(x.sc, x.fi);
	return x;
}

pii ask(int L, int R, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return pii(-1, -1);
	if(L <= l && r <= R)
	{
		if(l == r)
			return pii(seg[k][0], -1);
		return pii(seg[k][0], seg[k][1]);
	}
	push_down(k, l, r);
	pii res = ask(L, R, l, mid, ls);
	res = mg(res, ask(L, R, mid + 1, r, rs));
	return res;
}

int find(int L, int R, int v, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return -1;
	if(L <= l && r <= R)
	{
		push_down(k, l, r);
		if(seg[k][0] == v)
		{
			if(l == r)
				return l;
			if(seg[ls][0] == v)
				return find(L, R, v, l, mid, ls);
			else
				return find(L, R, v, mid + 1, r, rs);
		}
		else return -1;
	}
	push_down(k, l, r);
	int res = find(L, R, v, l, mid, ls);
	if(res == -1)
		res = find(L, R, v, mid + 1, r, rs);
	return res;
} 

int bg[N], wh[N], ttt[N];

int get(int to, int l = 1, int r = n, int k = 1)
{
	if(l == r)
		return seg[k][0];
	push_down(k, l, r);
	if(to <= mid)
		return get(to, l, mid, ls);
	return get(to, mid + 1, r , rs);
}

void sol()
{
	int qq;
	cin >> n >> qq;
	for(int i = 1; i <= qq; i++)
	{
		int op;
		cin >> op;
		if(op == 0)
		{
			int l, r, x;
			cin >> l >> r >> x;
			if(x == 0)
				a[++anum] = gg(l, r, i);
			else
				b[++bnum] = gg(l, r, i);
		}
		else
		{
			int x;
			cin >> x;
			qry[++qnum] = gg(x, x, i);
		}
	}
	build();
	for(int i = anum; i >= 1; i--)
	{
		int l = a[i].l, r = a[i].r, tim = a[i].tim;
		cg(l, r, tim);
	}
	memset(ttt, 63, sizeof ttt);
	for(int i = 1; i <= bnum; i++)
	{
		{
			pii need = ask(b[i].l, b[i].r);
			bg[i] = max(b[i].tim, need.sc);
			if(bg[i] <= qq)
				wh[i] = find(b[i].l, b[i].r, need.fi);
			//cerr << "GGGG" << b[i].l << ' ' << b[i].r << ' ' << bg[i] << ' ' <<wh[i] <<'\n';
		}
		ttt[wh[i]] = min(ttt[wh[i]], bg[i]);
	}
	for(int i = 1; i <= qnum; i++)
	{
		int nw = qry[i].l;
		int tim = qry[i].tim;
		if(ttt[nw] <= tim)
			cout << "YES" << '\n';
		else
		{
			int tmp = get(nw);
			if(tmp <= tim)
				cout << "NO" << '\n';
			else
				cout << "N/A" << '\n';
		}
	}
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