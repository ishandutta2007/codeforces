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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int LG = 61;

ll a[55];
ll p[55];

ll sum(int l, int r)
{	
	if(l==0) return p[r];
	else return p[r]-p[l-1];	
}

bool dp[55][55];
int n,k; 

bool check(ll mid)
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		if((p[i]&mid)==mid)
		{
			dp[i][1] = 1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int z=1;z<=k;z++)
		{
			for(int j=i;j>0;j--)
			{
				if(dp[j-1][z-1]&&(sum(j, i)&mid)==mid) dp[i][z] = 1;
			}
		}
	}
	return dp[n-1][k];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		p[i]=a[i];
		if(i>0) p[i]+=p[i-1];
	}
	ll ans = 0;
	for(int i=LG-1;i>=0;i--)
	{
		ll checkcur = ans^(1LL<<i);
		if(check(checkcur)) ans^=(1LL<<i);
	}
	cout<<ans<<'\n';
}