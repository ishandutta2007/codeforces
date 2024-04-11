#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define ll long long
#define db double
using namespace std;

int n,m;

int main()
{
	int i,j;
	cin>>n;
	if(n>36||n<0)
	{
		puts("-1");
		return 0;
	}
	if(!n)
	{
		puts("1");
		return 0;
	}
	for(;n>1;n-=2)
	{
		cout<<8;
	}
	if(n)
		cout<<4;
}