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

int a[200001];
ll dp[200001];
ll pref[200001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	pref[0] = a[0];
	for(int i=1;i<n; i++)
	{
		pref[i] = pref[i-1]+a[i];
	}
	//dp[n][0] = dp[n][1] = 0;
	//ll max1 = pref[n-1]; ll min0 = -pref[n-1];
	dp[n-1] = 0;
	ll maxi = pref[n-1]-dp[n-1];
	for(int i = n - 2; i >= 0; i--)
	{
		dp[i] = maxi;
		maxi = max(pref[i]-dp[i], maxi);
	}
	cout << dp[0];
}