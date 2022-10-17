/*************************************************************************
    > File Name: 869_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 06 Oct 2017 09:42:57 PM CST
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
	long long a, b;
	while(scanf("%lld%lld", &a, &b) != EOF)
	{
		long long ans=1;
		for(long long i=a+1; i<=b; i++)
		{
			ans=(ans*i)%10;
			if(ans == 0) break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}