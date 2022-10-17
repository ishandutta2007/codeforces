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

const int N = 2e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n, qq;
int a[N], fa[N], ch[N][2], ps[N];

int build_tree()
{
	vector<int> stk;
	for(int i = 1; i <= n; i++)
	{
		int nw = a[i];
		int bf = 0;
		while(!stk.empty() && a[stk.back()] < nw)
		{
			int tmp = stk.back();
			stk.pop_back();
			ch[tmp][1] = bf;
			bf = tmp;
		}
		if(bf)
			ch[i][0] = bf;
		stk.pb(i);
	}
	int res;
	while(!stk.empty())
	{
		int nw = stk.back();
		stk.pop_back();
		if(!stk.empty())
			ch[stk.back()][1] = nw;
		else
			res = nw;
	}
	for(int i = 1; i <= n; i++)
	{
		if(ch[i][0])
			fa[ch[i][0]] = i;
		if(ch[i][1])
			fa[ch[i][1]] = i;
	}
	return res;
}

vector<int> factor[N];

int lp[N], rp[N];
#define node array<int, 4>
vector<node> rec;

void dfs(int x)
{
	lp[x] = rp[x] = x;
	if(ch[x][0])
		dfs(ch[x][0]), lp[x] = min(lp[x], lp[ch[x][0]]);
	if(ch[x][1])
		dfs(ch[x][1]), rp[x] = max(rp[x], rp[ch[x][1]]);
	int val = a[x];
	vector<pii> seg;
	trav(p, factor[val])
	{
		int q = val / p;
		if(p >= q)
			break;
		int l, r;
		l = ps[p], r = ps[q];
		if(l > r)
			swap(l, r);
		if(l < lp[x] || r > rp[x])
			continue;
		l = min(l, x);
		r = max(r, x);
		seg.pb(pii(l, r));
	}
	sort(all(seg), [](pii x, pii y)
	{
		return x.fi == y.fi ? x.sc < y.sc : x.fi > y.fi;
	});
	int bf = rp[x];
	trav(v, seg)
	{
		int l, r;
		tie(l, r) = v;
		if(r <= bf)
		{
			rec.pb(node{lp[x], l, r, bf});
			bf = r - 1;
		}
	}
}

vector<pii> qry[N];
vector<pii> add[N], del[N];

#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)

ll seg[N], sseg[N], laz[N], laz2[N], laz3[N];

void push_up(int k)
{
	seg[k] = seg[ls] + seg[rs];
	sseg[k] = sseg[ls] + sseg[rs];
}
void gao2(int k, int l, int r, ll v)
{
	sseg[k] += seg[k] * v;
	laz2[k] += v;
}
void gao1(int k, int l, int r, ll v)
{
	laz3[k] -= v * laz2[k];
	seg[k] += v * (r - l + 1);
	laz[k] += v;
}
void gao3(int k, int l, int r, ll v)
{
	sseg[k] += v * (r - l + 1);
	laz3[k] += v;
}

void push_down(int k, int l, int r)
{
	if(laz[k])
	{
		gao1(ls, l, mid, laz[k]);
		gao1(rs, mid + 1, r, laz[k]);
		laz[k] = 0;
	}
	if(laz2[k])
	{
		gao2(ls, l, mid, laz2[k]);
		gao2(rs, mid + 1, r, laz2[k]);
		laz2[k] = 0;
	}
	if(laz3[k])
	{
		gao3(ls, l, mid, laz3[k]);
		gao3(rs, mid + 1, r, laz3[k]);
		laz3[k] = 0;
	}
}


void upd(int L, int R, int op, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return;
	if(L <= l && r <= R)
	{
		gao1(k, l, r, op);
		return;
	}
	push_down(k, l, r);
	upd(L, R, op, l, mid, ls);
	upd(L, R, op, mid + 1, r, rs);
	push_up(k);
}

ll ask(int L, int R, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return 0;
	if(L <= l && r <= R)
		return sseg[k];
	push_down(k, l, r);
	return ask(L, R, l, mid, ls) + ask(L, R, mid + 1, r, rs);
}

ll ans[N];

void sol()
{
	for(int i = 0; i < N; i++)
		laz2[i] = 1;
	cin >> n >> qq;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j += i)
			factor[j].pb(i);
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i], ps[a[i]] = i;
	int rt = build_tree();
	dfs(rt);
	trav(v, rec)
	{
		add[v[1]].pb(pii(v[2], v[3]));
		del[v[0] - 1].pb(pii(v[2], v[3]));
	}
	for(int i = 1; i <= qq; i++)
	{
		int l, r;
		cin>> l >> r;
		qry[l].pb(pii(r, i));
	}
	for(int l = n; l >= 1; l--)
	{
		trav(v, add[l])
			upd(v.fi, v.sc, 1);
		trav(v, del[l])
			upd(v.fi, v.sc, -1);
		gao2(1, 1, n, 1);
		trav(v, qry[l])
		{
			ans[v.sc] = ask(l, v.fi);
		}
	}
	for(int i = 1; i <= qq; i++)
		cout << ans[i] << "\n";
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