#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;

int n;
int a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int x, y, z, m;
		cin >> x >> y >> z >> m;
		int mx = max(0, x - 1) + max(0, y - 1) + max(0, z - 1);
		if(y < z)swap(y, z);
		if(x < y) swap(x, y);
		int mn = max(0, x - y - z - 1);
		if(mn <= m && m <= mx)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}