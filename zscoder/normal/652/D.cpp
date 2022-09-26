#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<ii, int> > vec;
pbds s;
int ans[200001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vec.pb(mp(ii(x, y), i));
	}
	sort(vec.begin(), vec.end());
	for(int i = n - 1; i >= 0; i--)
	{
		ans[vec[i].se] = s.order_of_key(vec[i].fi.se);
		s.insert(vec[i].fi.se);
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}