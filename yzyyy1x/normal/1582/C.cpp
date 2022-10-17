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

void sol()
{
	string s;
	cin >> n;
	cin >> s;
	s = '#' + s;
	int ans = inf;
	for(int c = 0; c < 26; c++)
	{
		char nw = c + 'a';
		int res = 0;
		for(int i = 1, j = n; i <= j;)
		{
			if(s[i] == s[j])
				++i, --j;
			else
			{
				if(s[i] == nw)
				{
					++res;
					++i;
				}
				else if(s[j] == nw)
				{
					++res;
					--j;
				}
				else
				{
					res = inf;
					break;
				}
			}
		}
		ans = min(ans, res);
	}
	cout << (ans >= inf ? -1 : ans) << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		sol();
	}
}