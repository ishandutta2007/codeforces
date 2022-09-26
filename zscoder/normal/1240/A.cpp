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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int cc[555];

void solve()
{
	int n; cin>>n;
	vector<ll> a;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; x/=100; a.pb(x);
	}
	ll x,l,y,r; cin>>x>>l>>y>>r;
	ll k; cin>>k;
	sort(a.rbegin(),a.rend());
	int ans=-1;
	int lo=1; int hi=n;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		memset(cc,0,sizeof(cc));
		for(int i=1;i<=mid;i++)
		{
			int cnt=0;
			if(i%l==0) cnt+=x;
			if(i%r==0) cnt+=y;
			cc[cnt]++;
		}
		ll val=0;
		int ptr=0;
		for(int i=0;i<cc[x+y];i++)
		{
			val+=a[ptr]*ll(x+y);
			ptr++;
		}
		if(x==y)
		{
			for(int i=0;i<cc[x];i++)
			{
				val+=a[ptr]*ll(x);
				ptr++;
			}
		}
		else
		{
			for(int i=0;i<cc[max(x,y)];i++)
			{
				val+=a[ptr]*ll(max(x,y));
				ptr++;
			}
			for(int i=0;i<cc[min(x,y)];i++)
			{
				val+=a[ptr]*ll(min(x,y));
				ptr++;
			}
		}
		if(val>=k)
		{
			ans=mid;
			hi=mid-1;
		}
		else lo=mid+1;
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	while(q--)
	{
		solve();
	}
}