#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 205

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;

bool dp[SIZE][SIZE][SIZE];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='B') a++;
		else if(str[i]=='R') b++;
		else c++;
	}
	dp[a][b][c]=true;
	queue <PP> que;
	que.push(PP(a,P(b,c)));
	while(!que.empty())
	{
		PP p=que.front();que.pop();
		a=p.first,b=p.second.first,c=p.second.second;
		if(a>=2&&!dp[a-1][b][c])
		{
			dp[a-1][b][c]=true;
			que.push(PP(a-1,P(b,c)));
		}
		if(b>=2&&!dp[a][b-1][c])
		{
			dp[a][b-1][c]=true;
			que.push(PP(a,P(b-1,c)));
		}
		if(c>=2&&!dp[a][b][c-1])
		{
			dp[a][b][c-1]=true;
			que.push(PP(a,P(b,c-1)));
		}
		if(a>=1&&b>=1&&!dp[a-1][b-1][c+1])
		{
			dp[a-1][b-1][c+1]=true;
			que.push(PP(a-1,P(b-1,c+1)));
		}
		if(b>=1&&c>=1&&!dp[a+1][b-1][c-1])
		{
			dp[a+1][b-1][c-1]=true;
			que.push(PP(a+1,P(b-1,c-1)));
		}
		if(c>=1&&a>=1&&!dp[a-1][b+1][c-1])
		{
			dp[a-1][b+1][c-1]=true;
			que.push(PP(a-1,P(b+1,c-1)));
		}
	}
	if(dp[1][0][0]) printf("B");
	if(dp[0][0][1]) printf("G");
	if(dp[0][1][0]) printf("R");
	puts("");
	return 0;
}