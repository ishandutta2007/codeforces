/*************************************************************************
    > File Name: 1036_D.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 12 Sep 2018 05:15:06 PM CST
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
		int m;
		long long a[300005]={0}, b[300005]={0};
		for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
		scanf("%d", &m);
		for(int i=1; i<=m; i++) scanf("%lld", &b[i]);
		int pa=1, pb=1;
		long long tmpa=a[pa], tmpb=b[pb];
		bool flag=1;
		int len=n;
		while(true)
		{
			if(pa>n || pb>m)
			{
				if(tmpa != tmpb) flag=0;
				break;
			}
			if(tmpa == tmpb)
			{
				pa++;
				pb++;
				tmpa=a[pa];
				tmpb=b[pb];
			}
			else if(tmpa < tmpb)
			{
				pa++;
				len--;
				tmpa+=a[pa];
			}
			else
			{
				pb++;
				tmpb+=b[pb];
			}
		}
		if(!flag) printf("-1\n");
		else printf("%d\n", len);
	}
	return 0;
}