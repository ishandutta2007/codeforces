/*********************************************************************
    > File Name: 1082_C.cpp
    > Author: yuki
 *********************************************************************/

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

struct Per
{
	int s, r;
};

bool cmp(Per a, Per b)
{
	return a.s<b.s || (a.s==b.s && a.r>b.r);
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		Per a[100005];
		for(int i=1; i<=n; i++)
			scanf("%d%d", &a[i].s, &a[i].r);
		sort(a+1, a+1+n, cmp);
//		for(int i=1; i<=n; i++)
//			printf("! %d %d\n", a[i].s, a[i].r);
		int tmp=0, x=0;
		int sum[100005]={0};
		for(int i=1; i<=n; i++)
		{
			if(i!=1 && a[i].s!=a[i-1].s)
			{
				tmp=0;
				x=0;
			}
			x++;
			tmp+=a[i].r;
			if(tmp >= 0) sum[x]+=tmp;
		}
		int ans=0;
		for(int i=1; i<=n; i++)
			ans=max(ans, sum[i]);
		printf("%d\n", ans);
	}
	return 0;
}