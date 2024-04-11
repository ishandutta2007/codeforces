/*************************************************************************
    > File Name: 849_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Fri 01 Sep 2017 10:12:30 PM CST
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

const double eps=1e-8;
int n, a[1005];
int num1, num2, prex1, prex2, prey1, prey2;
double k1, k2;
bool flag;

void dfs(int k)
{
	if(flag == 1) return;
	if(num1>1 && num2>1 && fabs(k1-k2)>eps) return;
	if(num1>1 && num2>0 && fabs((double)(prey1-prey2)/(double)(prex1-prex2)-k1)<=eps) return;
	if(num1>0 && num2>1 && fabs((double)(prey1-prey2)/(double)(prex1-prex2)-k2)<=eps) return;
	if(k > n)
	{
		if(num1>0 && num2>0) flag=1;
		else flag=0;
		return;
	}
	if(num1 <= 1)
	{
		if(num1 == 0)
		{
			prex1=k;
			prey1=a[k];
		}
		num1++;
		if(num1 == 2)
			k1=(double)(a[k]-prey1)/(double)(k-prex1);
		dfs(k+1);
		num1--;
	}
	if(num1>1 && fabs((double)(a[k]-prey1)/(double)(k-prex1)-k1)<=eps)
	{
		num1++;
		dfs(k+1);
		num1--;
	}
	if(num2 <= 1)
	{
		if(num2 == 0)
		{
			prex2=k;
			prey2=a[k];
		}
		num2++;
		if(num2 == 2)
			k2=(double)(a[k]-prey2)/(double)(k-prex2);
		dfs(k+1);
		num2--;
	}
	if(num2>1 && fabs((double)(a[k]-prey2)/(double)(k-prex2)-k2)<=eps)
	{
		num2++;
		dfs(k+1);
		num2--;
	}
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		flag=0;
		num1=0; num2=0;
		dfs(1);
		if(flag == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}