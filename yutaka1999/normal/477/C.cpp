#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005

using namespace std;

char str[SIZE];
char P[SIZE];
int nxt[SIZE][30];
int to[SIZE],val[SIZE];
int dp[SIZE][SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	memset(nxt,-1,sizeof(nxt));
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<30;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][str[i]-'a']=i;
	}
	scanf("%s",&P);
	int m=strlen(P);
	for(int i=0;i<n;i++)
	{
		if(str[i]!=P[0])
		{
			val[i]=to[i]=-1;
			continue;
		}
		val[i]=0;
		to[i]=i;
		for(int j=1;j<m;j++)
		{
			int c=P[j]-'a';
			if(nxt[to[i]+1][c]==-1)
			{
				val[i]=to[i]=-1;
				break;
			}
			val[i]+=nxt[to[i]+1][c]-to[i]-1;
			to[i]=nxt[to[i]+1][c];
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(to[i]!=-1&&j+val[i]<=n)
			{
				dp[to[i]+1][j+val[i]]=max(dp[to[i]+1][j+val[i]],dp[i][j]+1);
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",min(dp[n][i],(n-i)/m));
	}
	puts("");
	return 0;
}