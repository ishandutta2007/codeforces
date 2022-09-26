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

int dp[111][222222];
void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int g=a[0];
	int S=0;
	for(int i=0;i<n;i++)
	{
		g=__gcd(g,a[i]);
	}	
	for(int i=0;i<n;i++) 
	{
		a[i]/=g; S+=a[i];
	}
	//if exist split, then ans = 1
	
	dp[0][0]=1;
	dp[0][a[0]]=1;
	for(int i=0;i+1<n;i++)
	{
		for(int j=0;j<=200011;j++)
		{
			if(dp[i][j])
			{
				dp[i+1][j]=1;
				dp[i+1][j+a[i+1]]=1;
			}
		}
	}
		
	if(S%2==1)
	{
		cout<<0<<'\n'; return ;
	}
	if(S%2==0)
	{
		if(!dp[n-1][S/2])
		{
			cout<<0<<'\n'; return ;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]&1)
		{
			cout<<1<<'\n'<<i+1<<'\n'; return ;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}