#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 5005
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
ll dp[SIZE][SIZE][2];
ll nxt[SIZE][2];
int nd[SIZE];
int C[SIZE],D[SIZE];

void dfs(int v=0)
{
	nd[v]=1;
	dp[v][0][0]=0;//0:not use,1:use
	dp[v][0][1]=D[v];
	dp[v][1][0]=C[v];
	dp[v][1][1]=D[v];
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs(to);
		for(int j=0;j<=nd[v]+nd[to];j++) nxt[j][0]=nxt[j][1]=INF;
		for(int j=0;j<=nd[v];j++)
		{
			for(int k=0;k<=nd[to];k++)
			{
				nxt[j+k][0]=min(nxt[j+k][0],dp[v][j][0]+dp[to][k][0]);
				nxt[j+k][1]=min(nxt[j+k][1],dp[v][j][1]+min(dp[to][k][0],dp[to][k][1]));
			}
		}
		for(int j=0;j<=nd[v]+nd[to];j++)
		{
			dp[v][j][0]=nxt[j][0];
			dp[v][j][1]=nxt[j][1];
		}
		nd[v]+=nd[to];
	}
	//printf("%d\n",nd[v]);
	//for(int j=0;j<=nd[v];j++) printf("[%lld %lld] ",dp[v][j][0],dp[v][j][1]);puts("");
}
int main()
{
	int n,b;
	scanf("%d %d",&n,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&C[i],&D[i]);
		D[i]=C[i]-D[i];
		if(i>0)
		{
			int p;
			scanf("%d",&p);p--;
			vec[p].push_back(i);
		}
	}
	dfs();
	for(int i=n;i>=0;i--)
	{
		if(dp[0][i][0]<=b||dp[0][i][1]<=b)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}