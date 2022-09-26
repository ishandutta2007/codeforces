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
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<int,int> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll ans = 0;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y; ma[x]=y;
	}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y; ma[x]=max(ma[x],y);
	}
	for(auto x:ma)
	{
		ans+=x.se;
	}
	cout<<ans<<'\n';
}