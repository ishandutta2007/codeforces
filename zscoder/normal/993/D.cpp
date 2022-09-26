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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[55];
ll b[55];
const ld eps = 1e-7;
ld dp[55][55][55];

void amin(ld &a, ld b)
{
	if(b<a) a=b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ll lo = 0; ll hi = ll(1000)*ll(1e8)+100;
	ll ans = 0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		ld v = mid*ld(0.001);
		vector<pair<ll,ld> > vec;
		for(int i=0;i<n;i++)
		{
			vec.pb(mp(a[i], ld(a[i]) - ld(b[i])*v));
		}
		//min sum
		sort(vec.rbegin(),vec.rend());
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					dp[i][j][k]=ld(1e18);
				}
			}
		}
		dp[0][1][(vec.size()>1&&vec[0].fi==vec[1].fi)?1:0] = vec[0].se;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(dp[i][j][k]<ld(1e17))
					{
						ld v = dp[i][j][k];
						//use it
						int newk = k+1;
						if(i+2<n&&vec[i+1].fi!=vec[i+2].fi)
						{
							newk = 0;
						}
						amin(dp[i+1][j+1][newk], v + vec[i+1].se);
						//don't use it
						int rem = j - k;
						if(rem>0)
						{
							int newk = k;
							if(i+2<n&&vec[i+1].fi!=vec[i+2].fi)
							{
								newk = 0;
							}
							amin(dp[i+1][j-1][newk], v);
						}
					}
				}
			}
		}
		ld mn = ld(1e9);
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				amin(mn, dp[n-1][j][k]);
			}
		}
		if(mn<=ld(1e-11))
		{
			ans = mid;
			hi = mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
}