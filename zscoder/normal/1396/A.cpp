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

ll a[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<1<<' '<<1<<'\n';
		cout<<-a[0]<<'\n';
		cout<<1<<' '<<1<<'\n';
		cout<<0<<'\n';
		cout<<1<<' '<<1<<'\n';
		cout<<0<<'\n';
	}
	else
	{
		cout<<1<<' '<<n<<'\n';
		for(int i=0;i<n;i++)
		{
			cout<<-a[i]*1LL*n<<' ';
		}
		cout<<'\n';
		cout<<1<<' '<<n-1<<'\n';
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i]*1LL*(n-1)<<' ';
		}
		cout<<'\n';
		cout<<2<<' '<<n<<'\n';
		for(int i=1;i<n;i++)
		{
			if(i==n-1) cout<<a[i]*1LL*(n-1)<<' ';
			else cout<<0<<' ';
		}
		cout<<'\n';
	}
}