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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii mn[111111];
ii suf[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi a;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; a.pb(x);
	}
	for(int z=0;z<2;z++)
	{
		mn[0]={a[0],0};
		for(int i=1;i<n;i++)
		{
			mn[i]=min(mp(a[i],i),mn[i-1]);
		}
		suf[n-1]={a[n-1],n-1};
		for(int i=n-2;i>=0;i--)
		{
			suf[i]=min(mp(a[i],i),suf[i+1]);
		}
		for(int i=1;i+1<n;i++)
		{
			if(mn[i-1].fi<a[i]&&suf[i+1].fi<a[i])
			{
				cout<<3<<'\n';
				cout<<mn[i-1].se+1<<' '<<i+1<<' '<<suf[i+1].se+1<<'\n'; return 0;
			}
		}
		for(int i=0;i<n;i++) a[i]*=-1;
	}
	cout<<0<<'\n';	
}