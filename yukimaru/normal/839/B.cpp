/*************************************************************************
    > File Name: 839_B_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 13 Aug 2017 09:38:25 PM CST
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
		int num[10005]={0};
		int a;
		for(int i=1; i<=k; i++)
		{
			scanf("%d", &a);
			num[a]++;
		}
		int c[10]={0};
		c[4]=n; c[2]=2*n;
		bool flag=1;
		for(int i=10000; i>=1; i--)
		{
			while(num[i]--)
			{
				for(int j=4; j>=0; j--)
				{
					if(c[j] > 0)
					{
						c[j]--;
						int x=min(i, j);
						num[i-x]++;
						if(j-x-1 > 0) c[j-x-1]++;
						break;
					}
					if(j == 0)
					{
						flag=0;
						break;
					}
				}
				if(flag == 0) break;
			}
			if(flag == 0) break;
		}
		if(flag == 1) printf("YES\n");
		if(flag == 0) printf("NO\n");
	}
	return 0;
}