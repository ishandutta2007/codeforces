/*************************************************************************
    > File Name: 851_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 06 Sep 2017 06:39:54 PM CST
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
	long long n, k, t;
	while(scanf("%lld%lld%lld", &n, &k, &t) != EOF)
	{
		long long ans=0;
		if(t>=1 && t<=k) ans=t;
		else if(t>=k+1 && t<=n) ans=k;
		else if(t>=n+1 && t<=n+k) ans=k-t+n;
		printf("%lld\n", ans);
	}
	return 0;
}