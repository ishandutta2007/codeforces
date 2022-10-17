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

void sol()
{
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n, k;
		cin >> n >> k;
		VI ans(n);
		for(int i = 0; i < n; i++)
			ans[i] = n - i - 1;
		if(k == n - 1)
		{
			if(n == 4)
			{
				cout << -1 << '\n';
				continue;
			}
			else
			{
				ans[1] = 3;
				ans[3] = 1;
				ans[0] = n - 4;
				ans[n - 4] = 0;
				ans[n - 2] = n - 1;
				ans[n - 1] = n - 2;
			}
		}
		else
		{
			swap(ans[0], ans[k]);
			swap(ans[n - 1], ans[n - 1 - k]);
		}
		for(int i = 0; i < n; i++)
		{
			if(ans[i] > i)
				cout << i << ' ' << ans[i] << '\n';
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