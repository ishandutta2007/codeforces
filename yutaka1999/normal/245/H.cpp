#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

char in[5005];
int num[5005][5005];
int dp[5005][5005];

int memo(int l,int r)
{
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	return dp[l][r]=num[l][r]+memo(l+1,r);
}
int main()
{
	scanf("%s",&in);
	int s=strlen(in);
	for(int i=0;i<s;i++)
	{
		int l=i,r=i;
		while(l>=0&&r<s&&in[l]==in[r])
		{
			num[l][r]++;
			l--;r++;
		}
		l=i,r=i+1;
		while(l>=0&&r<s&&in[l]==in[r])
		{
			num[l][r]++;
			l--;r++;
		}
	}
	for(int i=0;i<s;i++)
	{
		for(int j=1;j<s;j++)
		{
			num[i][j]+=num[i][j-1];
		}
	}
	memset(dp,-1,sizeof(dp));
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--;r--;
		printf("%d\n",memo(l,r));
	}
	return 0;
}