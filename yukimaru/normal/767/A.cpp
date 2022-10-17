/*************************************************************************
    > File Name: 767_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sat 18 Feb 2017 05:05:25 PM CST
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
		int a[100005]={0};
		bool flag[100005]={0};
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		int maxn=n;
		for(int i=1; i<=n; i++)
		{
			flag[a[i]]=1;
			if(a[i] < maxn) printf("\n");
			else
			{
				int num=0;
				for(int j=a[i]; j>=1; j--)
				{
					if(flag[j] == 1)
					{
						if(num != 0) printf(" ");
						printf("%d", j);
						num++;
					}
					else if(flag[j] == 0) break;
				}
				printf("\n");
				maxn=maxn-num;
			}
		}
	}
	return 0;
}