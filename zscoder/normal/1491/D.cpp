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

int dp[31][31];

void solve()
{
	ll a[2]; cin>>a[0]>>a[1];
	vector<int> d[2];
	for(int z=0;z<2;z++)
	{
		for(int i=30;i>=0;i--)
		{
			if(a[z]&(1LL<<i)) d[z].pb(i);
		}
	}
	if(d[1].size()>d[0].size())
	{
		cout<<"NO\n"; return ;
	}
	if(a[0]>a[1])
	{
		cout<<"NO\n"; return ;
	}
	memset(dp,0,sizeof(dp));
	int siz = d[1].size();
	dp[0][0]=1;
	if(d[0][0]<d[1][0])
	{
		for(int i=1;i<d[0].size();i++)
		{
			//check if dp[0][i] is true
			dp[0][i]=1;
		}
	}
	for(int i=0;i+1<d[1].size();i++)
	{
		for(int j=0;j<d[0].size();j++)
		{
			if(!dp[i][j]) continue;
			//check how i+1 is going
			//start from [j+1,
			if(d[1][i+1]<d[0][j+1]) continue;
			if(d[1][i+1]==d[0][j+1])
			{
				dp[i+1][j+1]=1; continue;
			}
			for(int k=j+1;k<d[0].size();k++)
			{
				dp[i+1][k]=1; 
			}
		}
	}
	if(dp[int(d[1].size())-1][int(d[0].size())-1]) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}