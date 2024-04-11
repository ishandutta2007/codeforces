#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

int n;
int a[maxn];

int dp[maxn][maxn][3];

int ans[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}

int min12(int i,int j)
{
	return min(dp[i][j][1],dp[i][j][2]);
}

int min012(int i,int j)
{
	return min(dp[i][j][0],min12(i,j));
}

void solve()
{
	memset(ans,0x3f,sizeof(ans));
	memset(dp,0x3f,sizeof(dp));
	
	dp[2][1][0]=dp[2][0][0]=max(a[2]-(a[1]-1),0);
	dp[2][1][1]=dp[2][0][1]=max(a[1]-(a[2]-1),0);
	if (a[1]>a[2])
		dp[2][1][2]=0;
	if (a[1]>=a[2])
		dp[2][0][2]=0;
		
	for (int i=3;i<=n;++i)
	{
		int m=(i+1)/2;
		dp[i][0][0]=max(a[i]-(a[i-1]-1),0);
		dp[i][0][1]=max(a[i-1]-(a[i]-1),0);
		if (a[i-1]>=a[i])
			dp[i][0][2]=0;
			
		for (int j=1;j<=m;++j)
		{
			int hl=a[i]-1;
			int h0=min(a[i-1],a[i-2]-1),hp=a[i-1];
			dp[i][j][0]=dp[i-1][j][1]+max(a[i]-(hp-1),0);
			
//			cout<<i<<" "<<j<<" "<<0<<" "<<a[i]<<" "<<hp<<" "<<max(a[i]-(hp-1),0)<<endl;
			
			dp[i][j][1]=min(dp[i-1][j-1][0]+max(h0-hl,0),dp[i-1][j-1][2]+max(hp-hl,0));
			if (a[i]>hp)
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
			
			if (h0>=a[i])
				dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][0]);
			if (hp>a[i])
				dp[i][j][2]=min(dp[i][j][2],min12(i-1,j));
			if (hp==a[i])
				dp[i][j][2]=min(dp[i][j][2],min(dp[i-1][j][2],dp[i-1][j+1][1]));
			
//			ans[j]=min(ans[j],min012(i,j));
		}
	}
	
	/*for (int i=2;i<=n;++i)
	{
		int m=(i+1)/2;
		for (int j=0;j<=m;++j)
			for (int k=0;k<3;++k)
				printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]); 
		cout<<endl;
	}*/
	
	int m=(n+1)/2; 
	for (int i=1;i<=m;++i)
//		printf("%d ",ans[i]);
		printf("%d ",min012(n,i));
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	init();
	if (n==1)
		printf("0\n");
	else 
		solve();
	return 0;
}