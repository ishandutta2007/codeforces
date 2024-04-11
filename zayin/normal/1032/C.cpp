#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int pre[maxn][5];
bool dp[maxn][5];

int n,m=5;
int a[maxn];

void print(int n,int i)
{
	if (!n)	return ;
	print(n-1,pre[n][i]);
	printf("%d ",i);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	memset(dp[1],1,sizeof(dp[1]));
	for (int i=2;i<=n;++i)
	{
		if (a[i]==a[i-1])
		{
			for (int k=1;k<=m;++k)
				for (int j=1;j<=m;++j)
					if (k!=j&&dp[i-1][j])
						dp[i][k]=1,pre[i][k]=j;
		} else
		if (a[i]<a[i-1])
		{
			for (int k=1;k<=m;++k)
				for (int j=k+1;j<=m;++j)
					if (dp[i-1][j])
						dp[i][k]=1,pre[i][k]=j;
		} else
		if (a[i]>a[i-1])
		{
			for (int k=1;k<=m;++k)
				for (int j=1;j<k;++j)
					if (dp[i-1][j])
						dp[i][k]=1,pre[i][k]=j;
		}
	}

	for (int i=1;i<=m;++i)
		if (dp[n][i])
		{
			print(n,i);
			return 0;
		}
	puts("-1");
	return 0;
}