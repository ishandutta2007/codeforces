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
int a,b,ans;
int calc(int x,int y)
{
	int ret=0;
	for(int i=20;i>=0;i--)
	{
		if(((y>>i)&1)&&((x>>i)&1))ret|=(1<<i);
		else if((!((y>>i)&1))&&((x>>i)&1)){for(int j=i;j>=0;j--)if((x>>j)&1)ret|=(1<<j);return ret;}
		else if(((y>>i)&1)&&(!((x>>i)&1)))ret|=(1<<i);
	}
	return ret;
}
int main()
{
	T=read();
	while(T--)
	{
		a=read();b=read();
		ans=b-a;
		for(int i=a;i<=b;i++)ans=min(ans,i+calc(i,b)-a-b+1);
		printf("%d\n",ans);
	}
	return 0;
}