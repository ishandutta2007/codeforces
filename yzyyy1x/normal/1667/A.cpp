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
const ll inf = 1e18;
const ll mod = 998244353;//1e9 + 7;

int n;
ll a[N], b[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = inf;
	for(int ps = 1; ps <= n; ps++)
	{
		ll nw = 0;
		b[ps] = 0;
		for(int i = ps + 1; i <= n; i++)
		{
			ll need = b[i - 1] + 1;
			ll tmp = need / a[i];
			if(need % a[i])
				++tmp;
			nw += tmp;
			b[i] = tmp * a[i];
		}
		for(int i = ps - 1; i >= 1; i--)
		{
			ll need = b[i + 1] + 1;
			ll tmp = need / a[i];
			if(need % a[i])
				++tmp;
			nw += tmp;
			b[i] = tmp * a[i];
		}
		ans = min(ans, nw);
	}
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