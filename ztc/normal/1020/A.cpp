#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n,h,a,b,k;
int i,j,c,d,e,f;
int main()
{
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d%d",&c,&d,&e,&f);
		if((a<=d&&d<=b)||(a<=f&&f<=b)||c==e||(d<a&&b<f)||(f<a&&b<d))printf("%d\n",abs(e-c)+abs(f-d));
		else 
		{
			if(d<a)printf("%d\n",abs(e-c)+a-d+a-f);
			else printf("%d\n",abs(e-c)+d-b+f-b);
		}
	}
	return 0;
}