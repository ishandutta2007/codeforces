/*************************************************************************
    > File Name: 1062_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 14 Nov 2018 11:35:16 PM CST
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

struct node
{
	int l, r;
};

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a[105]={0};
		node tmp[105];
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		int cnt=0, tmpl=1, tmpr=1;
		for(int i=2; i<=n; i++)
		{
			if(a[i] == a[i-1]+1) tmpr++;
			else
			{
				cnt++;
				tmp[cnt].l=tmpl;
				tmp[cnt].r=tmpr;
				tmpl=i;
				tmpr=i;
			}
		}
		cnt++;
		tmp[cnt].l=tmpl;
		tmp[cnt].r=tmpr;
		int ans=0, tmpans=0;
		for(int i=1; i<=cnt; i++)
		{
			tmpans=tmp[i].r-tmp[i].l+1;
			tmpans-=2;
			if(a[tmp[i].l]==1 || a[tmp[i].r]==1000)
				tmpans++;
			ans=max(ans, tmpans);
		}
		if(ans < 1) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}