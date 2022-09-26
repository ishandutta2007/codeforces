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

ll a[222222];
ll ans[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=21;i>=0;i--)
	{
		int cc=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]&(1<<i)) cc++;
		}
		for(int j=0;j<cc;j++) ans[j]|=(1<<i);
	}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		res+=ans[i]*ans[i];
	}
	cout<<res<<'\n';
}