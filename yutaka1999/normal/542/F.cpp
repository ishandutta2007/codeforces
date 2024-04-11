#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#define SIZE 1005
#define MX 105

using namespace std;

vector <int> vec[MX];
int dp[MX][SIZE];
int cnt[SIZE];

int main()
{
	int n,T;
	scanf("%d %d",&n,&T);
	for(int i=0;i<n;i++)
	{
		int t,q;
		scanf("%d %d",&t,&q);
		if(t<=T) vec[T-t].push_back(q);
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	int ret=0;
	for(int i=0;i+1<MX;i++)
	{
		sort(vec[i].begin(),vec[i].end(),greater <int>());
		cnt[0]=0;
		for(int j=0;j<vec[i].size();j++) cnt[j+1]=cnt[j]+vec[i][j];
		int sz=vec[i].size();
		for(int j=0;j<=n;j++)
		{
			if(dp[i][j]==-1) continue;
			ret=max(ret,dp[i][j]);
			for(int k=0;k<=min(j,sz);k++)
			{
				int nxt=min(n,2*(j-k));
				dp[i+1][nxt]=max(dp[i+1][nxt],dp[i][j]+cnt[k]);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}