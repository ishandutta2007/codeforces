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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int C = 300;
int dp[2][C+1];
int a[300011];
const int INF = int(1e9);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	//n=240000;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		//if(i<100000) a[i]=2000;
		//else a[i]=1000;
		a[i]/=100;
	}
	for(int i=0;i<=C;i++) dp[0][i]=dp[1][i]=INF;
	dp[0][a[0]/10] = a[0];
	for(int i=1;i<n;i++)
	{
		int cur=(i&1); int pre=(cur^1);
		for(int j=0;j<=C;j++) dp[cur][j]=INF;
		for(int j=0;j<=C;j++)
		{
			if(dp[pre][j]<INF)
			{
				int mn = min(a[i], j);
				dp[cur][j-mn] = min(dp[cur][j-mn], dp[pre][j] + a[i] - mn);
				if(j+(a[i]/10)<=C) dp[cur][j+(a[i]/10)]=min(dp[cur][j+(a[i]/10)],dp[pre][j]+a[i]);
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=C;i++)
	{
		ans=min(ans,dp[(n+1)&1][i]);
	}
	ll res = ans*100;
	cout<<res<<'\n';
}