#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v, x) for(auto v:x)
#define VI vector<int>
#define VLL vector<ll>
//define double long double
#define all(x) (x).begin(),(x).end()
using namespace std;
const double eps = 1e-10;//1e-12
const int N = 2e5 + 100;
const ll mod = 998244353;//1e9 + 7;
const int inf = 1e9;

int n, m, a[N];

int dp[8200], ndp[8200];
vector<int> hav[5100];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		hav[x].pb(i);
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i <= 5000; i++)
	{
		if(!hav[i].size())
			continue;
		memset(ndp, 63, sizeof ndp);
		for(int val = 0; val < 8192; val++)
		{
			if(dp[val] < inf)
			{
				int ps;
				ps = lower_bound(all(hav[i]), dp[val]) - hav[i].begin();
				if(ps == hav[i].size())
					continue;
				ndp[val ^ i] = min(ndp[val ^ i], hav[i][ps]);
			}
		}
		for(int val = 0; val < 8192; val++)
			dp[val] = min(dp[val], ndp[val]);
	}
	VI may;
	for(int i = 0; i < 8192; i++)
	{
		if(dp[i] < inf)
			may.pb(i);
	}
	cout << may.size() << '\n';
	trav(v, may)
		cout << v << ' ';
	cout << '\n';
}