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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll a[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll s;
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>a[i];
	int lo=0; int hi=n;
	ll mincost = ll(1e18);
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		vector<ll> vec(n);
		for(int i=0;i<n;i++)
		{
			vec[i]=a[i]+ll(i+1)*mid;
		}
		sort(vec.begin(),vec.end());
		ll sum=0;
		for(int i=0;i<mid;i++) sum+=vec[i];
		if(sum<=s)
		{
			mincost=sum;
			ans=mid;
			lo=mid+1;
		}
		else 
		{
			hi=mid-1;
		}
	}
	cout<<ans<<' '<<mincost<<'\n';
}