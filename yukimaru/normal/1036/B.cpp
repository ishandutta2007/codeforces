/*************************************************************************
    > File Name: 1036_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 10 Sep 2018 05:37:33 PM CST
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

void swap(long long &a, long long &b)
{
	long long t=a;
	a=b;
	b=t;
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		long long n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		if(n < m) swap(n, m);
		if(n > k) printf("-1\n");
		else
		{
			long long ans=n, tmp=n-m;
			k-=n;
			if(tmp%2 != 0)
			{
				k--;
				ans+=k;
			}
			else
			{
				if(k%2 == 0) ans+=k;
				else ans=ans+k-2;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}