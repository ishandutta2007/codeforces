#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#define INF 1000000000
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

bool ok[SIZE][SIZE];
int num[SIZE][SIZE];
int dp[SIZE][SIZE];
char str[SIZE];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int sx,sy,gx,gy;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<m;j++)
		{
			ok[i][j]=str[j]!='T';
			if(str[j]=='S') sx=i,sy=j;
			else if(str[j]=='E') gx=i,gy=j;
			else if(str[j]!='T') num[i][j]=str[j]-'0';
		}
	}
	queue <P> que;
	que.push(P(gx,gy));
	memset(dp,-1,sizeof(dp));
	dp[gx][gy]=0;
	while(!que.empty())
	{
		P p=que.front();que.pop();
		int x=p.first,y=p.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(0<=nx&&nx<n&&0<=ny&&ny<m&&ok[nx][ny]&&dp[nx][ny]==-1)
			{
				dp[nx][ny]=dp[x][y]+1;
				que.push(P(nx,ny));
			}
		}
	}
	assert(dp[sx][sy]>=0);
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dp[i][j]!=-1&&dp[i][j]<=dp[sx][sy])
			{
				ret+=num[i][j];
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}