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

int dp[2022][(1<<12)+10];
int B[2022][(1<<12)+10];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp)); memset(B,0,sizeof(B));
		int n,m; cin>>n>>m;
		vector<vi> a(m);
		for(int i=0;i<m;i++) a[i].resize(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[j][i];
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				for(int k=0;k<n;k++)
				{
					int sum=0;
					for(int l=0;l<n;l++)
					{
						if(j&(1<<l))
						{
							sum+=a[i][(l+k)%n];
						}
					}
					B[i][j]=max(B[i][j],sum);
				}
			}
		}
		for(int i=0;i<(1<<n);i++)
		{
			dp[0][i]=B[0][i];
		}
		for(int i=1;i<m;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				int k=j;
				for(;;k=((k-1)&j))
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j^k]+B[i][k]);
					if(k==0) break;
				}
			}
		}
		cout<<dp[m-1][(1<<n)-1]<<'\n';
	}
}