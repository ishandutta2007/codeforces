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

int MOD[3] = {int(1e9)+7, int(1e9)+9, 998353243};

void add(int &a, int b, int mod)
{
	a+=b;
	while(a>=mod) a-=mod;
}

int mult(int a, int b, int mod)
{
	a%=mod; b%=mod;
	a=(a*1LL*b)%mod;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	int n,m; cin>>n>>m;
	MOD[2]^=rand();
	vector<string> vec(n);
	vector<vi> dp[3];
	vector<vi> dp2[3];
	for(int i=0;i<3;i++) dp[i].resize(n);
	for(int i=0;i<3;i++) dp2[i].resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
		for(int j=0;j<3;j++) dp[j][i].resize(m,0);
		for(int j=0;j<3;j++) dp2[j][i].resize(m,0);
	}
	dp[0][0][0]=dp[1][0][0]=dp[2][0][0]=1;
	dp2[0][n-1][m-1]=dp2[1][n-1][m-1]=dp2[2][n-1][m-1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='#') continue;
			for(int k=0;k<3;k++)
			{
				if(i>0) add(dp[k][i][j],dp[k][i-1][j],MOD[k]);
				if(j>0) add(dp[k][i][j],dp[k][i][j-1],MOD[k]);
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(vec[i][j]=='#') continue;
			for(int k=0;k<3;k++)
			{
				if(i+1<n) add(dp2[k][i][j],dp2[k][i+1][j],MOD[k]);
				if(j+1<m) add(dp2[k][i][j],dp2[k][i][j+1],MOD[k]);
			}
		}
	}
	if(dp[0][n-1][m-1]==0&&dp[1][n-1][m-1]==0&&dp[2][n-1][m-1]==0)
	{
		cout<<0<<'\n'; return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0&&j==0) continue;
			if(i==n-1&&j==m-1) continue;
			if(vec[i][j]=='#') continue;
			int pos=1;
			for(int k=0;k<3;k++)
			{
				if(mult(dp[k][i][j],dp2[k][i][j],MOD[k])!=dp[k][n-1][m-1]) 
				{
					pos=0; break;
				}
			}
			if(pos){cout<<1<<'\n'; return 0;}
		}
	}
	cout<<2<<'\n';
}