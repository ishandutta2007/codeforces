/*************************************************************************
    > File Name: 1036_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 10 Sep 2018 04:47:10 PM CST
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
	long long n, k;
	while(scanf("%lld%lld", &n, &k) != EOF)
	{
		long long ans=k/n;
		if(k-ans*n > 0) ans+=1; 
		printf("%lld\n", ans);
	}
	return 0;
}