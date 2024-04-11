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

int n;
int a[N];
int divv[N];
pii cur[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], divv[i] = 1, cur[i] = pii(a[i], a[i]);
	ll res = 0, sum = 0;
	for(int r = 1; r <= n; r++)
	{
		int l = r - 1;
		while(l > 0 && cur[l].sc > cur[l + 1].fi)
		{
			int x;
			ll dt = divv[l];
			x = (a[l] + cur[l + 1].fi - 1) / cur[l + 1].fi;
			divv[l] = x;
			cur[l].sc = (a[l] / x) + (a[l] % x ? 1 : 0);
			cur[l].fi = (a[l] / x);
			dt = x - dt;
			sum = (sum + l * dt) % mod;
			--l;
		}
		res = (res + sum) % mod;
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