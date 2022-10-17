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

int n, m, a[N];

void sol()
{
	string s;
	cin >> s;
	int n = s.length();
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		if(s[i] == 'a')
			++cnt0;
		else ++cnt1;
		while(s[j] == s[i] && j < n)
			++j;
		--j;
		i = j;
	}
	if(abs(cnt0 - cnt1) == 1)
		cout << s << '\n';
	else
	{
		if(s[n - 1] == 'a')
			s[n - 1] = 'b';
		else
			s[n - 1] = 'a';
		cout << s << '\n';
	}
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