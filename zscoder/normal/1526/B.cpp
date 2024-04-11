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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[11111];

vi a={11,111,1111,11111};
void prep()
{
	dp[0]=1;
	for(int i=1;i<=10000;i++)
	{
		for(int j:a)
		{
			if(i-j>=0&&dp[i-j]) dp[i]=1;
		}
	}	
}

void solve()
{
	int x; cin>>x;
	if(x>=5000){cout<<"YES\n";}
	else if(dp[x]){cout<<"YES\n";}
	else cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	prep();
	int t; cin>>t;
	while(t--) solve();
}