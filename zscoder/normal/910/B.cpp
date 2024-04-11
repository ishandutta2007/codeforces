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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[(1<<10)];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int l,a,b; cin>>l>>a>>b;
	vi vec;
	for(int i=0;i<4;i++) vec.pb(a);
	for(int i=0;i<2;i++) vec.pb(b);
	for(int i=0;i<(1<<6)+100;i++) dp[i]=int(1e9);
	dp[0] = 0;
	vi bits;
	for(int i=1;i<(1<<6);i++)
	{
		int sum=0;
		for(int j=0;j<vec.size();j++)
		{
			if(i&(1<<j))
			{
				sum+=vec[j];
			}
		}
		if(sum<=l)
		{
			dp[i] = 1; bits.pb(i);
		}
	}
	for(int i=1;i<(1<<6);i++)
	{
		for(int z=0;z<bits.size();z++)
		{
			int j=bits[z];
			if((i&j)==j)
			{
				dp[i] = min(dp[i], dp[j] + dp[(i^j)]);
			}
		}
	}
	cout<<dp[(1<<6)-1]<<'\n';
}