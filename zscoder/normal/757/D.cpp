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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int n; string s;
const int MOD = 1e9 + 7;
int dp[80][(1<<20)];

int binary(int l, int r)
{
	int ans = 0;
	for(int i = l; i <= r; i++)
	{
		ans<<=1;
		ans+=int(s[i]-'0');
		if(ans>1000) ans=1000;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	cin>>s;
	//cerr<<s.length()<<'\n';
	for(int i = 0; i <= n - 1; i++) dp[i][0] = 1;
	ll ans = 0;
	for(int i = 0; i <= n - 1; i++) //iterate over last cuts
	{
		for(int j = 0; j < (1<<20); j++)
		{
			if(dp[i][j]==0) continue;
			for(int k = 1; i+k-1<n; k++) //next subseg = [i, i + k - 1]
			{
				int val = binary(i, i+k-1);
				if(val>20) continue;
				if(val==0) continue;
				val--;
				//cerr<<i<<' '<<k<<' '<<val<<' '<<(j|(1<<val))<<'\n';
				dp[i+k][(j|(1<<val))] += dp[i][j];
				while(dp[i+k][(j|(1<<val))]>=MOD) dp[i+k][(j|(1<<val))]-=MOD;
				//assert(dp[i+k][(j|(1<<val))]<MOD);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 20; j++)
		{
			ans+=dp[i][(1<<j)-1];
			//if(dp[i][(1<<j)-1]!=0) cerr<<i<<' '<<j<<' '<<dp[i][(1<<j)-1]<<'\n';
			while(ans>=MOD) ans-=MOD;
		}
	}
	cout<<ans;
}