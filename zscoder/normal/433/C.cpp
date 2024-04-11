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

int a[100001];
vi adj[100001];
ll ans[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if(m == 1)
	{
		cout << 0; return 0;
	}
	for(int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	ll cur = 0;
	for(int i = 0; i < m - 1; i++)
	{
		cur += abs(a[i] - a[i+1]);
	}
	for(int i = 1; i < m - 1; i++)
	{
		if(a[i-1] != a[i]) adj[a[i]].pb(a[i-1]);
		if(a[i+1] != a[i]) adj[a[i]].pb(a[i+1]);
	}
	if(a[0]!=a[1]) adj[a[0]].pb(a[1]);
	if(a[m-1]!=a[m-2]) adj[a[m-1]].pb(a[m-2]);
	ll bestans = 0;
	for(int i = 1; i <= n; i++)
	{
		//cerr << i << endl;
		if(adj[i].empty()) continue;
		sort(adj[i].begin(), adj[i].end());
		ll med = adj[i][int(adj[i].size())/2];
		for(int j = 0; j < adj[i].size(); j++)
		{
			ans[i] += abs(med - adj[i][j]);
			ans[i] -= abs(i - adj[i][j]);
		}
		bestans = min(ans[i], bestans);
	}
	cout << cur + bestans << '\n';
}