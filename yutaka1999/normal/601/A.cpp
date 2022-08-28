#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 405
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

int dp[SIZE][SIZE][2];
bool A[SIZE][SIZE];
int n;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		A[a][b]=A[b][a]=true;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	queue <PP> que;
	que.push(PP(P(0,0),0));
	int ret=-1;
	while(!que.empty())
	{
		PP p=que.front();que.pop();
		int s=p.first.first,t=p.first.second;
		int k=p.second;
		if(s==n-1&&t==n-1&&k==0)
		{
			ret=dp[s][t][k]/2;
			break;
		}
		if(k==0)
		{
			if(s==n-1)
			{
				if(dp[s][t][1]==-1)
				{
					dp[s][t][1]=dp[s][t][k]+1;
					que.push(PP(P(s,t),1));
				}
			}
			for(int i=0;i<n;i++)
			{
				if(s!=i&&A[s][i]&&dp[i][t][1]==-1)
				{
					dp[i][t][1]=dp[s][t][k]+1;
					que.push(PP(P(i,t),1));
				}
			}
		}
		else
		{
			if(t==n-1)
			{
				if(dp[s][t][0]==-1)
				{
					dp[s][t][0]=dp[s][t][k]+1;
					que.push(PP(P(s,t),0));
				}
			}
			for(int i=0;i<n;i++)
			{
				if(t!=i&&!A[t][i]&&dp[s][i][0]==-1)
				{
					dp[s][i][0]=dp[s][t][k]+1;
					que.push(PP(P(s,i),0));
				}
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}