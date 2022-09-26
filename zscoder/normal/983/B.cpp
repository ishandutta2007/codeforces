#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[5011][5011];
int a[50011];
int ans[5011][5011];

int solve(int l, int r)
{
	if(l>r) return 0;
	if(ans[l][r]!=-1) return ans[l][r];
	return (ans[l][r] = max(solve(l+1,r),max(solve(l,r-1), dp[l][r-l])));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); memset(ans,-1,sizeof(ans));
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		dp[i][0] = a[i];
	}
	for(int len=1;len<=n;len++)
	{
		int best=19;
		for(int j=19;j>=0;j--)
		{
			if(len&(1<<j))
			{
				best=j; break;
			}
		}
		for(int i=0;i<n;i++)
		{
			dp[i][len] = dp[i][len-(1<<best)];
			if(i+(1<<best) < n)
			{
				dp[i][len] ^= dp[i+(1<<best)][len-(1<<best)];
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			cerr<<i<<' '<<j<<' '<<dp[i][j-i]<<'\n';
		}
	}
	*/
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r; l--; r--;
		cout<<solve(l,r)<<'\n';
	}
}