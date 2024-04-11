/*************************************************************************
    > File Name: 849_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 01 Sep 2017 10:48:12 PM CST
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
	int a[500]={0}, end=0;
	for(int i=2; i<500; i++)
	{
		a[i]=a[i-1]+i-1;
		if(a[i] > 100000)
		{
			end=i-1;
			break;
		}
	}
	int k;
	while(scanf("%d", &k) != EOF)
	{
		if(k == 0)
		{
			printf("a\n");
			continue;
		}
		char x='a';
		for(int i=end; i>=2; i--)
			while(a[i]<=k)
			{
				for(int j=1; j<=i; j++) printf("%c", x);
				x++;
				k=k-a[i];
			}
		printf("\n");
	}
	return 0;
}