/*************************************************************************
    > File Name: 839_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sat 12 Aug 2017 11:31:42 PM CST
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

int n, num[100005];
vector<int> edge[100005];
double ans;

void add(int u, int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
	num[u]++;
	num[v]++;
}

void dfs(int k, int l, int pre, double x)
{
	if(num[k] == 1)
	{
		ans+=l*x;
		return;
	}
	for(vector<int>::iterator it=edge[k].begin(); it != edge[k].end(); it++)
	{
		if(*it == pre) continue;
		dfs(*it, l+1, k, (x/(double)(num[k]-1)));
	}
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		ans=0;
		memset(num, 0, sizeof(num));
		memset(edge, 0, sizeof(edge));
		int u, v;
		for(int i=1; i<=n-1; i++)
		{
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		num[1]++;
		dfs(1, 0, 0, 1);
		printf("%.15f\n", ans);
	}
	return 0;
}