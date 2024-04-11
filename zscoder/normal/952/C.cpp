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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vi vec; 
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; vec.pb(x);
	}
	while(vec.size()>1)
	{
		for(int i=0;i+1<vec.size();i++)
		{
			if(abs(vec[i]-vec[i+1])>=2){cout<<"NO\n"; return 0;}
		}
		int mx=-1; int best=0;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]>mx)
			{
				mx=vec[i]; best=i;
			}
		}
		vi nw;
		for(int i=0;i<vec.size();i++)
		{
			if(i!=best) nw.pb(vec[i]);
		}
		vec = nw;
	}
	cout<<"YES\n";
}