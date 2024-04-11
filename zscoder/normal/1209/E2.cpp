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

int dp[22][(1<<12)+10];
int B[22][(1<<12)+10];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
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
		vector<ii> MX(m);
		for(int i=0;i<m;i++)
		{
			MX[i].fi=0;
			for(int j=0;j<n;j++)
			{
				MX[i].fi=max(MX[i].fi,a[i][j]);
			}
			MX[i].se=i;
		}
		sort(MX.rbegin(),MX.rend());
		vector<vi> b(min(n,m));
		for(int i=0;i<min(n,m);i++) b[i].resize(n);
		memset(dp,-1,sizeof(dp)); memset(B,0,sizeof(B));
		for(int i=0;i<min(n,m);i++)
		{
			int id=MX[i].se;
			for(int j=0;j<n;j++)
			{
				b[i][j]=a[id][j];
			}
		}
		m=min(n,m); a=b;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				int sum=0;
				for(int k=0;k<n;k++)
				{
					if(j&(1<<k))
					{
						sum+=a[i][k];
					}
				}
				int curbit=j;
				for(int l=0;l<n;l++)
				{
					B[i][curbit]=max(B[i][curbit],sum);
					int p=0;
					if(curbit&(1<<(n-1)))
					{
						p=1; curbit^=(1<<(n-1));
					}
					curbit<<=1;
					if(p) curbit^=1;
				}
			}
		}
		for(int j=0;j<(1<<n);j++)
		{
			vector<ii> vec;
			for(int k=0;k<m;k++)
			{
				vec.pb({B[k][j],k});
			}
			sort(vec.rbegin(),vec.rend());
			for(int k=n;k<m;k++)
			{
				B[vec[k].se][j]=0;
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
				dp[i][j]=dp[i-1][j];
			}
			for(int j=0;j<(1<<n);j++)
			{
				if(B[i][j]>0)
				{
					int super=((1<<n)-1)^j;
					int k=super;
					for(;;k=((k-1)&super))
					{
						dp[i][j^k]=max(dp[i][j^k],dp[i-1][k]+B[i][j]);
						if(k==0) break;
					}
				}
			}
		}
		cout<<dp[m-1][(1<<n)-1]<<'\n';
	}
}