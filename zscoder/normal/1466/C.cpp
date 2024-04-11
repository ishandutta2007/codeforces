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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[2][27][27];

void amin(int &a, int b)
{
	if(a==-1) a=b;
	else a=min(a,b);
}

void solve()
{	
	string s; cin>>s;
	int n=s.length();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<27;j++)
		{
			for(int k=0;k<27;k++)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	dp[0][26][s[0]-'a']=0;
	int ct=0;
	for(int i=0;i<26;i++)
	{
		if(s[0]=='a'+i) continue;
		dp[0][26][i]=1; ct++;
		if(ct>=3) break;
	}
	for(int i=0;i+1<n;i++)
	{
		int cur=(i+1)&1; int pre=(i&1);
		for(int j=0;j<27;j++)
		{
			for(int k=0;k<27;k++)
			{
				dp[cur][j][k]=-1;
			}
		}
		for(int j=0;j<=26;j++)
		{
			for(int k=0;k<=26;k++)
			{
				if(dp[pre][j][k]==-1) continue;
				int v=dp[pre][j][k];
				if(s[i+1]-'a'!=j && s[i+1]-'a'!=k) amin(dp[cur][k][s[i+1]-'a'],v);
				//arbitrary
				int ct=0;
				for(int z=0;z<26;z++)
				{
					if(s[i+1]-'a'==z) continue;
					if(z==j||z==k) continue;
					ct++;
					amin(dp[cur][k][z],v+1);
					if(ct>=3) break;
				}
			}
		}
	}
	int ans=int(1e9);
	for(int j=0;j<=26;j++)
	{
		for(int k=0;k<=26;k++)
		{
			if(dp[(n+1)&1][j][k]!=-1) amin(ans,dp[(n+1)&1][j][k]);
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	while(n--) solve();
}