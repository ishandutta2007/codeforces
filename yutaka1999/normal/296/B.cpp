#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char s[SIZE],w[SIZE];
ll dp[SIZE][5];
ll sum[5];

ll kake(ll x,ll y)
{
	return (x*y)%MOD;
}
ll plus(ll x,ll y)
{
	if(x+y>=MOD) return x+y-MOD;
	return x+y;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&s);
	scanf("%s",&w);
	for(int i=0;i<n;i++)
	{
		memset(sum,0,sizeof(sum));
		if(i==0)
		{
			for(int j=0;j<10;j++)
			{
				if(s[i]!='?'&&s[i]-'0'!=j) continue;
				for(int k=0;k<10;k++)
				{
					if(w[i]!='?'&&w[i]-'0'!=k) continue;
					if(j==k) sum[0]++;
					else if(j<k) sum[1]++;
					else sum[2]++;
				}
			}
			for(int j=0;j<4;j++) dp[i][j]=sum[j];
		}
		else
		{
			for(int j=0;j<10;j++)
			{
				if(s[i]!='?'&&s[i]-'0'!=j) continue;
				for(int k=0;k<10;k++)
				{
					if(w[i]!='?'&&w[i]-'0'!=k) continue;
					if(j==k) sum[0]++;
					else if(j<k) sum[1]++;
					else sum[2]++;
				}
			}
			dp[i][0]=kake(sum[0],dp[i-1][0]);
			dp[i][1]=plus(kake(sum[0],dp[i-1][1]),kake(sum[1],plus(dp[i-1][0],dp[i-1][1])));
			dp[i][2]=plus(kake(sum[0],dp[i-1][2]),kake(sum[2],plus(dp[i-1][0],dp[i-1][2])));
			dp[i][3]=plus(plus(kake(sum[0],dp[i-1][3]),kake(sum[1],plus(dp[i-1][2],dp[i-1][3]))),plus(kake(sum[2],plus(dp[i-1][1],dp[i-1][3])),kake(sum[3],plus(plus(dp[i-1][0],dp[i-1][1]),plus(dp[i-1][2],dp[i-1][3])))));
		}
	}
	printf("%I64d\n",dp[n-1][3]);
	return 0;
}