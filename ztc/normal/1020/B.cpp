#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n;
bool b[1002][1002];
int a[1002],i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		j=i;
		while(!b[j][i])
		{
			b[j][i]=1;
			j=a[j];
		}
		printf("%d ",j);
	}
	return 0;
}