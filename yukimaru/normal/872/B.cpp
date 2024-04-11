/*************************************************************************
    > File Name: 872_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 15 Oct 2017 04:23:02 PM CST
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

int max(int a, int b)
{
	if(a >= b) return a;
	else return b;
}

int min(int a, int b)
{
	if(a <= b) return a;
	else return b;
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		int a[100005]={0};
		int maxa=-2147483647, mina=2147483647;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			maxa=max(maxa, a[i]);
			mina=min(mina, a[i]);
		}
		if(k >= 3) printf("%d\n", maxa);
		if(k == 1) printf("%d\n", mina);
		if(k == 2)
		{
			int prem[100005]={0}, sufm[100005]={0};
			prem[1]=a[1];
			sufm[n]=a[n];
			for(int i=2; i<=n; i++) prem[i]=min(prem[i-1], a[i]);
			for(int i=n-1; i>=1; i--) sufm[i]=min(sufm[i+1], a[i]);
			int tmp=0, ans=-2147483647;
			for(int i=1; i<n; i++)
			{
				tmp=max(prem[i], sufm[i+1]);
				ans=max(ans, tmp);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}