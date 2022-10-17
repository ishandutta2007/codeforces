/*************************************************************************
    > File Name: 854_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 06 Sep 2017 09:41:41 PM CST
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

set<long long> s;

void swap(long long &a, long long &b)
{
	int t=a;
	a=b;
	b=t;
}

int qsort(int l, int r, long long *a, long long *b)
{
	int i=l, j=r, x=a[(l+r)>>1];
	do{
		while(a[i]>x) i++;
		while(a[j]<x) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) qsort(l, j, a, b);
	if(i<r) qsort(i, r, a, b);
	return 0;
}

int qqsort(int l, int r, long long *a, long long *b, long long *c)
{
	int i=l, j=r, x=b[(l+r)>>1];
	do{
		while(b[i]<x) i++;
		while(b[j]>x) j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			swap(c[i], c[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) qqsort(l, j, a, b, c);
	if(i<r) qqsort(i, r, a, b, c);
	return 0;
}

int main()
{
	int n, k;
	long long c[300005]={0}, id[300005]={0}, fin[300005]={0};
	while(scanf("%d%d", &n, &k) != EOF)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", &c[i]);
			id[i]=(long long)i;
		}
		qsort(1, n, c, id);
		for(long long i=k+1; i<=k+n; i++) s.insert(i);
		long long ans=0;
		for(int i=1; i<=n; i++)
		{
			set<long long>::iterator j=s.lower_bound(id[i]);
			ans+=(*j-id[i])*c[i];
			fin[i]=*j;
			s.erase(j);
		}
		printf("%lld\n", ans);
		qqsort(1, n, c, id, fin);
		for(int i=1; i<n; i++)
			printf("%lld ", fin[i]);
		printf("%lld\n", fin[n]);
	}
	return 0;
}