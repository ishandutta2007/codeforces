/*************************************************************************
    > File Name: 870_D.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 16 Oct 2017 07:48:33 PM CST
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
		int p0xb[5005]={0}, b0xp[5005]={0};
		for(int i=0; i<n; i++)
		{
			printf("? 0 %d\n", i);
			fflush(stdout);
			scanf("%d", &p0xb[i]);
		}
		for(int i=0; i<n; i++)
		{
			printf("? %d 0\n", i);
			fflush(stdout);
			scanf("%d", &b0xp[i]);
		}
		int cnt=0;
		int p[5005]={0}, b[5005]={0};
		bool flag=1;
		int ans[5005]={0};
		for(int i=0; i<n; i++)
		{
			p[0]=i;
			for(int j=0; j<n; j++)
				b[j]=p[0]^p0xb[j];
			for(int j=0; j<n; j++)
				p[b[j]]=j;
			flag=1;
			for(int j=0; j<n; j++)
				if((b[0]^p[j]) != b0xp[j])
				{
					flag=0;
					break;
				}
			if(flag == 1)
			{
				cnt++;
				if(cnt == 1)
				{
					for(int j=0; j<n; j++)
						ans[j]=p[j];
				}
			}
		}
		printf("!\n");
		printf("%d\n", cnt);
		for(int i=0; i<n-1; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n-1]);
		fflush(stdout);
	}
	return 0;
}