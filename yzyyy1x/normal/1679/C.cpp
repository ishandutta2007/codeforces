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

const int N = 1e6 + 100;
const int inf = 1e9;
//const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7

int n;
int a[2][N];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)

int seg[2][N << 2];

void push_up(int op, int k)
{
	seg[op][k] = seg[op][ls] + seg[op][rs];
}

void upd(int op, int to, int l = 1, int r = n, int k = 1)
{
	if(l == r)
	{
		seg[op][k] = (a[op][to] >= 1);
		return;
	}
	if(to <= mid)
		upd(op, to, l, mid, ls);
	else upd(op, to, mid + 1, r, rs);
	push_up(op, k);
}

int ask(int op, int L, int R, int l = 1, int r = n, int k = 1)
{
	if(l > R || r < L)
		return 0;
	if(L <= l && r <= R)
		return seg[op][k];
	return ask(op, L, R, l, mid, ls) + ask(op, L, R, mid + 1, r, rs);
}

void sol()
{
	int qq;
	cin >> n >> qq;
	while(qq--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int x, y;
			cin >> x >> y;
			a[0][x]++;
			a[1][y]++;
			upd(0, x);
			upd(1, y);
		//	cerr << "GGG" << y << ' ' << a[1][y] << ' ' << ask(1, 2, 2) << '\n';
		}
		else if(op == 2)
		{
			int x, y;
			cin >> x >> y;
			a[0][x]--;
			a[1][y]--;
			upd(0, x);
			upd(1, y);
		}
		else
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			ll l = ask(0, x1, x2), r = ask(1, y1, y2);
			//cerr << "GG" << l << ' ' << r << '\n';
			cout << ((l * (y2 - y1 + 1) + r * (x2 - x1 + 1) - l * r == 1LL * (x2 - x1 + 1) * (y2 - y1 + 1)) ? "Yes" : "No" )<< '\n';
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