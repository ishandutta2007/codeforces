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

ll a[566666];
ll suf[566666];
ll dps[566666];
ll pre[566666];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i>0) pre[i]=pre[i-1];
		pre[i]+=ll((i)/(k+1))*a[i];
		//cerr<<i<<' '<<pre[i]<<'\n';
	}
	ll ans = -ll(9e18);
	suf[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	dps[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		dps[i]=dps[i+1]+suf[i+1];
		//cerr<<i<<' '<<dps[i]<<' '<<suf[i]<<'\n';
	}
	ans=max(dps[0],pre[n-1]);
	for(int i=0;i<n;i++)
	{
		ll mxcnt = i/(k+1);
		ll sum = pre[i]+dps[i+1]+(mxcnt+1)*suf[i+1];
		ans=max(ans,sum);
	}
	cout<<ans<<'\n';
}