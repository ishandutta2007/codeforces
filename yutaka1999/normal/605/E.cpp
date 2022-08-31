#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1005
#define EPS (1e-10)

using namespace std;
typedef pair <double,int> P;

int pb[SIZE][SIZE];
double dp[SIZE],now[SIZE];
int n;

void solve()
{
	priority_queue <P,vector <P>,greater <P> > que;
	for(int i=0;i<n;i++)
	{
		dp[i]=-1.0;
		now[i]=1.0;
	}
	dp[n-1]=0.0;
	que.push(P(0.0,n-1));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(dp[v]+EPS<p.first) continue;
		//printf("%d %f\n",v,dp[v]);
		for(int i=0;i<n;i++)
		{
			if(i!=v&&pb[i][v]>0&&(dp[i]<-EPS||dp[i]-EPS>dp[v]))
			{
				double nxt=(dp[i]<-EPS?0:(dp[i]*(double) (1.0-now[i])-now[i]))+now[i]*(double) pb[i][v]/100.0*(dp[v]+1.0);
				double nw=now[i]*(double) (100-pb[i][v])/100.0;
				double vl=(nxt+nw)/(1.0-nw);
				if(dp[i]<-EPS||dp[i]-EPS>vl)
				{
					dp[i]=vl;
					now[i]=nw;
					que.push(P(vl,i));
				}
			}
		}
	}
	printf("%.10f\n",dp[0]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&pb[i][j]);
		}
	}
	solve();
	return 0;
}