#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 405

using namespace std;

int mp[SIZE][SIZE];
int dp[2][SIZE][SIZE];
int cnt1[SIZE*SIZE],cnt2[SIZE*SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
			mp[i][j]--;
		}
	}
	int pos=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dp[pos][i][j]=m;
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		pos^=1;
		for(int j=0;j<=n-i;j++)
		{
			int s=j,t=j+i-1;
			int now=0;
			for(int k=0;k<m;k++)
			{
				if(now<k) now=k;
				while(now<m)
				{
					if(dp[pos^1][s][k]<now) break;
					if(i>1&&dp[pos^1][s+1][k]<now) break;
					if(cnt1[mp[t][now]]>0) break;
					if(cnt2[mp[s][now]]>0) break;
					if(i>1&&mp[s][now]==mp[t][now]) break;
					cnt1[mp[s][now]]++;
					cnt2[mp[t][now]]++;
					now++;
				}
				dp[pos][s][k]=now-1;
				mx=max(mx,(now-k)*i);
				if(now>k)
				{
					cnt1[mp[s][k]]--;
					cnt2[mp[t][k]]--;
				}
				//printf("%d [%d %d] %d\n",i,s,k,now-1);
			}
		}
	}
	printf("%d\n",mx);
	return 0;
}