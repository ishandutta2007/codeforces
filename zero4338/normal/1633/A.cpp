#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int n;
int calc(int x,int y)
{
	int ret=0;
	while(x)
	{
		if(x%10!=y%10)ret++;
		x/=10;y/=10;
	}
	return ret;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int mi=0;
		if(n<100)
		{
			mi=77;
			for(int i=10;i<100;i++)
				if(i%7==0&&calc(n,i)<calc(mi,n))mi=i;
		}
		else
		{
			mi=777;
			for(int i=100;i<1000;i++)
				if(i%7==0&&calc(n,i)<calc(mi,n))mi=i;
		}
		printf("%d\n",mi);
	}
	return 0;
}