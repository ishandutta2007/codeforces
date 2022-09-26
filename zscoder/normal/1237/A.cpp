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
typedef unsigned long long ull;
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi vec;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		vec.pb(x);
	}
	vi ans;
	int add=0;
	for(int i=0;i<n;i++)
	{
		int x=vec[i];
		if(x%2==0)
		{
			ans.pb(x/2); continue;
		}
		else
		{
			if(x>=0)
			{
				x/=2;
			}
			else
			{
				int tmp=abs(x)/2;
				x=-tmp-1;
			}
			if(!add)
			{
				x++;
			}
			add^=1;
			ans.pb(x);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<'\n';
	}
}