/*************************************************************************
    > File Name: 868_C_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 05 Oct 2017 07:44:15 PM CST
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
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		int f[100005][5];
		bool vis[20]={0};
		for(int i=1; i<=n; i++)
		{
			int tmp=0;
			for(int j=1; j<=k; j++)
			{
				scanf("%d", &f[i][j]);
				tmp+=f[i][j]*(1<<(k-j));
			}
			vis[tmp]=1;
		}
		bool flag=0;
		for(int i=0; i<16; i++)
		{
			for(int j=i+1; j<16; j++)
				if(vis[i]==1 && vis[j]==1)
				{
					if((i&j) == 0) flag=1;
					if(flag == 1) break;
				}
			if(flag == 1) break;
		}
		if(flag==1 || vis[0]==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}