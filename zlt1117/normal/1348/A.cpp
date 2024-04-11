#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?x:-x;
}
int pw2[35],t,n;
int main()
{
	pw2[0]=1;
	for(int i=1;i<=30;++i)pw2[i]=pw2[i-1]*2;
	t=getint();
	while(t--)
	{
		n=getint();
		int sum=pw2[n];
		for(int i=n-1,j=1;j<=n/2;--i,++j)
		{
			sum-=pw2[i];
		}
		for(int i=n/2-1;i>=1;--i)
		{
			sum+=pw2[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}