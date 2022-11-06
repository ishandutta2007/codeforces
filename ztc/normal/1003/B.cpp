#include<stdio.h>
#include<iostream>
#include<deque>
using namespace std;
int n,i,j,a,b,x;
int main()
{
	scanf("%d%d%d",&a,&b,&x);
	if(x&1)
	{
		for(i=1;i<=b-x/2;i++)printf("1");
		for(i=1;i<=x/2;i++)printf("01");
		for(i=1;i<=a-x/2;i++)printf("0");
	}
	else
	{
		if(b>a)
		{
			for(i=1;i<=x/2;i++)printf("10");
			for(i=1;i<=a-x/2;i++)printf("0");
			for(i=1;i<=b-x/2;i++)printf("1");
		}
		else
		{
			for(i=1;i<=x/2;i++)printf("01");
			for(i=1;i<=b-x/2;i++)printf("1");
			for(i=1;i<=a-x/2;i++)printf("0");
		}
	}
	return 0;
}