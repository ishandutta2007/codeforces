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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n; cin>>n;
	int k1,k2; cin>>k1>>k2;
	int mx1=0;
	for(int i=0;i<k1;i++)
	{
		int x; cin>>x; mx1=max(mx1,x);
	}
	int mx2=0;
	for(int i=0;i<k2;i++)
	{
		int x; cin>>x; mx2=max(mx2,x);
	}
	if(mx1>mx2) cout<<"YES\n";
	else cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}