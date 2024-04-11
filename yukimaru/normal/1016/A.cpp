/*************************************************************************
    > File Name: 1016_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 08 Aug 2018 10:00:43 PM CST
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
	long long n, m;
	while(scanf("%lld%lld", &n, &m) != EOF)
	{
		long long a[200005]={0};
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
		long long sum=0, prep=0, nowp=0;
		for(int i=1; i<=n; i++)
		{
			sum+=a[i];
			nowp=sum/m;
			printf("%lld", nowp-prep);
			if(i != n) printf(" ");
			else printf("\n");
			prep=nowp;
		}
	}
	return 0;
}