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

ll a[222222];
	
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	vi seg;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		if(i>0) seg.pb(a[i]-a[i-1]-1);
	}
	int ans = a[n-1]-a[0]+1;
	sort(seg.rbegin(),seg.rend());
	for(int i=0;i<k-1;i++) ans-=seg[i];
	cout<<ans<<'\n';
}