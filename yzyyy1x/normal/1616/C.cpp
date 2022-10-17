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
const ll inf = 1e18;
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

int n;
int a[N], b[N];

void sol()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 1;
	for(int ps1 = 1; ps1 <= n; ps1++)
	{
		for(int ps = ps1 + 1; ps <= n; ps++)
		{
			double d = 1.0 * (a[ps] - a[ps1]) / (ps - ps1);
			int cur = 0;
			for(int i = 1; i <= n; i++)
			{
				double nw = (i - ps) * d + a[ps];
				if(fabs(nw-a[i]) < 1e-9)
					++cur;
			}
			ans = max(ans, cur);
		}
	}
	cout << n - ans << '\n';
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