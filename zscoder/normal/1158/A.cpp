#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[222222];
ll b[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	ll sum=0;
	ll mx=-1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; sum+=a[i]; mx=max(mx,a[i]);
	}
	sort(a,a+n);
	sum*=ll(m); ll cnt=0;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		if(b[i]<mx){cout<<-1<<'\n'; return 0;}
		if(b[i]>mx)
		{
			cnt++;
			sum+=b[i]-mx;
		}
	}
	if(cnt==m)
	{
		sum+=a[n-1]-a[n-2];
	}
	cout<<sum<<'\n';
}