/*************************************************************************
    > File Name: 872_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 15 Oct 2017 04:37:23 PM CST
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
	int q;
	while(scanf("%d", &q) != EOF)
	{
		while(q--)
		{
			int n;
			scanf("%d", &n);
			if(n < 4) printf("-1\n");
			else
			{
				int tmp=n/4;
				if(n%2 != 0) tmp=tmp-1;
				if(n == 11) tmp=0;
				if(tmp < 1) printf("-1\n");
				else printf("%d\n", tmp);
			}
		}
	}
	return 0;
}