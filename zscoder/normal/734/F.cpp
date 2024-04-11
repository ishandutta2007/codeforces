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

ll b[222222];
ll c[222222];
ll a[222222];
ll sum[62];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	ll S=0;
	for(int i=0;i<n;i++)
	{
		S+=b[i]+c[i];
	}
	if(S%(2*n)!=0)
	{
		cout<<-1<<'\n'; return 0;
	}
	S/=2*n;
	for(int i=0;i<n;i++)
	{
		a[i]=b[i]+c[i]-S;
		if(a[i]%n!=0)
		{
			cout<<-1<<'\n'; return 0;
		}
		a[i]/=n;
	}
	for(int j=0;j<60;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]&(1LL<<j))
			{
				sum[j]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		ll ans=0;
		for(int j=0;j<60;j++)
		{
			if(a[i]&(1LL<<j))
			{
				ans+=(1LL<<j)*(sum[j]);
			}
		}
		if(ans!=b[i])
		{
			cout<<-1<<'\n'; return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}