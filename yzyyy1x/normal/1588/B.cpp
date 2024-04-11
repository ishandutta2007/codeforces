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
const ll mod = 998244353;//1e9 + 7;

map<pii, ll> vis;

ll ask(int l, int r)
{
	if(vis.count(pii(l, r)))
		return vis[pii(l, r)];
	cout << "? " << l << ' ' << r << endl;
	ll res;
	cin >> res;
	return vis[pii(l, r)] = res;
}

void out(int i, int j, int k)
{
	cout << "! " << i << ' ' << j << ' ' << k << endl;
	return;
}

ll calc(ll y)
{
	ll x; // x ^x - x = 2* y;
	x = (1LL + sqrt(1 + 8LL * y)) / 2LL;
	for(ll i = max(1LL, x - 10); i <= x + 10; i++)
	{
		if(i * i - i >= 2 * y)
			return i;
	}
	assert(0);
}

ll ccc(ll x, ll y)
{
	ll dt = y - x;
	return dt * (dt + 1) / 2LL;
}

void sol()
{
	ll n;
	vis.clear();
	cin >> n;
	ll l = 1, r = n, mid, cnt, tot = ask(1, n);
	
	while(l <= r)
	{
		mid = (l + r) >> 1;
		ll tmp = ask(1, mid);
		if(tmp == 0)
			l = mid + 1;
		else if(tmp == tot)
			r = mid - 1;
		else
		{
			cnt = tmp;
			break;
		}
	}
	ll v = calc(cnt);
	ll bg = mid - v + 1;
	cnt = ask(1, bg);
	if(cnt != 0)
		bg = bg - calc(cnt) + 1;
	l = bg + 1;
	ll psj = bg;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(ask(bg, mid) == ccc(bg, mid))
		{
			psj = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	++psj;
	tot -= ccc(bg, psj - 1);
	ll psk = psj + calc(tot) - 1;
	out(bg, psj, psk);
	
}

signed main()
{
	int tt;
	cin >> tt;
	while(tt--)
		sol();
}