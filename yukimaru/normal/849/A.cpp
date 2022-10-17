/*************************************************************************
    > File Name: 849_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 01 Sep 2017 09:48:33 PM CST
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

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a[105]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		bool dp[105][2];
		memset(dp, 0, sizeof(dp));
		dp[0][1]=1;
		for(int i=1; i<=n; i++)
			for(int j=i-1; j>=0; j=j-2)
			{
				if(a[j+1]%2==0 || a[i]%2==0) continue;
				if(dp[j][0]==1 || dp[i][1]==1) dp[i][1]=1;
				if(dp[j][1]==1 || dp[i][0]==1) dp[i][0]=1;
			}
		if(dp[n][0] == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}