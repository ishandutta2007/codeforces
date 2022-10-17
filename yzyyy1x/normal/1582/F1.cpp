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
bitset<520>bst[520];

void sol()
{
	cin >> n;
	for(int i = 0; i <= 512; i++)
		bst[i].reset(), bst[i][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	bitset<520>nw, ans;
	nw.reset();
	ans.reset();
	ans.set(0);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 0)
			continue;
		nw.reset();
		for(int j = 0; j < 512; j++)
		{
			if(bst[a[i] - 1][j] == 1)
				nw[j ^ a[i]] = 1;
		}
		for(int j = a[i]; j <= 500; j++)
		{
			bst[j] |= nw; 
		}
		ans |= nw;
	}
	cout << ans.count() << '\n';
	for(int j = 0; j < 512; j++)
		if(ans[j])cout << j << ' ';
	cout << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol();
}