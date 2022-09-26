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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll pre[111111];
ll a[111111];
ll suf[111111];
ll bestpre[111111];
ll bestsuf[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	ll cur=a[0]; pre[0]=0;
	bestpre[0]=cur;
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1];
		if(a[i]<=cur)
		{
			pre[i]+=(cur+1-a[i]);
			cur++;
		}
		else
		{
			cur=a[i];
		}
		bestpre[i]=cur;
	}
	cur = a[n-1];
	suf[n-1]=0;
	bestsuf[n-1]=cur;
	for(int i=n-2;i>=0;i--)
	{
		suf[i]=suf[i+1];
		if(a[i]<=cur)
		{
			suf[i]+=(cur+1-a[i]);
			cur++;
		}
		else
		{
			cur=a[i];
		}
		bestsuf[i]=cur;
	}
	ll ans=ll(1e18);
	for(int i=0;i<n;i++)
	{
		ll mx=max(bestpre[i],bestsuf[i])-a[i];
		ll res=pre[i]-(bestpre[i]-a[i])+suf[i]-(bestsuf[i]-a[i]);
		ans=min(ans,res+mx);
	}
	cout<<ans<<'\n';
}