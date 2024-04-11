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

void solve()
{
	int n,m; cin>>n>>m;
	vi a(n);
	vi b(m);
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]--;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i]; 		
	}
	sort(a.rbegin(),a.rend());
	ll ans=0;
	for(int i=0;i<n;i++) ans+=b[a[i]];
	ll sum=ans;
	int lo=1; int hi=min(n,m);
	int zz=0;
	while(lo<=hi)
	{
		ll res=0;
		bool pos=1;
		int mid=(lo+hi)>>1;
		for(int i=0;i<mid;i++)
		{
			if(mid-1-i>a[i]){pos=0; break;}
		}
		if(pos)
		{
			for(int i=0;i<mid;i++)
			{
				res+=b[i];
			}
			for(int i=mid;i<n;i++)
			{
				res+=b[a[i]];
			}
			ans=min(ans,res);
		}
		if(pos)
		{
			lo=mid+1;
			zz=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	for(int z=1;z<zz;z++)
	{
		sum-=b[a[z-1]];
		sum+=b[z-1];
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}