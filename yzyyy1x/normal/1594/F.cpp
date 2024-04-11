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

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		ll s, n, k;
		cin >> s >> n >> k;
		if(s < k)
			cout << "NO" << '\n';
		else if(s == k)
			cout << "YES" << '\n';
		else
		{
			++s;
			ll num;
			ll len1 = s / k + 1, len2 = s / k;
			ll num1 = s % k, num2 = k - s % k;
			num = (len1 + 1) / 2 * num1 + (len2 + 1) / 2 * num2;
			--num;
			if(num >= n)
				cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}
	}
}