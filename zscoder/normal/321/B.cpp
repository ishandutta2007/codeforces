#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

bool used[101];
int A, C;
vi a, d, c;

int del(int x)
{
	for(int i = 0; i < c.size(); i++)
	{
		if(c[i] >= x && !used[i])
		{
			used[i] = true;
			return i;
		}
	}
	return -1;
}

int solve()
{
	int dsum = 0;
	for(int i = 0; i < d.size(); i++)
	{
		int cur = del(d[i]+1);
		if(cur == -1) return 0;
	}
	for(int i = 0; i < A; i++)
	{
		int cur = del(a[i]);
		if(cur == -1) return 0;
		dsum += (c[cur] - a[i]);
	}
	int ptr = del(0);
	while(ptr != -1)
	{
		dsum += c[ptr];
		ptr = del(0);
	}
	return dsum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int x; cin >> x;
		if(s[0] == 'A') a.pb(x);
		else d.pb(x);
	}
	c.resize(m);
	for(int i = 0; i < m; i++) cin >> c[i];
	sort(a.begin(),a.end()); sort(d.begin(),d.end()); sort(c.begin(),c.end());
	int ans1, ans2;
	A = a.size(); C = c.size();
	ans1 = 0;
	for(int i = 0; i < min(A, C); i++)
	{
		ans1 += max(0, c[C-1-i] - a[i]);
	}
	ans2 = solve();
	//cerr << ans1 << ' ' << ans2 << '\n';
	cout << max(ans1, ans2);
}