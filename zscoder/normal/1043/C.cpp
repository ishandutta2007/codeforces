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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string dp[2][1222];
int par[2][1222];
int res[1222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	dp[0][0]=dp[1][0]=s.substr(0,1);
	memset(par,-1,sizeof(par));
	par[0][0]=par[1][0]=0;
	int n=s.length();
	for(int i=1;i<n;i++)
	{
		{
			dp[0][i] = dp[0][i-1]+s[i];
			par[0][i]=0;
			string s2 = s[i]+dp[1][i-1];
			if(s2<dp[0][i])
			{
				dp[0][i]=s2;
				par[0][i]=1;
			}
		}
		{
			dp[1][i] = s[i]+dp[1][i-1];
			par[1][i]=0;
			string s2 = dp[0][i-1]+s[i];
			if(s2<dp[1][i])
			{
				dp[1][i]=s2;
				par[1][i]=1;
			}
		}
	}
	int cur=0;
	if(dp[1][n-1]<dp[0][n-1])
	{
		cur=1;
	}
	for(int i=n-1;i>=0;i--)
	{
		res[i]=par[cur][i];
		cur^=par[cur][i];
	}
	for(int i=0;i<n;i++)
	{
		/*
		if(res[i]) 
		{
			int l=0; int r=i;
			while(l<r)
			{
				swap(s[l],s[r]); l++; r--;
			}
		}
		*/
		cout<<res[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
	//cerr<<s<<'\n';
}