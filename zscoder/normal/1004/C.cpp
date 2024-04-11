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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int b[222222];
int a[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; set<int> L;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(L.find(a[i])==L.end())
		{
			b[i]=1;
		}
		L.insert(a[i]);
	}
	ll ans=0;
	set<int> R;
	for(int i=n-1;i>=0;i--)
	{
		if(b[i])
		{
			ans+=R.size();
		}
		R.insert(a[i]);
	}
	cout<<ans<<'\n';
}