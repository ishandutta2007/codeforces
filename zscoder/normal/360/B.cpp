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

int n, k;
ll a[2001];
ll dp[2001];

bool valid(ll mid)
{
	for(int i = 0; i <= n; i++)
	{
		dp[i] = i;
	}
	for(ll i = 1; i < n; i++)
	{
		//cerr << i << '\n';
		for(ll j = 0; j < i; j++)
		{
			//cerr << i << ' ' << j << ' ' << dp[j] << '\n';
			if(abs(a[i] - a[j]) <= mid*abs(i - j))
			{
				//cerr << i << ' ' << j << '\n';
				dp[i] = min(dp[i], dp[j] + (i - j - 1));
			}
		}
		//cerr << i << ' ' << dp[i] << '\n';
	}
	int i = n;
	for(ll j = 0; j < i; j++)
	{
		//cerr << i << ' ' << j << ' ' << dp[j] << '\n';
		dp[i] = min(dp[i], dp[j] + (i - j - 1));
	}
	ll ans = dp[n];
	if(dp[n]==-1) ans = 100000;
	//cerr << mid << ' ' << ans << '\n';
	if(ans <= k) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	a[n] = a[n-1];
	ll lo = 0; ll hi = ll(2e9);
	ll ans = -1;
	while(lo <= hi)
	{
		ll mid = (lo+hi)>>1;
		if(valid(mid))
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ans;
}