/*************************************************************************
    > File Name: 1062_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 15 Nov 2018 12:38:41 AM CST
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

typedef long long ll;

int fac[1000005], num[1000005];
bool flag[1000005]={0};

int main()
{
	for(int i=1; i<=1000000; i*=2)
		flag[i]=1;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 1)
		{
			printf("1 0\n");
			continue;
		}
		int cnt=0;
		memset(fac, 0, sizeof(fac));
		memset(num, 0, sizeof(num));
		for(int i=2; i*i<=n; i++)
			if(n%i == 0)
			{
				cnt++;
				fac[cnt]=i;
				while(n%i == 0)
				{
					num[cnt]++;
					n/=i;
				}
			}
		if(n > 1)
		{
			cnt++;
			fac[cnt]=n;
			num[cnt]++;
		}
		int ans1=1, ans2=0;
		int maxi=0, mini=2147483647;
		for(int i=1; i<=cnt; i++)
		{
			ans1*=fac[i];
			maxi=max(maxi, num[i]);
			mini=min(mini, num[i]);
		}
		while(!flag[maxi]) maxi++;
		if(mini < maxi) ans2++;
		while(maxi > 1)
		{
			maxi/=2;
			ans2++;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}