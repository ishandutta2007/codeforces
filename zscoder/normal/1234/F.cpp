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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ex[(1<<20)+11];
int dp[(1<<20)+11];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int bit=0;
		ex[bit]=1;
		for(int j=i;j<s.length();j++)
		{
			if(bit&(1<<(s[j]-'a'))) break;
			bit|=(1<<(s[j]-'a'));
			ex[bit]=1;
		}
	}
	for(int i=0;i<(1<<20);i++)
	{
		if(ex[i]) dp[i]=__builtin_popcount(i);
	}
	for(int i = 0;i <20; ++i) 
	{
		for(int mask = 0; mask < (1<<20); ++mask)
		{
			if(mask & (1<<i))
			{
				dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<20);i++)
	{
		if(ex[i])
		{
			ans=max(ans,__builtin_popcount(i)+dp[((1<<20)-1)^i]);
		}
	}	
	cout<<ans<<'\n';
}