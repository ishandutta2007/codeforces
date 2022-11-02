#include<iostream>
#include<cstdio>
using namespace std;
int a1,a2,a3,a4,b1,b2,b3,b4;
int main()
{
	cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
	int c1=0,c2=0,c3=0,c4=0;
	if(a1>b4 && b2>a3)
		c1=0;
	else
		if(a1<b4 && b2<a3)
			c1=1;
		else
			c1=2;
	if(a1>b3 && b2>a4)
		c2=0;
	else
		if(a1<b3 && b2<a4)
			c2=1;
		else
			c2=2;
	if(a2>b4 && b1>a3)
		c3=0;
	else
		if(a2<b4 && b1<a3)
			c3=1;
		else
			c3=2;
	if(a2>b3 && b1>a4)
		c4=0;
	else
		if(a2<b3 && b1<a4)
			c4=1;
		else
			c4=2;
	if((c1==1 || c2==1) && (c3==1 || c4==1))
		puts("Team 2");
	else
		if((c1==0 && c2==0) || (c3==0 && c4==0))
			puts("Team 1");
		else
			puts("Draw");
	return 0;
}