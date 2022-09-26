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

ll dp[100001];
ll dp2[100001];
ll a[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		dp2[i] = dp2[i-1] + a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
	{
		dp[i] = a[i] + dp[i-1];
	}
	int q; cin >> q;
	while(q--)
	{
		int t, l, r; cin >> t >> l >> r;
		if(t == 1)
		{
			cout << dp2[r] - dp2[l-1] << '\n';
		}
		else cout << dp[r]-dp[l-1]<<'\n';
	}
}