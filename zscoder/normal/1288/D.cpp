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

vi a[302222];
int dp[266];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		vi v;
		for(int j=0;j<m;j++)
		{
			int x; cin>>x; v.pb(x);
		}
		a[i]=v;
	}
	int lo=0; int hi=int(1e9)+10;
	int ans=0;
	ii res={0,0};
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		for(int i=0;i<(1<<m);i++) dp[i]=-1;
		for(int i=0;i<n;i++)
		{
			int bit=0;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]>=mid) bit|=(1<<j);
			}
			dp[bit]=i;
		}
		for(int i=(1<<m)-1;i>=0;i--)
		{
			if(dp[i]>=0)
			{
				for(int j=0;j<m;j++)
				{
					if(i&(1<<j)) dp[i^(1<<j)]=dp[i];
				}
				
			}
		}
		bool pos=0;
		for(int i=0;i<(1<<m);i++)
		{
			int v=dp[i];
			int w=dp[((1<<m)-1)^i];
			if(v>=0&&w>=0)
			{
				if(mid>=ans)
				{
					ans=mid; res={v,w}; pos=1; break;
				}
			}
		}
		if(pos)
		{
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	cerr<<ans<<'\n';
	cout<<res.fi+1<<' '<<res.se+1<<'\n';
}