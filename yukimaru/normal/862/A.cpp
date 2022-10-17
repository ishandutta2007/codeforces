/*************************************************************************
    > File Name: 862_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 20 Sep 2017 07:13:09 PM CST
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
	int n, x;
	bool f[105];
	while(scanf("%d%d", &n, &x) != EOF)
	{
		memset(f, 0, sizeof(f));
		int a;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			f[a]=1;
		}
		int num=0;
		for(int i=0; i<x; i++)
			if(f[i] == 0) num++;
		int ans=-1;
		if(num == 0)
		{
			if(f[x] == 0) ans=0;
			if(f[x] == 1) ans=1;
		}
		else
		{
			if(f[x] == 0) ans=num;
			if(f[x] == 1) ans=num+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}