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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	if(n==1)
	{
		cout<<1<<'\n'; return 0;
	}
	ll gd=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			gd=__gcd(gd,i);
			gd=__gcd(gd,n/i);
		}
	}
	cout<<gd<<'\n';
}