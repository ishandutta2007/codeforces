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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111111];
int solve(int l, int r)
{
	if(l==r) return 1;
	int mid=l-1+(r-l+1)/2;
	bool pos=1;
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]<a[i-1]) {pos=0; break;}
	}
	if(pos) return r-l+1;
	return max(solve(l,mid),solve(mid+1,r));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<solve(0,n-1)<<'\n';
}