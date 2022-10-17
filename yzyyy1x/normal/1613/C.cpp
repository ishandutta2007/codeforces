//#define LOCAL
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
//const ll inf = 1e18
const ll mod = 998244353;//1e9 + 7

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


int n;
ll a[N], h;

bool chk(ll x)
{
	ll l = 0, r = 0, cur = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > r)
		{
			cur += r - l;
			l = a[i];
		}
		r = a[i] + x;
	}
	if(r > l)
		cur += r - l;
	return cur >= h;
}

void sol()
{
	cin >> n >> h;
	for(int i = 1; i<= n; i++)
		cin >> a[i];
	ll l = 1, r = h, res = h, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(chk(mid))
			res = mid, r = mid - 1;
		else l = mid + 1;
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