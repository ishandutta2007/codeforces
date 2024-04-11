#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n,k,p,i,j;
int main()
{
	scanf("%d",&n);
	k=sqrt(n);
	if(k*k==n)
	{
		for(i=k;i<=n;i+=k)for(j=i;j>i-k;j--)printf("%d ",j);
	}
	else
	{
		k+=1;
		for(i=k;i<=n+k-1;i+=k)for(j=min(n,i);j>=i-k+1;j--)printf("%d ",j);
	}
}