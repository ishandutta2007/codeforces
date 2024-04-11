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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll dp[111][2];
ll a[111];
ll s[111];

ll sum(int l, int r)
{
	if(l==0) return s[r];
	else return s[r]-s[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		s[i]=a[i];
		if(i>0) s[i]+=s[i-1];
	}
	dp[n-1][0] = a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		dp[i][0] = max(dp[i+1][0], dp[i+1][1] + a[i]);
		dp[i][1] = sum(i,n-1) - dp[i][0];
	}
	cout<<sum(0,n-1) - dp[0][0]<<' '<<dp[0][0]<<'\n';
}