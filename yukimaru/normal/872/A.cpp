/*************************************************************************
    > File Name: 872_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 15 Oct 2017 04:05:43 PM CST
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

int min(int a, int b)
{
	if(a <= b) return a;
	else return b;
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int a[15]={0}, b[15]={0};
		int mina=100, minb=100;
		bool fa[10]={0};
		int ff[15]={0}, num=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			mina=min(mina, a[i]);
			fa[a[i]]=1;
		}
		for(int i=1; i<=m; i++)
		{
			scanf("%d", &b[i]);
			minb=min(minb, b[i]);
			if(fa[b[i]] == 1)
			{
				num++;
				ff[num]=b[i];
			}
		}
		if(num > 0)
		{
			int tmp=100;
			for(int i=1; i<=num; i++)
				tmp=min(tmp, ff[i]);
			if(mina != minb) printf("%d\n", tmp);
			if(mina == minb)
			{
				if(tmp <= mina) printf("%d\n", tmp);
				else printf("%d\n", mina);
			}
		}
		else
		{
		if(mina == minb) printf("%d\n", mina);
		else if(mina < minb) printf("%d%d\n", mina, minb);
		else if(minb < mina) printf("%d%d\n", minb, mina);
		}
	}
	return 0;
}