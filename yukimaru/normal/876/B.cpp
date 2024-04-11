/*************************************************************************
    > File Name: 876_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 16 Oct 2017 11:45:26 PM CST
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
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m) != EOF)
	{
		int a[100005]={0};
		int num[100005]={0};
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			num[a[i]%m]++;
		}
		int max=0, ai=0;
		for(int i=0; i<100005; i++)
			if(num[i] > max)
			{
				max=num[i];
				ai=i;
			}
		if(max < k)
			printf("No\n");
		else
		{
			printf("Yes\n");
			int tmp=0;
			for(int i=1; i<=n; i++)
			{
				if(a[i]%m == ai)
				{
					tmp++;
					if(tmp == k) printf("%d\n", a[i]);
					else printf("%d ", a[i]);
				}
				if(tmp == k) break;
			}
		}
	}
	return 0;
}