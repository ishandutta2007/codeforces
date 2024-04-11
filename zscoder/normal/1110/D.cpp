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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111111];
int dp[1111111][3][3];

void amax(int &x, int y)
{
	x=max(x,y);
}

int main()
{
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		a[x]++;
	}
	if(m==1)
	{
		cout<<a[1]/3<<'\n'; return 0;
	}
	if(m==2)
	{
		cout<<(a[1]/3) + (a[2]/3)<<'\n'; return 0;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<m-2;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				int v=dp[i][j][k];
				if(v<0) continue;
				for(int l=0;l<3;l++)
				{
					int c1 = a[i+1]-j-k-l;
					int c2 = a[i+2]-k-l;
					int c3 = a[i+3]-l;
					if(c1<0||c2<0||c3<0) continue;
					amax(dp[i+1][k][l], v+c1/3+l);
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<3;k++)
		{
			int c2 = a[m-1]-j-k;
			int c3 = a[m]-k;
			if(c2<0||c3<0||dp[m-2][j][k]<0) continue;
			ans=max(ans,dp[m-2][j][k]+c2/3+c3/3);
		}
	}
	printf("%d\n",ans);
}