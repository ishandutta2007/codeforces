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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[111111];
ii a[111111];
int t[111111];

int dist(const ii &x, const ii &y)
{
	return abs(x.fi-y.fi)+abs(x.se-y.se);
}

int mx[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r,n; cin>>r>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t[i]>>a[i].fi>>a[i].se;
	}
	ii ori = {1,1};
	memset(dp,-1,sizeof(dp));
	memset(mx,-1,sizeof(mx));
	for(int i=0;i<n;i++)
	{
		if(dist(ori,a[i])<=t[i])
		{
			dp[i]=1;
		}
		if(i-1002>=0) dp[i]=max(dp[i],mx[i-1002]+1);
		for(int j=max(0,i-1001);j<i;j++)
		{
			if(dist(a[j],a[i])<=t[i]-t[j]&&dp[j]>=0) dp[i]=max(dp[i],dp[j]+1);
		}
		if(i>0) mx[i]=max(mx[i-1],dp[i]);
		else mx[i]=dp[i];
	}
	cout<<max(mx[n-1],0)<<'\n';
}