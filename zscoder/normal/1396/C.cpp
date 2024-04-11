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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[1111111];
ll dp[1111111];
ll sc[1111111][2];

void amin(ll &a, ll b)
{
	a=min(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll r[3]; ll d;
	cin>>n;
	for(int i=0;i<3;i++) cin>>r[i];
	cin>>d;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sc[i][0]=a[i]*1LL*r[0]+r[2]; //kill everyone one by one
		sc[i][1]=min(a[i]*1LL*r[0]+2LL*r[0],r[1]+r[0]); //bruh just kill 
	}
	dp[0]=0;
	for(int i=1;i<=n+1;i++) dp[i]=ll(5e18);
	for(int i=0;i<n;i++)
	{
		//push up
		ll v=dp[i];
		//a 1
		amin(dp[i+1],v+sc[i+1][0]+d);
		//two 2s
		amin(dp[i+2],v+sc[i+1][1]+sc[i+2][1]+4LL*d);
		//single 2
		amin(dp[i+1],v+sc[i+1][1]+3LL*d); //solo last 2
		//2-1
		if(i+2<n) amin(dp[i+2],v+sc[i+1][1]+sc[i+2][0]+4LL*d);
		else amin(dp[i+2],v+sc[i+1][1]+sc[i+2][0]+3LL*d); //2 -> 1 -> 2 gaodim
		//cerr<<i<<' '<<dp[i]<<'\n';
	}
	cout<<dp[n]-d<<'\n';
}