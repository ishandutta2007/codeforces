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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int MOD;
int add(int a, int b)
{
	a+=b;
	a%=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int dp[55];

int getrange(int l, int r)
{
	if(l>r) return 0;
	return (r-l+1)%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int d; cin>>d>>MOD;
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<30;i++)
		{
			int val = getrange((1<<i),min(d,(1<<(i+1))-1));
			dp[i]=val;
			for(int j=0;j<i;j++)
			{
				dp[i]=add(dp[i],mult(dp[j],val));
			}
			ans=add(ans,dp[i]);
		}
		cout<<ans<<'\n';
	}
}