/*************************************************************************
    > File Name: 987_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 03 Jun 2018 10:09:39 AM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

int min(int a, int b)
{
	if(a <= b) return a;
	else return b;
}

const int inf=3e8+5;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int s[3005]={0};
		int c[3005]={0};
		int dp[3005][5];
		for(int i=1; i<=n; i++) scanf("%d", &s[i]);
		for(int i=1; i<=n; i++) scanf("%d", &c[i]);
		for(int i=1; i<=n; i++)
		{
			dp[i][1]=c[i];
			dp[i][2]=inf;
			dp[i][3]=inf;
		}
		for(int j=2; j<=3; j++)
			for(int i=1; i<=n; i++)
				for(int k=1; k<i; k++)
					if(s[i] > s[k])
						dp[i][j]=min(dp[i][j], dp[k][j-1]+c[i]);
		int ans=inf;
		for(int i=1; i<=n; i++)
			ans=min(ans, dp[i][3]);
		printf("\n");
		if(ans == inf) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}