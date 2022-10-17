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

int a[N], b[N], num;

bool flex[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n, x;
		cin >> n >> x;
		for(int i = 1; i <= n; i++)
			cin >> a[i], flex[i] = 0;
		num = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i >= x + 1 || i + x <= n)
				flex[i] = 1, b[++num] = a[i];
		}
		sort(b + 1, b + num + 1);
		int ps = 1;
		for(int i = 1; i <= n; i++)
		{
			if(flex[i])
				a[i] = b[ps++];
		}
		bool flg = 1;
		for(int i = 1; i < n; i++)
		{
			if(a[i] > a[i + 1])
			{
				flg = 0;
				break;
			}
		}
		if(flg)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}