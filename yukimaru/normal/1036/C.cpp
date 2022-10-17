/*************************************************************************
    > File Name: 1036_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 10 Sep 2018 05:58:28 PM CST
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

long long a[25];
long long dp[25][10];

long long dfs(long long pos, long long limit, long long cnt)
{
	if(cnt > 3) return 0;
	if(pos == -1) return 1;

	if(!limit && dp[pos][cnt]!=-1)
		return dp[pos][cnt];
	long long tmp=0;
	long long up=limit ? a[pos] : 9;
	for(int i=0; i<=up; i++)
		tmp+=dfs(pos-1, limit && (i==up), cnt+(i>0));
	if(!limit) dp[pos][cnt]=tmp;
	return tmp;
}

long long solve(long long n)
{
	memset(dp, -1, sizeof(dp));
	long long pos=0;
	while(n)
	{
		a[pos++]=n%10;
		n/=10;
	}
	return dfs(pos-1, 1, 0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long l, r;
		scanf("%lld%lld", &l, &r);
		long long ans=solve(r)-solve(l-1);
		printf("%lld\n", ans);
	}
	return 0;
}