#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#define SIZE 1000005

using namespace std;

vector <int> rvec[SIZE];
int dp[SIZE],deg[SIZE];
bool up[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		rvec[b].push_back(a);
		deg[a]++;
	}
	deque <int> que;
	memset(dp,-1,sizeof(dp));
	memset(up,false,sizeof(up));
	int s,t;
	scanf("%d %d",&s,&t);s--;t--;
	dp[t]=0;
	que.push_back(t);
	while(!que.empty())
	{
		int v=que.front();que.pop_front();
		if(up[v]) continue;
		up[v]=true;
		for(int i=0;i<rvec[v].size();i++)
		{
			int to=rvec[v][i];
			deg[to]--;
			if(deg[to]!=0)
			{
				if(dp[to]==-1) dp[to]=dp[v]+1;
				else
				{
					if(dp[to]<=dp[v]+1) continue;
					dp[to]=dp[v]+1;
				}
				que.push_back(to);
			}
			else
			{
				if(dp[to]==-1||dp[to]>dp[v])
				{
					dp[to]=dp[v];
					que.push_front(to);
				}
			}
		}
	}
	printf("%d\n",dp[s]);
	return 0;
}