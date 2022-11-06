#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
bool a[100002],b;
long long i,p=0,q=0,r=0,s=0,n;
int main()
{
	scanf("%I64d",&n);
	getchar();
	for(i=1;i<=n;i++)a[i]=getchar()-'0';
	getchar();
	for(i=1;i<=n;i++)
	{
		b=getchar()-'0';
		if(b)
		{
			if(a[i])p+=1;
			else q+=1;
		}
		else
		{
			if(a[i])r+=1;
			else s+=1;
		}
	}
	printf("%I64d",p*s+r*s+r*q);
}