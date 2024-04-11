/*************************************************************************
    > File Name: 834_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 30 Jul 2017 11:05:57 PM CST
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
		char s[1000005]={0};
		scanf("%s", s+1);
		int st[256]={0}, ed[256]={0};
		for(int i=1; i<=n; i++)
			if(st[s[i]-0] == 0) st[s[i]-0]=i;
		for(int i=n; i>=1; i--)
			if(ed[s[i]-0] == 0) ed[s[i]-0]=i;
		int num=0;
		bool f[256]={0};
		bool flag=0;
		for(int i=1; i<=n; i++)
		{
			for(int c='A'; c<='Z'; c++)
			{
				if(st[c] == i && f[c] == 0)
				{
					num++;
					f[c]=1;
				}
				if(ed[c] == i-1 && f[c] == 1)
				{
					num--;
					f[c]=0;
				}
			}
			if(num > k)
			{
				flag=1;
				break;
			}
		}
		if(flag == 1) printf("YES\n");
		else if(flag == 0) printf("NO\n");
	}
	return 0;
}