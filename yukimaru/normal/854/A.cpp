/*************************************************************************
    > File Name: 854_A_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 06 Sep 2017 09:05:14 PM CST
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

int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ans=0;
		for(int i=1; i<n-i; i++)
			if(gcd(i, n-i) == 1) ans=max(ans, i);
		printf("%d %d\n", ans, n-ans);
	}
	return 0;
}