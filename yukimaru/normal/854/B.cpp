/*************************************************************************
    > File Name: 854_B_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 07 Sep 2017 01:07:09 AM CST
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
		if(k==0 || k==n)
			printf("0 0\n");
		else
		{
			if(k+2*k <= n) printf("1 %lld\n", 2*k);
			else printf("1 %lld\n", n-k);
		}
	}
	return 0;
}