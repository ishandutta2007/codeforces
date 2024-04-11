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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n,m; ll ta,tb; int k; cin>>n>>m>>ta>>tb>>k;
	vector<ll> a,b;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb(x+ta);
	}
	for(int i=0;i<m;i++)
	{
		ll x; cin>>x; b.pb(x);
	}
	sort(a.begin(),a.end()); sort(b.begin(),b.end());
	ll ans = 0;
	for(int i=0;i<=k;i++)
	{
		//remove i from first, k-i from second
		if(i>n||k-i>m) continue;
		if(i==n)
		{
			ans=ll(2e18);
		}
		else if(k-i==m)
		{
			ans=ll(2e18);
		}
		else
		{
			int earliest=a[i];
			int lb = lower_bound(b.begin(),b.end(),earliest)-b.begin();
			lb+=k-i;
			if(lb>=b.size()) ans=ll(2e18);
			else ans=max(ans,b[lb]+tb);
		}
	}
	if(ans>=ll(2e18)) ans=-1;
	cout<<ans<<'\n';
}