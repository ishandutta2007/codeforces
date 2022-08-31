#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char A[SIZE],B[SIZE];
int dp[2][SIZE][2];
int m,d;

int solve(char C[SIZE])
{
	int n=strlen(C);
	int pos=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	dp[pos][0][0]=1;
	for(int i=0;i<n;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		int v=C[i]-'0';
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(i%2==1&&k!=d) continue;
				else if(i%2!=1&&k==d) continue;
				int nxt=(10*j+k)%m;
				dp[pos][nxt][1]+=dp[pos^1][j][1];
				if(dp[pos][nxt][1]>=MOD) dp[pos][nxt][1]-=MOD;
				if(v>k)
				{
					dp[pos][nxt][1]+=dp[pos^1][j][0];
					if(dp[pos][nxt][1]>=MOD) dp[pos][nxt][1]-=MOD;
				}
				else if(v==k) 
				{
					dp[pos][nxt][0]+=dp[pos^1][j][0];
					if(dp[pos][nxt][0]>=MOD) dp[pos][nxt][0]-=MOD;
				}
			}
		}
	}
	return (dp[pos][0][0]+dp[pos][0][1])%MOD;
}
int main()
{
	scanf("%d %d",&m,&d);
	scanf("%s",&A);
	scanf("%s",&B);
	//printf("%d %d\n",solve(A),solve(B));
	int ret=solve(B)-solve(A);
	if(ret<0) ret+=MOD;
	//Agood
	bool up=true;
	int n=strlen(A),sum=0;
	for(int i=0;i<n;i++)
	{
		sum*=10;
		sum+=A[i]-'0';
		sum%=m;
		if(i%2==1&&A[i]-'0'!=d)
		{
			up=false;
			break;
		}
		else if(i%2!=1&&A[i]-'0'==d)
		{
			up=false;
			break;
		}
	}
	if(up&&sum==0)
	{
		ret++;
		if(ret==MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}