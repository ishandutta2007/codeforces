#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
struct node 
{
	int id,num;
	bool operator<(const node &u)const
	{
		if(u.num==num)return id<u.id;
		else return u.num<num;
	}
}a[1002];
int b,c,d,e,n,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&b,&c,&d,&e);
		a[i].id=i;
		a[i].num=b+c+d+e;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(a[i].id==1)
		{
			printf("%d",i);
			return 0;
		}
	}
}