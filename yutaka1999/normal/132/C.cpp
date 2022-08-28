#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 205
#define MD 102

using namespace std;

bool dp[2][55][SIZE][2];
char str[SIZE];
int n;

int main()
{
	scanf("%s",&str);
	scanf("%d",&n);
	int sz=strlen(str);
	int pos=0;
	memset(dp[pos],false,sizeof(dp[pos]));
	dp[pos][0][MD][0]=true;
	for(int i=0;i<sz;i++)
	{
		pos^=1;
		memset(dp[pos],false,sizeof(dp[pos]));
		for(int j=0;j<=n;j++)
		{
			for(int k=1;k<SIZE-1;k++)
			{
				for(int l=0;l<2;l++)
				{
					if(str[i]=='T')
					{
						dp[pos][j][k][l]|=dp[pos^1][j][k][l^1];
						dp[pos][j+1][k][l]|=dp[pos^1][j][k+(l==0?-1:1)][l];
					}
					else
					{
						dp[pos][j][k][l]|=dp[pos^1][j][k+(l==0?-1:1)][l];
						dp[pos][j+1][k][l]|=dp[pos^1][j][k][l^1];
					}
				}
			}
		}
	}
	int ret=0;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=n;k>=0;k-=2)
			{
				if(dp[pos][k][i][j]) ret=max(ret,abs(MD-i));
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}