#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 8005
#define MD 4005
#define INF 1000000005

using namespace std;

char A[SIZE],B[SIZE];
int dp[SIZE][SIZE];
int nxt1[SIZE][30];
int nxt2[SIZE][30];
int bef[30];

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	scanf("%s",&A);
	scanf("%s",&B);
	int la=strlen(A),lb=strlen(B);
	memset(bef,-1,sizeof(bef));
	for(int i=la-1;i>=0;i--)
	{
		bef[A[i]-'a']=i;
		for(int j=0;j<30;j++)
		{
			nxt1[i][j]=bef[j];
		}
	}
	memset(bef,-1,sizeof(bef));
	for(int i=lb-1;i>=0;i--)
	{
		bef[B[i]-'a']=i;
		for(int j=0;j<30;j++)
		{
			nxt2[i][j]=bef[j];
		}
	}
	for(int i=0;i<=la;i++)
	{
		for(int j=0;j<=lb;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<=la;i++)
	{
		for(int j=0;j<=lb;j++)
		{
			if(dp[i][j]==INF) continue;
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b);
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a);
			if(i<la&&j<lb)
			{
				int x=nxt1[i][B[j]-'a'],y=nxt2[j][A[i]-'a'];
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(A[i]==B[j]?0:c));
				if(A[i]!=B[j]&&x!=-1&&y!=-1)
				{
					dp[x+1][y+1]=min(dp[x+1][y+1],dp[i][j]+d+(x-i-1)*b+(y-j-1)*a);
				}
			}
		}
	}
	printf("%d\n",dp[la][lb]);
	return 0;
}