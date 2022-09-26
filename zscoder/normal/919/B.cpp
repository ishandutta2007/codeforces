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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

bool sod(int x)
{
	int c=0;
	while(x)
	{
		c+=x%10;
		if(c>10) return false;
		x/=10;
	}
	return (c==10);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; ll ans = 0;
	for(int i=19;i<int(2e7);i++)
	{
		if(n==0) break;
		if(sod(i))
		{
			ans=i;
			n--;
		}
	}
	cout<<ans<<'\n';
}