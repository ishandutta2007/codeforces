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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[4444];
int dp[4444][4444]; //at position i, where is the next number j
vi pos[4444];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; vi vec;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; vec.pb(a[i]);
	}
	int ans=1;
	sort(vec.begin(),vec.end()); vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
		pos[a[i]].pb(i);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++) dp[i][j]=n;
	}
	for(int i=n-1;i>=0;i--)
	{
		dp[i][a[i]]=i;
		for(int j=0;j<n;j++)
		{
			if(j!=a[i]) dp[i][j]=dp[i+1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cur=dp[0][i];
			int cnt=0; int f[2] = {i,j};
			while(cur<n)
			{
				cur++; cnt++;
				cur=dp[cur][f[cnt&1]];
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans<<'\n';
}