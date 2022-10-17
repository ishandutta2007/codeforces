/*************************************************************************
    > File Name: 869_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 06 Oct 2017 09:38:55 PM CST
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
		int x[2005], y[2005];
		bool vis[20000005]={0};
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &x[i]);
			vis[x[i]]=1;
		}
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &y[i]);
			vis[y[i]]=1;
		}
		int num=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(vis[x[i]^y[j]]) num++;
		if(num%2 == 0) printf("Karen\n");
		else printf("Koyomi\n");
	}
	return 0;
}