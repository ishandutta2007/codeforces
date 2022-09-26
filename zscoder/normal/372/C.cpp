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

ll a[501];
ll b[501];
ll t[501];
ll dp[2][300001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, d; cin >> n >> m >> d;
	for(int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> t[i];
	}
	ll tim = 1;
	for(int i = 0; i < m; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		deque<ll> dq;
		ll interval = min(ll(n), ll(t[i] - tim)*ll(d));
		for(ll j = 1; j <= interval; j++)
		{
			while(!dq.empty() && dp[prev][dq.back()] <= dp[prev][j]) dq.pop_back();
			dq.pb(j);
		}
		for(ll j = 1; j <= n; j++)
		{
			ll k = j + interval;
			if(k <= n)
			{
				while(!dq.empty() && dp[prev][dq.back()] <= dp[prev][k]) dq.pop_back();
				dq.pb(k);
			}	
			dp[cur][j] = dp[prev][dq.front()] + ll(b[i] - abs(a[i] - j));
			while(!dq.empty() && dq.front()	<= ll(j - interval)) dq.pop_front();
		}
		tim = t[i];
	}
	ll ans = -ll(1e18);
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[(m&1)^1][i]);
	}
	cout << ans;
}