/*************************************************************************
    > File Name: 835_C_2.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Mon 31 Jul 2017 11:25:42 PM CST
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

int swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
	return 0;
}

int dqsort(int *a, int *b, int l, int r, int *c)
{
	int i=l, j=r, x=a[(l+r)>>1], y=b[(l+r)>>1];
	do{
		while((a[i]<x) || (a[i]==x && b[i]<y)) i++;
		while((a[j]>x) || (a[j]==x && b[j]>y)) j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			swap(c[i], c[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l < j) dqsort(a, b, l, j, c);
	if(i < r) dqsort(a, b, i, r, c);
	return 0;
}

int main()
{
	int n, q, c;
	while(scanf("%d%d%d", &n, &q, &c) != EOF)
	{
		int x[100005]={0}, y[100005]={0}, s[100005]={0};
		for(int i=1; i<=n; i++) scanf("%d%d%d", &x[i], &y[i], &s[i]);
		dqsort(x, y, 1, n, s);
		int pos[105][105];
		memset(pos, 0, sizeof(pos));
		for(int i=1; i<=n; i++)
			if(pos[x[i]][y[i]] == 0) pos[x[i]][y[i]]=i;
		int pre[15][105][105];
		memset(pre, 0, sizeof(pre));
		for(int tt=0; tt<=11; tt++)
		{
			for(int i=1; i<=100; i++)
				for(int j=1; j<=100; j++)
				{
					pre[tt][i][j]=pre[tt][i][j-1]+pre[tt][i-1][j]-pre[tt][i-1][j-1];
					for(int k=pos[i][j]; x[k]==i&&y[k]==j&&k<=n; k++)
						pre[tt][i][j]+=(s[k]+tt)%(c+1);
				}
		}
		while(q--)
		{
			int ti, x1i, y1i, x2i, y2i;
			scanf("%d%d%d%d%d", &ti, &x1i, &y1i, &x2i, &y2i);
			int tk=ti%(c+1);
			int ans=0;
/*			for(int i=1; i<=x2i; i++)
			{
				for(int j=1; j<=y2i; j++)
					printf("%d ", pre[tk][i][j]);
				printf("\n");
			} */
			ans=pre[tk][x2i][y2i]-pre[tk][x1i-1][y2i]-pre[tk][x2i][y1i-1]+pre[tk][x1i-1][y1i-1];
			printf("%d\n", ans);
		}
	}
	return 0;
}