/*************************************************************************
    > File Name: 1062_D.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 15 Nov 2018 02:22:48 PM CST
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
		int sum[100005]={0};
		for(int i=2; i<=n; i++)
			for(int j=i*2; j<=n; j+=i)
				sum[j]+=j/i;
		long long ans=0;
		for(int i=1; i<=n; i++)
			ans+=(long long)sum[i];
		ans*=(long long)4;
		printf("%lld\n", ans);
	}
	return 0;
}