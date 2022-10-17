/*************************************************************************
    > File Name: 834_C_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 31 Jul 2017 11:45:36 AM CST
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
		while(n--)
		{
			long long a, b;
			scanf("%lld%lld", &a, &b);
			long long tmp=a*b;
			long long c=cbrt((long double)tmp);
			if(c*c*c==tmp && a%c==0 && b%c==0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}