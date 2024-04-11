#include<cstdio>
#include<iostream>
#define xxx 50000
using namespace std;
int n,a[xxx];

int up(int x)
{
	for (int i=1;i<x;i++)
		if (a[i]>=a[i+1])
			return 0;
	return 1;
}

int same(int x,int y)
{
	for (int i=x;i<y;i++)
		if (a[i]!=a[i+1])
			return 0;
	return 1;
}

int dowm(int x)
{
	for (int i=x;i<n;i++)
		if (a[i]<=a[i+1])
			return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (up(i)&&same(i,j)&&dowm(j))
			{
				printf("YES");
				return 0;
			}
	printf("NO");
}