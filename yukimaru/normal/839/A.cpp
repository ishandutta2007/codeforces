/*************************************************************************
    > File Name: 839_A.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sat 12 Aug 2017 10:37:31 PM CST
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
	int a[105];
	int num, ans, tmp, sum;
	bool flag;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		num=0;
		ans=0;
		tmp=0;
		flag=0;
		sum=0;
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int i=1; i<=n; i++)
		{
			sum+=a[i];
			tmp=sum;
			if(sum > 8) tmp=8;
			sum=sum-tmp;
			num=num+tmp;
			if(num >= k)
			{
				flag=1;
				ans=i;
				break;
			}
		}
		if(flag == 1) printf("%d\n", ans);
		if(flag == 0) printf("-1\n");
	}
	return 0;
}